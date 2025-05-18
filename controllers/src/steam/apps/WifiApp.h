//	Steampunk Thingies
//	Copyright (c) 2022-2025 Johan A. Goossens. All rights reserved.
//
//	This work is licensed under the terms of the MIT license.
//	For a copy, see <https://opensource.org/licenses/MIT>.


#pragma once


//
//	Include files
//

#include "BaseApp.h"


//
//	WifiApp
//

class WifiApp : public BaseApp {
public:
	// constructor
	WifiApp(AppContext& context) {}

	// called once a loop (when app is active)
	void loop(AppContext& context) override {
		context.framebuffer->fillScreen(TFT_BLACK);
		context.framebuffer->setTextDatum(MC_DATUM);
	 	context.framebuffer->setTextColor(TFT_WHITE, TFT_BLACK);
		context.framebuffer->drawString("WIFI", 120, 60, 4);

		char buffer[32];
		snprintf(buffer, sizeof(buffer), "SSID: %s\n", context.wifi->getSSID().c_str());
		context.framebuffer->drawString(buffer, 120, 100, 2);

		snprintf(buffer, sizeof(buffer), "IP: %s\n", context.wifi->getIP().c_str());
		context.framebuffer->drawString(buffer, 120, 130, 2);

		snprintf(buffer, sizeof(buffer), "MAC: %s\n", context.wifi->getMacAddress().c_str());
		context.framebuffer->drawString(buffer, 120, 150, 2);

		snprintf(buffer, sizeof(buffer), "RSSI: %d dB\n", context.wifi->getRSSI());
		context.framebuffer->drawString(buffer, 120, 180, 2);
	}

private:
};
