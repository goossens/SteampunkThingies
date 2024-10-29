//	Steampunk Thingies
//	Copyright (c) 2022-2024 Johan A. Goossens. All rights reserved.
//
//	This work is licensed under the terms of the MIT license.
//	For a copy, see <https://opensource.org/licenses/MIT>.


#pragma once


//
//	Include files
//

#include <cstddef>
#include <stdint.h>

//
//	Forward declarations
//

class TFT_eSprite;


//
//	JgsSprite
//

class JgsSprite {
public:
	// load a sprite from a JPEG file
	static void fromJpegMemory(TFT_eSprite* sprite, const uint8_t data[], size_t size);
	static void fromJpegSdFile(TFT_eSprite* sprite, const char* filename);
};
