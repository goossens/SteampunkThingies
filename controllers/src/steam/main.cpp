//	Steampunk Thingies
//	Copyright (c) 2022-2025 Johan A. Goossens. All rights reserved.
//
//	This work is licensed under the terms of the MIT license.
//	For a copy, see <https://opensource.org/licenses/MIT>.


//
//	Include files
//

#include <Arduino.h>
#include <SD.h>

#include <TFT_eSPI.h>
#include <AiEsp32RotaryEncoder.h>

#include "JgsLog.h"
#include "JgsSprite.h"
#include "JgsTimeZone.h"
#include "JgsWifi.h"

#include "apps/AppContext.h"
#include "apps/AppSwitcher.h"


//
//	Constants
//

// SD card pins
static constexpr int SD_SCK = 42;
static constexpr int SD_MISO = 41;
static constexpr int SD_MOSI = 2;
static constexpr int SD_CS = 1;

// pwm pin for brightness control
static constexpr int pwmFreq = 5000;
static constexpr int pwmResolution = 8;
static constexpr int pwmLedChannelTFT = 0;

// rotary encoder pins
static constexpr int encoderA = 10;
static constexpr int encoderB = 9;
static constexpr int encoderButton = 6;


//
//	Globals
//

// screen subsystem
static int brightness = 64;
static TFT_eSPI tft = TFT_eSPI();
static TFT_eSprite framebuffer = TFT_eSprite(&tft);
static TFT_eSprite logoSprite = TFT_eSprite(&tft);

// SD card subsystem
static SPIClass sdSPI;

// network subsystem
static JgsWifi wifi;
static JgsTimeZone timezone;

// UI subsystem
AiEsp32RotaryEncoder encoder = AiEsp32RotaryEncoder(encoderA, encoderB, encoderButton, -1, 2);


//
//	Apps
//

AppContext context(tft, framebuffer, encoder, wifi, timezone);
AppSwitcher switcher(context);


//
//	showSplashScreen
//

void showSplashScreen() {
	tft.fillScreen(TFT_BLACK);
	logoSprite.pushSprite(70, 15);
	tft.setTextDatum(MC_DATUM);
	tft.drawString("Version: 1.0", 120, 180, 2);
	tft.drawString("June 3rd, 2024", 120, 200, 2);
}


//
//	setSplashScreenAction
//

void setSplashScreenAction(const char* msg1, const char* msg2) {
	tft.setTextDatum(MC_DATUM);
	tft.drawString("                      ", 120, 130, 2);
	tft.drawString("                      ", 120, 150, 2);
	tft.drawString(msg1, 120, 130, 2);
	tft.drawString(msg2, 120, 150, 2);
	delay(1500);
}


//
//	handlePossibleResetRequest
//

void handlePossibleResetRequest() {
	tft.fillScreen(TFT_BLACK);
	tft.setTextDatum(MC_DATUM);
	tft.drawString("DO YOU WANT A RESET?", 120, 60, 2);
	tft.drawString("If so, release button", 120, 90, 2);
	tft.drawString("and press and hold button", 120, 110, 2);
	tft.drawString("again for 2 seconds", 120, 130, 2);

	int counter = 29;
	char buffer[3];

	while (counter >= 0 && encoder.isEncoderButtonDown()) {
		snprintf(buffer, sizeof(buffer), "%d", counter);
		tft.drawString(buffer, 120, 180, 6);
		delay(1000);
		counter--;
	}

	while (counter >= 0) {
		if (encoder.isEncoderButtonDown()) {
			while (encoder.isEncoderButtonDown()) {
				delay(1000);
			}

			wifi.reset();
			tft.fillScreen(TFT_BLACK);
			ESP.restart();
		}

		snprintf(buffer, sizeof(buffer), "%d", counter);
		tft.drawString(buffer, 120, 180, 6);
		delay(1000);
		counter--;
	}
}


//
//	encoderISR (encoder change interupt)
//

void IRAM_ATTR encoderISR() {
	encoder.readEncoder_ISR();
}


//
//	setup
//

void setup() {
	// setup logging
	JgsLog::init();

	// initialize encoder
	encoder.begin();
	encoder.setup(encoderISR);
	encoder.disableAcceleration();

	// initialize display
	tft.init();
	tft.fillScreen(TFT_BLACK);
	framebuffer.createSprite(tft.width(), tft.height());

	// initialize backlighting
	ledcSetup(pwmLedChannelTFT, pwmFreq, pwmResolution);
	ledcAttachPin(TFT_BL, pwmLedChannelTFT);
	ledcWrite(pwmLedChannelTFT, brightness);

	// see if reset is being requested
	if (encoder.isEncoderButtonDown()) {
		handlePossibleResetRequest();
	}

	// initialize SD card
	sdSPI.begin(SD_SCK, SD_MISO, SD_MOSI);

	if (!SD.begin(SD_CS, sdSPI)) {
		JgsLog::print("ERROR: File System Mount Failed!\n");
		delay(3000);
		ESP.restart();
	}

	// show splash screen
	JgsSprite::fromJpegSdFile(&logoSprite, "/logo.jpeg");
	showSplashScreen();

	// initialize subsystems
	wifi.init([](const char* msg1, const char* msg2) {
		setSplashScreenAction(msg1, msg2);
	});

	timezone.init(wifi.isConfigChanged(), [](const char* msg1, const char* msg2) {
		setSplashScreenAction(msg1, msg2);
	});

	// output CPU and memory statistics
	JgsLog::cpuMemStats();
}


//
//	loop
//

void loop() {
	// ensure we still have a good wifi connection
	if (!wifi.isConnected()) {
		wifi.reconnect([](const char* msg1, const char* msg2) {
			setSplashScreenAction(msg1, msg2);
		});
	}

	// process time related events
	timezone.processEvents();

	// let app switcher run one loop in the current app
	switcher.loop(context);
}
