//	Steampunk Thingies
//	Copyright (c) 2022-2024 Johan A. Goossens. All rights reserved.
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
//	PotentialApp
//

class PotentialApp : public BaseApp {
public:
	// constructor
	PotentialApp(AppContext& context) :
		background(context.tft),
		hand(context.tft) {}

	// initial setup
	void setup(AppContext& context) override {
		// load images
		JgsSprite::fromJpegSdFile(&background, "/potential.jpeg");
		JgsSprite::fromJpegSdFile(&hand, "/hand.jpeg");
	}

	// called once a loop (when app is active)
	void loop(AppContext& context) override {
		static int pathIndex = 0;
		static int wiggleIndex = 0;
		int angle = path[pathIndex] + wiggle[wiggleIndex];

		background.pushToSprite(context.framebuffer, 0, 0);

		int px = context.framebuffer->getPivotX();
		int py = context.framebuffer->getPivotY();
		context.framebuffer->setPivot(119, 199);
		hand.setPivot(119, 199);
		hand.pushRotated(context.framebuffer, angle, TFT_WHITE);
		context.framebuffer->setPivot(px, py);

		wiggleIndex = (wiggleIndex + 1) % wiggleSteps;

		if ((wiggleIndex % 3) == 0) {
			pathIndex = (pathIndex + 1) % pathSteps;
		}

		delay(70);
	}

private:
	// images
	TFT_eSprite background;
	TFT_eSprite hand;

	// movements
	static inline constexpr int wiggle[] = {
		0, -1, -2, -1,
		0, -1, 0, 1,
		2, 1, 0, -1,
		0, 1, 0, -1,
		-2 -1, 0, 1,
		0, -1, 0, -1
	};

	static inline constexpr int path[] = {
		-10, -10, -10, -9, -8, -7, -7, -6, -5, -4, -4, -3, -2, -1, 0, 1, 2, 2, 3, 4, 4, 5, 6, 7, 8, 8, 9,
		10, 10, 10, 11, 12, 12, 13, 14, 15, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 24, 25, 26, 27, 28, 29,
		30, 30, 30, 31, 32, 33, 34, 35, 35, 35, 34, 33, 32, 31, 30, 30, 30, 29, 28, 28, 27, 26,
		25, 25, 25, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5,
		5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12, -13, -14, -15, -16, -17, -18,
		-20, -20, -20, -20, -19, -19, -18, -17, -16, -16, -16, -15, -14, -14, -13, -12, -12, -11, -11
	};

	static inline constexpr int wiggleSteps = sizeof(wiggle) / sizeof(*wiggle);
	static inline constexpr int pathSteps = sizeof(path) / sizeof(*path);
};
