//	Steampunk Thingies
//	Copyright (c) 2022-2024 Johan A. Goossens. All rights reserved.
//
//	This work is licensed under the terms of the MIT license.
//	For a copy, see <https://opensource.org/licenses/MIT>.


//
//	Include files
//

#include <Arduino.h>

#include <OneButton.h>
#include <TFT_eSPI.h>

#include "JgsLog.h"
#include "JgsSprite.h"
#include "JgsTimeZone.h"
#include "JgsWifi.h"

#include "logo.h"
#include "nixie.h"


//
//	Constants
//

// buttons and pwm pin for brightness control
static constexpr int downButtonPin = 0;
static constexpr int upButtonPin = 14;

static constexpr int pwmFreq = 5000;
static constexpr int pwmResolution = 8;
static constexpr int pwmLedChannelTFT = 0;


//
//	Globals
//

static JgsWifi wifi;
static JgsTimeZone timezone;

static int brightness = 127;
static OneButton downButton(downButtonPin, true);
static OneButton upButton(upButtonPin, true);

static TFT_eSPI tft = TFT_eSPI();
static TFT_eSprite logoSprite = TFT_eSprite(&tft);
static TFT_eSprite nixie0Sprite = TFT_eSprite(&tft);
static TFT_eSprite nixie1Sprite = TFT_eSprite(&tft);
static TFT_eSprite nixie2Sprite = TFT_eSprite(&tft);
static TFT_eSprite nixie3Sprite = TFT_eSprite(&tft);
static TFT_eSprite nixie4Sprite = TFT_eSprite(&tft);
static TFT_eSprite nixie5Sprite = TFT_eSprite(&tft);
static TFT_eSprite nixie6Sprite = TFT_eSprite(&tft);
static TFT_eSprite nixie7Sprite = TFT_eSprite(&tft);
static TFT_eSprite nixie8Sprite = TFT_eSprite(&tft);
static TFT_eSprite nixie9Sprite = TFT_eSprite(&tft);
static TFT_eSprite blankSprite = TFT_eSprite(&tft);
static TFT_eSprite dotsSprite = TFT_eSprite(&tft);

static int seconds = -1;
static int minutes = -1;


//
//	showSplashScreen
//

void showSplashScreen() {
	tft.fillScreen(TFT_BLACK);
	logoSprite.pushSprite(0, 0);
	tft.setTextDatum(MC_DATUM);
	tft.drawString("Nixie Clock", 245, 30, 2);
	tft.drawString("Version: 1.0", 245, 55, 2);
	tft.drawString("Jan 3rd, 2024", 245, 80, 2);
}


//
//	setSplashScreenAction
//

void setSplashScreenAction(const char* msg1, const char* msg2) {
	tft.setTextDatum(MC_DATUM);
	tft.drawString("                      ", 245, 120, 2);
	tft.drawString("                      ", 245, 145, 2);
	tft.drawString(msg1, 245, 120, 2);
	tft.drawString(msg2, 245, 145, 2);
	delay(1500);
}


//
//	setup
//

void setup() {
	// setup logging
	JgsLog::init();

	// initialize the display
	tft.init();
	tft.setRotation(1);

	// initialize backlighting
	ledcSetup(pwmLedChannelTFT, pwmFreq, pwmResolution);
	ledcAttachPin(TFT_BL, pwmLedChannelTFT);
	ledcWrite(pwmLedChannelTFT, brightness);

	// setup buttons
	downButton.attachClick([]() {
		brightness = max(15, brightness - 32);
		ledcWrite(pwmLedChannelTFT, brightness);
	});

	upButton.attachClick([]() {
		brightness = min(255, brightness + 32);
		ledcWrite(pwmLedChannelTFT, brightness);
	});

	// show the splash screen
	JgsSprite::fromJpegMemory(&logoSprite, logo, logoLength);
	showSplashScreen();
	setSplashScreenAction("Graphics", "Initializing...");

	// create the tube sprites
	JgsSprite::fromJpegMemory(&nixie0Sprite, nixie0, nixie0Length);
	JgsSprite::fromJpegMemory(&nixie1Sprite, nixie1, nixie1Length);
	JgsSprite::fromJpegMemory(&nixie2Sprite, nixie2, nixie2Length);
	JgsSprite::fromJpegMemory(&nixie3Sprite, nixie3, nixie3Length);
	JgsSprite::fromJpegMemory(&nixie4Sprite, nixie4, nixie4Length);
	JgsSprite::fromJpegMemory(&nixie5Sprite, nixie5, nixie5Length);
	JgsSprite::fromJpegMemory(&nixie6Sprite, nixie6, nixie6Length);
	JgsSprite::fromJpegMemory(&nixie7Sprite, nixie7, nixie7Length);
	JgsSprite::fromJpegMemory(&nixie8Sprite, nixie8, nixie8Length);
	JgsSprite::fromJpegMemory(&nixie9Sprite, nixie9, nixie9Length);
	JgsSprite::fromJpegMemory(&blankSprite, blank, blankLength);
	JgsSprite::fromJpegMemory(&dotsSprite, dots, dotsLength);

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
		showSplashScreen();
		wifi.reconnect(setSplashScreenAction);
	}

	// process time related events
	timezone.processEvents();

	// handle buttons
	downButton.tick();
	upButton.tick();

	// update clock display (if required)
	if (seconds != timezone.getSeconds()) {
		seconds = timezone.getSeconds();

		// have the minutes changed
		if (minutes != timezone.getMinutes()) {
			minutes = timezone.getMinutes();
			auto hours = timezone.getHours();

			// function to render a single nixie tube
			auto displayTube = [&] (int number, int x, int y) {
				switch (number) {
					case 0: nixie0Sprite.pushSprite(x, y); break;
					case 1: nixie1Sprite.pushSprite(x, y); break;
					case 2: nixie2Sprite.pushSprite(x, y); break;
					case 3: nixie3Sprite.pushSprite(x, y); break;
					case 4: nixie4Sprite.pushSprite(x, y); break;
					case 5: nixie5Sprite.pushSprite(x, y); break;
					case 6: nixie6Sprite.pushSprite(x, y); break;
					case 7: nixie7Sprite.pushSprite(x, y); break;
					case 8: nixie8Sprite.pushSprite(x, y); break;
					case 9: nixie9Sprite.pushSprite(x, y); break;
					default: break;
				}
			};

			// render hours
			displayTube(int(hours / 10), 0, 0);
			displayTube(int(hours % 10), 75, 0);

			// render blank
			blankSprite.pushSprite(150, 0);

			// render minutes
			displayTube(int(minutes / 10), 170, 0);
			displayTube(int(minutes % 10), 245, 0);

		} else {
			// render blinking dots
			if (seconds % 2) {
				dotsSprite.pushSprite(150, 0);

			} else {
				blankSprite.pushSprite(150, 0);
			}
		}

	} else {
		delay(100);
	}
}
