//	Steampunk Thingies
//	Copyright (c) 2022-2024 Johan A. Goossens. All rights reserved.
//
//	This work is licensed under the terms of the MIT license.
//	For a copy, see <https://opensource.org/licenses/MIT>.


#pragma once


//
//	Include files
//

#include <cstdio>
#include <cstdarg>

#include <Arduino.h>


//
//	JgsLog
//

class JgsLog {
public:
	// constructor
	static void init() {
#ifndef DISABLE_LOGGING
		Serial.begin(115200);
		while (!Serial);
#endif
	}

	// print a line
	static size_t print(const char* msg, ...) {
#ifndef DISABLE_LOGGING
		va_list args;
		va_start(args, msg);

		char buffer[128];
		auto size = vsnprintf(buffer, sizeof(buffer), msg, args);
		Serial.write(buffer);
		Serial.flush();

		va_end(args);
		return size;
#else
		return 0;
#endif
	}

	// show CPU/memory statistics
	static void cpuMemStats() {
#ifndef DISABLE_LOGGING
		print("\n");
		print("Chip model: %s, %dMHZ, %d cores\n", ESP.getChipModel(), ESP.getCpuFreqMHz(), ESP.getChipCores());
		print("Free heap: %d out of %d\n", ESP.getFreeHeap(), ESP.getHeapSize());
		print("Free PSRAM: %d out of %d\n", ESP.getFreePsram(), ESP.getPsramSize());
		print("Sketch size: %d out of %d\n", ESP.getSketchSize(), ESP.getFlashChipSize());
#endif
	}
};
