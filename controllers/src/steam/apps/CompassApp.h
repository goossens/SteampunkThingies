//	Steampunk Thingies
//	Copyright (c) 2022-2025 Johan A. Goossens. All rights reserved.
//
//	This work is licensed under the terms of the MIT license.
//	For a copy, see <https://opensource.org/licenses/MIT>.


#pragma once


//
//	Include files
//

#include "JgsSprite.h"
#include "BaseApp.h"


//
//	Constants
//

// movements
static constexpr int compassWiggle[] = {
	0, -1, -0, -1,
	0, -1, 0, 1,
	1, 1, 0, -1,
	0, 1, 0, -1,
	0 -1, 0, 1,
	0, -1, 0, -1
};

static constexpr int compassPath[] = {
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19
};

static constexpr int compassWiggleSteps = sizeof(compassWiggle) / sizeof(*compassWiggle);
static constexpr int compassPathSteps = sizeof(compassPath) / sizeof(*compassPath);


//
//	CompassApp
//

class CompassApp : public BaseApp {
public:
	// constructor
	CompassApp(AppContext& context) :
		background(context.tft),
		plane(context.tft) {}

	// initial setup
	void setup(AppContext& context) override {
		// load images
		JgsSprite::fromJpegSdFile(&background, "/compass.jpeg");
		background.setPivot(background.width() / 2, background.height() / 2);
		JgsSprite::fromJpegSdFile(&plane, "/plane.jpeg");
	}

	// called once a loop (when app is active)
	void loop(AppContext& context) override {
		static int compassPathIndex = 0;
		static int compassWiggleIndex = 0;
		int angle = compassPath[compassPathIndex];

		background.pushRotated(context.framebuffer, angle);
		plane.pushToSprite(context.framebuffer, 0, 0, TFT_BLACK);

		compassWiggleIndex = (compassWiggleIndex + 1) % compassWiggleSteps;

		if ((compassWiggleIndex % 3) == 0) {
			compassPathIndex = (compassPathIndex + 1) % compassPathSteps;
		}

		delay(100);
	}

private:
	// images
	TFT_eSprite background;
	TFT_eSprite plane;
};
