//	Steampunk Thingies
//	Copyright (c) 2022-2025 Johan A. Goossens. All rights reserved.
//
//	This work is licensed under the terms of the MIT license.
//	For a copy, see <https://opensource.org/licenses/MIT>.


#pragma once


//
//	Include files
//

#include <TFT_eSPI.h>
#include <AiEsp32RotaryEncoder.h>

#include "JgsTimeZone.h"
#include "JgsWifi.h"


//
//	AppContext
//

class AppContext {
public:
	// constructor
	AppContext(TFT_eSPI& t, TFT_eSprite& fb, AiEsp32RotaryEncoder& e, JgsWifi& w, JgsTimeZone& tz) :
		tft(&t),
		framebuffer(&fb),
		encoder(&e),
		wifi(&w),
		timezone(&tz) {}

	// properties
	TFT_eSPI* tft;
	TFT_eSprite* framebuffer;
	AiEsp32RotaryEncoder* encoder;
	JgsWifi* wifi;
	JgsTimeZone* timezone;
};
