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
//	TimeZoneApp
//

class TimeZoneApp : public BaseApp {
public:
	// constructor
	TimeZoneApp(AppContext& context) {}

	// called once a loop (when app is active)
	void loop(AppContext& context) override {
		context.framebuffer->fillScreen(TFT_BLACK);
		context.framebuffer->setTextDatum(MC_DATUM);
	 	context.framebuffer->setTextColor(TFT_WHITE, TFT_BLACK);
		context.framebuffer->drawString("TIME", 120, 60, 4);

		context.framebuffer->drawString(context.timezone->getDateTime(), 120, 120, 2);
		context.framebuffer->drawString(context.timezone->getAddress(), 120, 160, 2);
		context.framebuffer->drawString(context.timezone->getCountry(), 120, 180, 2);
	}

private:
};
