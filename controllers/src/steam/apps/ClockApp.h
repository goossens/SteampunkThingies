//	Steampunk Thingies
//	Copyright (c) 2022-2025 Johan A. Goossens. All rights reserved.
//
//	This work is licensed under the terms of the MIT license.
//	For a copy, see <https://opensource.org/licenses/MIT>.


#pragma once


//
//	Include files
//

#include "JgsFonts.h"

#include "BaseApp.h"


//
//	App
//

class ClockApp : public BaseApp {
public:
	// constructor
	ClockApp(AppContext& context) {}

	// initial setup
	void setup(AppContext& context) override {
		// determine clock geometry
		w = context.tft->width();
		h = context.tft->height();
		cx = w / 2;
		cy = h / 2;
		r = cx * 0.8666;
		weekdayX = cx - 30.0f;
	}

	// called once a loop (when app is active)
	void loop(AppContext& context) override {
		// get the current time
		int month = context.timezone->getMonth();
		int day = context.timezone->getDay();
		int weekday = context.timezone->getWeekDay();
		int hours = context.timezone->getHours();
		int minutes = context.timezone->getMinutes();
		int seconds = context.timezone->getSeconds();

		// clear the framebuffer
		context.framebuffer->fillSprite(TFT_BLACK);

		// render the seconds circle
		context.framebuffer->setTextColor(TFT_WHITE, TFT_BLACK);

		for (auto i = 0; i < 60; i++) {
			float angle = rad * (i * 6 - 90 + (seconds * 6));
			float cs = cos(angle);
			float sn = sin(angle);

			float x0 = (r * cs) + cx;
			float y0 = (r * sn) + cy;

			float x1 = ((r - 16) * cs) + cx;
			float y1 = ((r - 16) * sn) + cy;

			float x2 = ((r - 26) * cs) + cx;
			float y2 = ((r - 26) * sn) + cy;

			if (i % 5) {
				context.framebuffer->fillCircle(x1, y1, 1, TFT_WHITE);

			} else {
				context.framebuffer->drawLine(x1, y1, x2, y2, TFT_WHITE);
				context.framebuffer->drawString(secondLabels[i / 5], x0, y0, 2);
			}
		}

		// draw seconds
		context.framebuffer->fillTriangle(cx - 1, cy - 70, cx - 5, cy - 56, cx + 4, cy - 56, TFT_ORANGE);
		context.framebuffer->setFreeFont(&DSEG7_Modern_Bold_20);
		String s = (seconds < 10) ? "0" + String(seconds) : String(seconds);
		context.framebuffer->drawString(s, cx, cy - 36);

		// render hours and minutes
		context.framebuffer->setFreeFont(&DSEG7_Classic_Regular_28);
		String h = (hours < 10) ? "0" + String(hours) : String(hours);
		String m = (minutes < 10) ? "0" + String(minutes) : String(minutes);
		context.framebuffer->drawString(h + ":" + m, cx, cy + 28);
		context.framebuffer->setTextFont(1);

		// render month and day
		context.framebuffer->setTextColor(TFT_CYAN, TFT_BLACK);
		context.framebuffer->drawString("MONTH", cx - 40, 78, 1);
		context.framebuffer->drawString("DAY", cx + 40, 78, 1);
		context.framebuffer->setTextColor(TFT_WHITE, TFT_DARKGREY);
		context.framebuffer->drawString(String(month / 10), cx - 48, 96, 2);
		context.framebuffer->drawString(String(month % 10), cx - 32, 96, 2);
		context.framebuffer->drawString(String(day / 10), cx + 32, 96, 2);
		context.framebuffer->drawString(String(day % 10), cx + 48, 96, 2);

		// render day of week
	 	context.framebuffer->setTextColor(TFT_WHITE, TFT_BLACK);
		context.framebuffer->drawString(dayLabels[weekday - 1], weekdayX, 118, 2);
		weekdayX += 0.5 * weekdayDirection;

		if (weekdayX < cx - 30 || weekdayX > cx + 30) {
			weekdayDirection = -weekdayDirection;
		}

		// set branding
		context.framebuffer->setTextColor(TFT_ORANGE, TFT_BLACK);
		context.framebuffer->drawString("JOGO STUDIO", 120, 174, 1);

		// rendering confusing ball
		context.framebuffer->fillCircle(((r - 16) * cos(ballAngle * rad)) + cx, ((r - 16) * sin(ballAngle * rad)) + cy, 6, TFT_RED);
		ballAngle = ballAngle <= 0 ? 358 : ballAngle - 2;
	}

private:
	// properties
	int w;
	int h;
	int cx;
	int cy;
	int r;
	float weekdayX;
	float weekdayDirection = 1.0f;
	float ballAngle = 360.0f;

	// for degrees to radians conversions
	static inline constexpr float rad = 0.01745f;

	// clock labels
	static inline constexpr const char* secondLabels[] = { "00", "55", "50", "45", "40", "35", "30", "25", "20", "15", "10", "05" };
	static inline constexpr const char* dayLabels[] = { "SUNDAY", "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY" };
};
