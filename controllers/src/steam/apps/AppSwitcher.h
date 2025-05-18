//	Steampunk Thingies
//	Copyright (c) 2022-2025 Johan A. Goossens. All rights reserved.
//
//	This work is licensed under the terms of the MIT license.
//	For a copy, see <https://opensource.org/licenses/MIT>.


//
//	Include files
//

#include <vector>

#include "AppContext.h"

#include "ClockApp.h"
#include "CompassApp.h"
#include "PotentialApp.h"
#include "SteamApp.h"
#include "TimeZoneApp.h"
#include "WifiApp.h"


//
//	AppSwitcher
//

class AppSwitcher {
public:
	// constructor
	AppSwitcher(AppContext& context) :
			clockApp{context},
			compassApp{context},
			potentialApp{context},
			steamApp{context},
			timezoneApp{context},
			wifiApp{context} {

		apps.emplace_back("Steam", &steamApp);
		apps.emplace_back("Potential", &potentialApp);
		apps.emplace_back("Clock", &clockApp);
		apps.emplace_back("Compass", &compassApp);
		apps.emplace_back("Wifi", &wifiApp);
		apps.emplace_back("Timezone", &timezoneApp);
	}

	// run one loop
	void loop(AppContext& context) {
		// handle encoder button state
		if (context.encoder->isEncoderButtonDown()) {
			// start timer (if required)
			if (!wasButtonDown) {
				lastTimeButtonDown = millis();
			}

    		wasButtonDown = true;

		} else if (wasButtonDown) {
			// see if this was a short or long click
			if (switching || millis() - lastTimeButtonDown > 500) {
				// toggle app switching mode on long clicks
				switching = !switching;

			} else {
				// send short click to current app
				apps[currentApp].app->onClick(context);
			}

			wasButtonDown = false;
		}

		// handle encoder rotation
		int rotation = context.encoder->encoderChanged();

		if (rotation) {
			// change app (if required)
			if (switching) {
				currentApp = (apps.size() + currentApp + rotation) % apps.size();

			} else {
				// let current app handle rotation
				apps[currentApp].app->onRotate(context, rotation);
			}
		}

		// show app name if we are in app switching mode
		if (switching) {
			context.framebuffer->fillScreen(TFT_BLACK);
			context.framebuffer->setTextColor(TFT_ORANGE, TFT_BLACK);
			context.framebuffer->setTextDatum(MC_DATUM);
			context.framebuffer->drawString(apps[currentApp].name, 120, 120, 4);

		} else {
			// run a loop in the current app
			apps[currentApp].app->run(context);
		}

		// update display
		context.framebuffer->pushSprite(0, 0);
	}

private:
	// app list
	ClockApp clockApp;
	CompassApp compassApp;
	PotentialApp potentialApp;
	SteamApp steamApp;
	TimeZoneApp timezoneApp;
	WifiApp wifiApp;

	struct App {
		App(const char* n, BaseApp* a) : name(n), app(a) {}
		const char* name;
		BaseApp* app;
	};

	std::vector<App> apps;
	int currentApp = 0;

	// tracking the encoder
	bool wasButtonDown = false;
	unsigned long lastTimeButtonDown = 0;

	// app switching mode
	bool switching = false;
};
