//	Steampunk Thingies
//	Copyright (c) 2022-2024 Johan A. Goossens. All rights reserved.
//
//	This work is licensed under the terms of the MIT license.
//	For a copy, see <https://opensource.org/licenses/MIT>.


//
//	Include files
//

#include <Arduino.h>
#include <TFT_eSPI.h>
#include <JPEGDecoder.h>

#include "JgsLog.h"
#include "JgsSprite.h"


//
//	decodeCommon
//

static void decodeCommon(TFT_eSprite* sprite) {
	// retrieve information about the image
	uint32_t mcuWidth = JpegDec.MCUWidth;
	uint32_t mcuHeight = JpegDec.MCUHeight;
	uint32_t width = JpegDec.width;
	uint32_t height = JpegDec.height;

	// create the sprite
	sprite->createSprite(width, height);

	// read each MCU block until there are no more
	while (JpegDec.readSwappedBytes()) {
		// get a pointer to the image block
		uint16_t* pixels = JpegDec.pImage;

		// calculate where the image block should be drawn in the sprite
		int mcuX = JpegDec.MCUx * mcuWidth;
		int mcuY = JpegDec.MCUy * mcuHeight;

		// check if the image block size needs to be changed for the right edge
		uint32_t winW = (mcuX + mcuWidth <= width) ? mcuWidth : (width % mcuWidth);
		uint32_t winH = (mcuY + mcuHeight <= height) ? mcuHeight : (height % mcuHeight);

		// copy pixels into a continuous block (if required)
		if (winW != mcuWidth) {
			uint16_t* dest = pixels + winW;

			for (int h = 1; h < winH; h++) {
				uint16_t* src = pixels + h * mcuWidth;

				for (int w = 0; w < winW; w++) {
					*dest++ = *src++;
				}
			}
		}

		// save MCU block to sprite
		sprite->pushImage(mcuX, mcuY, winW, winH, pixels);
	}
}


//
//	JgsSprite::fromJpegMemory
//

void JgsSprite::fromJpegMemory(TFT_eSprite* sprite, const uint8_t data[], size_t size) {
	// decode image
	JpegDec.decodeArray(data, size);
	decodeCommon(sprite);
}


//
//	JgsSprite::fromJpegMemory
//

#if BOARD_HAS_SD_CARD
void JgsSprite::fromJpegSdFile(TFT_eSprite* sprite, const char* filename) {
	File jpegFile = SD.open(filename, FILE_READ);

	if (jpegFile) {
		if (JpegDec.decodeSdFile(filename)) {
			decodeCommon(sprite);

		} else {
			JgsLog::print("ERROR: File [%s] has unsupported JPEG format!\n", filename);
		}

	} else {
		JgsLog::print("ERROR: File [%s] not found!\n", filename);
  	}
}
#endif
