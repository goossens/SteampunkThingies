//	Steampunk Thingies
//	Copyright (c) 2022-2025 Johan A. Goossens. All rights reserved.
//
//	This work is licensed under the terms of the MIT license.
//	For a copy, see <https://opensource.org/licenses/MIT>.


#pragma once


//
//	Include files
//

#include "Arduino.h"


// array size is 3230
const uint8_t nixie3[] PROGMEM  = {
  0xff, 0xd8, 0xff, 0xe0, 0x00, 0x10, 0x4a, 0x46, 0x49, 0x46, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01,
  0x00, 0x01, 0x00, 0x00, 0xff, 0xdb, 0x00, 0x43, 0x00, 0x08, 0x06, 0x06, 0x07, 0x06, 0x05, 0x08,
  0x07, 0x07, 0x07, 0x09, 0x09, 0x08, 0x0a, 0x0c, 0x14, 0x0d, 0x0c, 0x0b, 0x0b, 0x0c, 0x19, 0x12,
  0x13, 0x0f, 0x14, 0x1d, 0x1a, 0x1f, 0x1e, 0x1d, 0x1a, 0x1c, 0x1c, 0x20, 0x24, 0x2e, 0x27, 0x20,
  0x22, 0x2c, 0x23, 0x1c, 0x1c, 0x28, 0x37, 0x29, 0x2c, 0x30, 0x31, 0x34, 0x34, 0x34, 0x1f, 0x27,
  0x39, 0x3d, 0x38, 0x32, 0x3c, 0x2e, 0x33, 0x34, 0x32, 0xff, 0xdb, 0x00, 0x43, 0x01, 0x09, 0x09,
  0x09, 0x0c, 0x0b, 0x0c, 0x18, 0x0d, 0x0d, 0x18, 0x32, 0x21, 0x1c, 0x21, 0x32, 0x32, 0x32, 0x32,
  0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32,
  0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32,
  0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0xff, 0xc0,
  0x00, 0x11, 0x08, 0x00, 0xaa, 0x00, 0x4b, 0x03, 0x01, 0x22, 0x00, 0x02, 0x11, 0x01, 0x03, 0x11,
  0x01, 0xff, 0xc4, 0x00, 0x1f, 0x00, 0x00, 0x01, 0x05, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,
  0x0a, 0x0b, 0xff, 0xc4, 0x00, 0xb5, 0x10, 0x00, 0x02, 0x01, 0x03, 0x03, 0x02, 0x04, 0x03, 0x05,
  0x05, 0x04, 0x04, 0x00, 0x00, 0x01, 0x7d, 0x01, 0x02, 0x03, 0x00, 0x04, 0x11, 0x05, 0x12, 0x21,
  0x31, 0x41, 0x06, 0x13, 0x51, 0x61, 0x07, 0x22, 0x71, 0x14, 0x32, 0x81, 0x91, 0xa1, 0x08, 0x23,
  0x42, 0xb1, 0xc1, 0x15, 0x52, 0xd1, 0xf0, 0x24, 0x33, 0x62, 0x72, 0x82, 0x09, 0x0a, 0x16, 0x17,
  0x18, 0x19, 0x1a, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a,
  0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5a,
  0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7a,
  0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99,
  0x9a, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7,
  0xb8, 0xb9, 0xba, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xd2, 0xd3, 0xd4, 0xd5,
  0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xf1,
  0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xff, 0xc4, 0x00, 0x1f, 0x01, 0x00, 0x03,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0xff, 0xc4, 0x00, 0xb5, 0x11, 0x00,
  0x02, 0x01, 0x02, 0x04, 0x04, 0x03, 0x04, 0x07, 0x05, 0x04, 0x04, 0x00, 0x01, 0x02, 0x77, 0x00,
  0x01, 0x02, 0x03, 0x11, 0x04, 0x05, 0x21, 0x31, 0x06, 0x12, 0x41, 0x51, 0x07, 0x61, 0x71, 0x13,
  0x22, 0x32, 0x81, 0x08, 0x14, 0x42, 0x91, 0xa1, 0xb1, 0xc1, 0x09, 0x23, 0x33, 0x52, 0xf0, 0x15,
  0x62, 0x72, 0xd1, 0x0a, 0x16, 0x24, 0x34, 0xe1, 0x25, 0xf1, 0x17, 0x18, 0x19, 0x1a, 0x26, 0x27,
  0x28, 0x29, 0x2a, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49,
  0x4a, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5a, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69,
  0x6a, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7a, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88,
  0x89, 0x8a, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6,
  0xa7, 0xa8, 0xa9, 0xaa, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xba, 0xc2, 0xc3, 0xc4,
  0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0xe2,
  0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9,
  0xfa, 0xff, 0xda, 0x00, 0x0c, 0x03, 0x01, 0x00, 0x02, 0x11, 0x03, 0x11, 0x00, 0x3f, 0x00, 0xf0,
  0x9a, 0x28, 0xa5, 0xab, 0x20, 0x4a, 0x5a, 0x28, 0xa0, 0x0b, 0xb6, 0x51, 0x46, 0x10, 0x4d, 0x2c,
  0x61, 0xd3, 0x7e, 0xc2, 0x5b, 0x90, 0x3d, 0x78, 0xab, 0xde, 0x24, 0xd3, 0xad, 0xac, 0x67, 0x81,
  0xad, 0xa3, 0x68, 0x96, 0x44, 0xcb, 0x23, 0x7e, 0x04, 0x11, 0xf5, 0x06, 0xb6, 0xbc, 0x3d, 0xa6,
  0x0b, 0xad, 0x05, 0x21, 0x9e, 0x2f, 0x95, 0xe7, 0xf3, 0xf3, 0xb7, 0x9c, 0x63, 0x03, 0x9f, 0x4a,
  0xca, 0xd7, 0x84, 0xd7, 0x51, 0x1b, 0xc9, 0x03, 0x16, 0x2f, 0xf3, 0x36, 0x38, 0xf4, 0xfe, 0x82,
  0xb9, 0x94, 0xd4, 0xaa, 0x68, 0xf6, 0xdc, 0xd5, 0xc5, 0xc6, 0x36, 0x6b, 0x73, 0x9f, 0xa2, 0x8a,
  0x2b, 0xa4, 0xc8, 0x28, 0xa2, 0x8a, 0x00, 0x28, 0xa2, 0x8a, 0x00, 0x29, 0xd1, 0xa6, 0xf7, 0x0b,
  0xf9, 0xd2, 0x00, 0x49, 0xc0, 0x19, 0x3e, 0x82, 0xbb, 0x6f, 0x0e, 0x78, 0x3e, 0xec, 0x43, 0xf6,
  0xeb, 0xd8, 0x31, 0x1c, 0xaa, 0x56, 0x34, 0x29, 0xbc, 0x8e, 0x7a, 0x91, 0xda, 0x8b, 0x05, 0xd2,
  0xdc, 0xdb, 0xd0, 0xf4, 0xcb, 0xf9, 0x6c, 0x52, 0xf1, 0xaf, 0x2c, 0xad, 0x6d, 0xf2, 0xaa, 0x2d,
  0xfc, 0xc0, 0x5b, 0x6f, 0x4c, 0xf2, 0x78, 0xfa, 0x7f, 0x2a, 0x9e, 0xeb, 0x48, 0xd2, 0x6d, 0x04,
  0xcb, 0x73, 0x75, 0x1c, 0xb6, 0xce, 0x9f, 0x3a, 0xc6, 0xdc, 0x9c, 0xf5, 0xc0, 0xc9, 0x19, 0x1d,
  0x47, 0xb8, 0xa6, 0x7f, 0x61, 0xda, 0xdb, 0x07, 0x5b, 0x65, 0xf3, 0xa3, 0x65, 0x18, 0x32, 0x5a,
  0xaa, 0x30, 0x3d, 0xfb, 0x9e, 0x2a, 0x54, 0xd2, 0x2d, 0xee, 0x0c, 0x71, 0xcc, 0xb2, 0x00, 0x46,
  0x0a, 0xad, 0xae, 0xe2, 0x3d, 0x31, 0x83, 0x58, 0xa8, 0xc1, 0x3b, 0xa5, 0x63, 0x5d, 0xd6, 0xb2,
  0xfc, 0x0f, 0x29, 0xb9, 0x87, 0xec, 0xf7, 0x52, 0xc2, 0x1c, 0x38, 0x46, 0x2a, 0x18, 0x7f, 0x10,
  0xec, 0x6a, 0x2a, 0xf4, 0x1f, 0x19, 0x78, 0x1a, 0xea, 0x28, 0x9f, 0x5c, 0xd3, 0xad, 0x9c, 0x59,
  0xe1, 0x44, 0xf0, 0x95, 0x21, 0xa2, 0x6e, 0x99, 0x19, 0xea, 0x0f, 0xe9, 0x5e, 0x7f, 0xdf, 0x15,
  0xb3, 0x56, 0x31, 0x4d, 0x3d, 0x84, 0xa5, 0xa2, 0x92, 0x81, 0x8a, 0x01, 0x24, 0x01, 0xd4, 0xd7,
  0x5d, 0xe1, 0x0f, 0x0f, 0xe8, 0x3a, 0x83, 0x4d, 0x71, 0xaf, 0x6a, 0xf1, 0xd9, 0x5a, 0xc3, 0x8c,
  0xa9, 0xc9, 0x79, 0x09, 0xec, 0xaa, 0x39, 0x3f, 0x5a, 0xe4, 0x45, 0x4d, 0x9c, 0x60, 0x82, 0x3e,
  0x94, 0xd3, 0x48, 0x4d, 0x36, 0xb4, 0x3d, 0xa6, 0x3b, 0xbf, 0x85, 0x5a, 0x44, 0x23, 0xc9, 0xb5,
  0xba, 0xba, 0x6c, 0x75, 0xda, 0x17, 0x3f, 0x9d, 0x6c, 0xe9, 0x1e, 0x3c, 0xf8, 0x77, 0x04, 0x6b,
  0x22, 0xc4, 0xf6, 0x32, 0x64, 0x8d, 0x8e, 0x8e, 0xc4, 0x0f, 0x5f, 0x94, 0x11, 0xcd, 0x78, 0x00,
  0x59, 0x1b, 0x9e, 0x00, 0xf5, 0x24, 0x0a, 0x73, 0x2e, 0x09, 0x12, 0x6e, 0x0f, 0xec, 0x6a, 0xb9,
  0xd9, 0x9f, 0xb1, 0x4f, 0x76, 0x7b, 0x7e, 0xa7, 0xe2, 0xff, 0x00, 0x0b, 0xde, 0x5d, 0x16, 0xb1,
  0xd4, 0x2d, 0xa3, 0x4e, 0x99, 0x97, 0xcd, 0x52, 0x7f, 0x00, 0x86, 0x99, 0x6b, 0xae, 0x68, 0x2d,
  0x70, 0x1a, 0x5f, 0x12, 0x59, 0xc2, 0xa3, 0xfe, 0x79, 0x24, 0xce, 0x47, 0xfe, 0x38, 0x2b, 0xc3,
  0x8b, 0xb2, 0x9e, 0x0d, 0x5b, 0xb6, 0x94, 0x92, 0x8e, 0xdc, 0x85, 0x3c, 0x81, 0x4a, 0xf1, 0x7d,
  0x07, 0xec, 0xf9, 0x74, 0x47, 0xb3, 0xea, 0x3e, 0x22, 0xf0, 0xfc, 0x4c, 0x04, 0x57, 0xb1, 0xea,
  0x28, 0x4e, 0x49, 0x78, 0x88, 0xfe, 0x63, 0x9a, 0xa1, 0x26, 0xa1, 0xe0, 0x1b, 0xe5, 0xff, 0x00,
  0x89, 0xc6, 0x8c, 0xa8, 0x8d, 0xc7, 0x9d, 0x04, 0x65, 0x48, 0x3e, 0xbc, 0x11, 0x5e, 0x69, 0x3e,
  0xa5, 0x28, 0xfd, 0xd5, 0xbc, 0x29, 0x1f, 0x19, 0xdc, 0x46, 0x4d, 0x66, 0x4d, 0x3c, 0xd3, 0x36,
  0x65, 0x95, 0xdb, 0xea, 0x6a, 0xae, 0x96, 0xc4, 0xa8, 0x37, 0xb9, 0xdd, 0x78, 0xdf, 0xc0, 0x3a,
  0x56, 0x97, 0xa3, 0xc7, 0xaf, 0xf8, 0x77, 0x55, 0x4b, 0xcd, 0x3a, 0x47, 0x08, 0x62, 0x66, 0xcb,
  0xc6, 0x4f, 0x4f, 0xc2, 0xbc, 0xea, 0xaf, 0xad, 0xe4, 0xc2, 0xd7, 0xec, 0x82, 0x69, 0x3c, 0x82,
  0xdb, 0x8c, 0x7b, 0x8e, 0xd2, 0x7d, 0x71, 0x54, 0x5c, 0x7c, 0xe6, 0xa1, 0xbb, 0x9a, 0xa4, 0xd0,
  0x23, 0x05, 0x61, 0x91, 0x91, 0xe9, 0x53, 0x70, 0xcd, 0xb5, 0x06, 0x32, 0x7a, 0xe2, 0xab, 0xf7,
  0x15, 0x76, 0xca, 0x33, 0x25, 0xda, 0x20, 0xef, 0xeb, 0x51, 0x27, 0x65, 0x73, 0x5a, 0x71, 0xe6,
  0x92, 0x44, 0x4a, 0x01, 0xc9, 0x07, 0x90, 0x78, 0x18, 0xeb, 0x52, 0x20, 0x94, 0xa9, 0x2a, 0xad,
  0x81, 0xd4, 0x8f, 0xeb, 0x5b, 0x7a, 0x4f, 0x87, 0x2e, 0x75, 0x5b, 0x84, 0x86, 0xd6, 0x2f, 0x32,
  0x56, 0x4d, 0xc1, 0x41, 0xed, 0x5d, 0x6d, 0xbf, 0xc3, 0x0d, 0x65, 0x6d, 0x1b, 0x7d, 0x99, 0xde,
  0x4f, 0x0a, 0x08, 0xe9, 0xef, 0xcd, 0x66, 0xea, 0x24, 0xb5, 0x92, 0x3a, 0xe3, 0x85, 0x6d, 0xec,
  0x79, 0x9b, 0x36, 0xc9, 0x37, 0x70, 0x48, 0x39, 0xe4, 0x66, 0xad, 0x5a, 0x86, 0x31, 0x33, 0xa8,
  0x2a, 0x18, 0xf6, 0xe2, 0xbb, 0x4d, 0x4b, 0xe1, 0x47, 0x88, 0x16, 0x19, 0x6e, 0x92, 0xd0, 0x24,
  0x70, 0xa9, 0x77, 0xdc, 0xe1, 0x46, 0xd0, 0x32, 0x79, 0xcf, 0x5a, 0x9b, 0xc3, 0x5f, 0x0c, 0xf5,
  0x6d, 0x52, 0xde, 0x59, 0xbc, 0x96, 0x65, 0x29, 0x1c, 0x91, 0xaa, 0x10, 0xca, 0x55, 0xc6, 0x41,
  0x27, 0x3d, 0x71, 0xda, 0xa5, 0x62, 0x21, 0xb5, 0xc4, 0xf0, 0x73, 0xe6, 0xd2, 0xd6, 0xf5, 0x38,
  0xf0, 0xb2, 0x99, 0x94, 0x9d, 0xe7, 0x28, 0x6a, 0x83, 0x96, 0x53, 0x96, 0x57, 0xe0, 0xfa, 0x57,
  0xad, 0xaf, 0xc2, 0x9d, 0x6c, 0x95, 0x61, 0xa7, 0xb8, 0x65, 0x04, 0x63, 0x3c, 0x11, 0xf9, 0xd7,
  0x37, 0xe2, 0x3f, 0x87, 0x9a, 0xb6, 0x89, 0x60, 0xd7, 0x77, 0x96, 0x32, 0x45, 0x0e, 0x40, 0xf3,
  0x3a, 0x81, 0xf5, 0xad, 0x79, 0xb4, 0xdc, 0x3e, 0xad, 0xaf, 0xfc, 0x13, 0x89, 0x6c, 0x3c, 0xc4,
  0x81, 0xd4, 0x92, 0x38, 0xc5, 0x55, 0x90, 0x7e, 0xf0, 0xd6, 0x86, 0xa0, 0xa9, 0x0d, 0xda, 0xc7,
  0x1b, 0x70, 0x01, 0xfe, 0x75, 0x9f, 0x27, 0xfa, 0xc6, 0xa7, 0x17, 0x75, 0x73, 0x92, 0xa4, 0x79,
  0x64, 0xd1, 0x1d, 0x5f, 0xd3, 0xdb, 0x6d, 0xdc, 0x6c, 0x7a, 0x01, 0xce, 0x6b, 0x3c, 0xf6, 0xfa,
  0xd5, 0xcb, 0x53, 0xfb, 0xc3, 0xfe, 0xe1, 0xa5, 0x3f, 0x85, 0x95, 0x49, 0xda, 0x69, 0x9d, 0x67,
  0x85, 0x7c, 0x4f, 0x7b, 0xa1, 0xea, 0x0b, 0x73, 0x68, 0xe9, 0x19, 0x58, 0xf6, 0x61, 0x94, 0x10,
  0xfe, 0xc7, 0xda, 0xbd, 0x14, 0x7c, 0x48, 0xbe, 0xfb, 0x04, 0x8f, 0x71, 0x70, 0xac, 0xe0, 0x00,
  0x42, 0x44, 0x83, 0x24, 0xfb, 0xe3, 0x8f, 0xc3, 0x9a, 0xf1, 0xbb, 0x13, 0x99, 0x95, 0x88, 0xc9,
  0x0b, 0xf2, 0x8f, 0x7a, 0xd6, 0x13, 0xe7, 0x4b, 0x11, 0x80, 0xc4, 0xef, 0xfe, 0x43, 0xfc, 0x49,
  0xaf, 0x36, 0xbd, 0x3e, 0x66, 0x7b, 0x98, 0x79, 0xc7, 0x97, 0xde, 0x49, 0x9d, 0xd6, 0x9d, 0xe3,
  0x49, 0x9e, 0xf8, 0xc7, 0xf6, 0x2d, 0x39, 0x92, 0x47, 0x05, 0xc7, 0xd9, 0x91, 0x99, 0x89, 0xf5,
  0x24, 0x13, 0xf8, 0xd5, 0xff, 0x00, 0xed, 0x74, 0xfb, 0x48, 0xb6, 0x36, 0x56, 0x8a, 0x58, 0x79,
  0x8e, 0xf0, 0xa0, 0x8c, 0xb3, 0x11, 0x9f, 0xe1, 0xc7, 0x03, 0x8c, 0x57, 0x11, 0xa4, 0x47, 0xe5,
  0xde, 0x46, 0xd2, 0x26, 0x59, 0x98, 0x0c, 0x1e, 0x31, 0xc5, 0x76, 0x7a, 0x1e, 0x97, 0x2e, 0xa5,
  0xab, 0x5a, 0xa4, 0x71, 0x96, 0x66, 0x44, 0x19, 0xc0, 0xfe, 0xe5, 0x73, 0xcd, 0x5e, 0x56, 0x5b,
  0x58, 0xef, 0x84, 0x62, 0xa1, 0xcc, 0xce, 0xdf, 0xc3, 0xda, 0x86, 0xab, 0xa9, 0x45, 0x1c, 0x80,
  0x86, 0xb5, 0x8c, 0xe2, 0x52, 0xb0, 0xa3, 0x3a, 0x01, 0xf8, 0x7c, 0xdf, 0xce, 0xb8, 0x0f, 0x88,
  0x5e, 0x22, 0x59, 0x6e, 0xb5, 0x88, 0xb4, 0xd9, 0xcb, 0x69, 0xd3, 0xcb, 0x1c, 0x5b, 0x15, 0xf2,
  0xac, 0xc8, 0x39, 0x70, 0x3a, 0x0c, 0x92, 0x47, 0x1d, 0x76, 0xd7, 0xa1, 0x78, 0xa3, 0x56, 0x87,
  0xc0, 0xde, 0x18, 0x1a, 0x5e, 0x9e, 0x41, 0xd4, 0x6e, 0x57, 0x6e, 0xf0, 0x3e, 0xe9, 0x3c, 0x67,
  0xfc, 0x2b, 0xc2, 0xf5, 0x26, 0x22, 0x18, 0xd2, 0x4f, 0x9c, 0x6c, 0xda, 0xd9, 0x1d, 0x79, 0x3d,
  0x7f, 0x1e, 0x6b, 0x78, 0x41, 0x52, 0x6b, 0xa9, 0xc2, 0xad, 0x55, 0xca, 0x69, 0x59, 0x74, 0xff,
  0x00, 0x3f, 0xf2, 0x39, 0x7d, 0x59, 0xcb, 0xea, 0x39, 0xda, 0x47, 0x15, 0x49, 0xfe, 0xf9, 0xab,
  0xba, 0x92, 0x62, 0xf7, 0x38, 0xe3, 0x1f, 0xd6, 0xa9, 0x3f, 0x2c, 0x6b, 0xd3, 0x87, 0xc2, 0x8f,
  0x0e, 0xb3, 0xbc, 0xd9, 0x0b, 0x76, 0xfa, 0xd5, 0xeb, 0x3f, 0xf5, 0x9f, 0xf0, 0x12, 0x3f, 0x43,
  0x54, 0x9b, 0xa0, 0xfa, 0xd5, 0xdb, 0x43, 0x82, 0x4f, 0xa2, 0xff, 0x00, 0x43, 0x44, 0xf6, 0x62,
  0xa5, 0xf1, 0xa2, 0x7b, 0x76, 0xda, 0xe3, 0xd4, 0x2e, 0x47, 0xe1, 0x5b, 0xda, 0x6a, 0x2c, 0x91,
  0x43, 0x3f, 0x97, 0x93, 0x8c, 0x85, 0x03, 0x38, 0x39, 0xe4, 0x8f, 0x5a, 0xc1, 0xb7, 0x05, 0xa7,
  0x8c, 0x0c, 0xfd, 0xde, 0xd5, 0xb3, 0x24, 0x84, 0x5b, 0x88, 0xa3, 0x63, 0x85, 0xc6, 0x63, 0x57,
  0xc6, 0x0f, 0xd7, 0xbd, 0x70, 0xd5, 0xd7, 0x43, 0xd7, 0xc3, 0x59, 0x6a, 0xcd, 0x2b, 0x09, 0x0f,
  0xf6, 0xca, 0xb4, 0x91, 0x9c, 0x87, 0xe1, 0x17, 0x92, 0x07, 0x3c, 0x73, 0x5e, 0xe9, 0xe0, 0x6f,
  0xec, 0xeb, 0x7d, 0x2b, 0xed, 0x51, 0x60, 0x5f, 0x3c, 0x4a, 0x00, 0x91, 0x7e, 0xee, 0x14, 0x7a,
  0x67, 0x83, 0xd7, 0x3e, 0x95, 0xf3, 0xc5, 0x95, 0xf9, 0x17, 0x8b, 0xbc, 0x3e, 0x15, 0xbb, 0x02,
  0x7f, 0x5a, 0xd9, 0x83, 0x5f, 0x8a, 0xde, 0x54, 0x90, 0x7d, 0xab, 0x7a, 0x27, 0x00, 0xb1, 0x03,
  0xee, 0xe3, 0xa5, 0x73, 0x49, 0x4e, 0x32, 0xf7, 0x4e, 0xc6, 0xa1, 0x56, 0x9b, 0x4e, 0x56, 0x3a,
  0xcf, 0x12, 0xd8, 0xea, 0xfa, 0x8f, 0x88, 0x1a, 0x49, 0x36, 0xcd, 0x04, 0x6c, 0x7c, 0xdb, 0xa8,
  0xdb, 0x74, 0x7b, 0xd8, 0x64, 0x0c, 0x8e, 0xfb, 0x71, 0xc7, 0xbd, 0x71, 0x7a, 0xb4, 0x65, 0x58,
  0x05, 0xe8, 0xc3, 0x28, 0x33, 0xfc, 0x23, 0x80, 0x7f, 0x3c, 0xfe, 0x55, 0xe8, 0x3e, 0x0e, 0xbb,
  0x36, 0xe4, 0xbe, 0xa6, 0x63, 0x5b, 0x56, 0x52, 0xf3, 0x33, 0x36, 0xe6, 0x77, 0x6f, 0xef, 0x2e,
  0x7e, 0xef, 0x6f, 0x5a, 0x8b, 0xe2, 0x1f, 0x86, 0x61, 0x85, 0x63, 0xd5, 0xac, 0x00, 0x16, 0x92,
  0xa9, 0x52, 0x8a, 0x72, 0x23, 0x60, 0x32, 0x00, 0xff, 0x00, 0x64, 0x8c, 0x11, 0xed, 0x45, 0x39,
  0x4a, 0x53, 0xb4, 0xbe, 0x43, 0x93, 0x51, 0xf7, 0x6d, 0xbf, 0xf5, 0x63, 0xc6, 0xf5, 0x56, 0x63,
  0x78, 0x54, 0xf4, 0x02, 0xb3, 0xdb, 0xef, 0x1a, 0xd0, 0xd6, 0x0e, 0x75, 0x49, 0x7d, 0xb1, 0x54,
  0x19, 0x49, 0x62, 0x71, 0x5e, 0xbc, 0x3e, 0x14, 0x7c, 0xe5, 0x65, 0xef, 0xbf, 0x52, 0x16, 0xce,
  0xdf, 0xc6, 0xae, 0x59, 0x9f, 0x99, 0xf3, 0xfd, 0xc3, 0xfc, 0x8d, 0x53, 0x62, 0x76, 0xe0, 0x77,
  0x35, 0x6e, 0xd4, 0xe0, 0xbf, 0xfb, 0x87, 0xf9, 0x1a, 0x27, 0xb3, 0x15, 0x2f, 0x89, 0x1a, 0x56,
  0x31, 0x92, 0xac, 0x54, 0xe1, 0x8a, 0xe0, 0x55, 0x81, 0x63, 0x2c, 0x29, 0xfb, 0xc0, 0x0b, 0x03,
  0x81, 0xc8, 0xad, 0xbf, 0x06, 0xe9, 0xd6, 0x57, 0x9a, 0xad, 0xa2, 0xea, 0x0f, 0xe5, 0xd9, 0x4d,
  0x22, 0x29, 0x90, 0x0e, 0x54, 0xe4, 0x7e, 0x59, 0xe9, 0x5d, 0x3f, 0x8d, 0xfc, 0x0f, 0x36, 0x8b,
  0xa8, 0xcc, 0xd8, 0x06, 0x09, 0x9f, 0x7c, 0x6d, 0x83, 0x8f, 0x71, 0x5e, 0x7b, 0xa8, 0xdc, 0xdc,
  0x51, 0xed, 0xc2, 0x94, 0x79, 0x55, 0xf7, 0x38, 0x5b, 0x51, 0x30, 0x94, 0x2e, 0xe3, 0x8d, 0xc7,
  0x8c, 0x0a, 0xb4, 0x37, 0xcb, 0x75, 0x1d, 0xb3, 0x12, 0x57, 0x87, 0x65, 0x03, 0xbf, 0x6f, 0xd6,
  0xa5, 0xb2, 0xb3, 0xdb, 0x78, 0xd9, 0xdb, 0x85, 0x0e, 0x4f, 0x5e, 0xca, 0x6a, 0x4b, 0x38, 0xb7,
  0x48, 0x6e, 0x47, 0x0f, 0x36, 0x59, 0x07, 0xa2, 0x81, 0x81, 0x59, 0x37, 0x69, 0x6a, 0x75, 0x28,
  0x5e, 0x36, 0x45, 0xe8, 0xe3, 0x9a, 0xde, 0x68, 0x52, 0x09, 0x01, 0x8f, 0x0c, 0xf2, 0xa3, 0x77,
  0x3c, 0x8c, 0x81, 0xec, 0x0d, 0x7a, 0x45, 0xc8, 0x93, 0xfe, 0x10, 0xdb, 0xfb, 0x19, 0x40, 0x6b,
  0x58, 0xac, 0x7c, 0xc8, 0x64, 0xff, 0x00, 0x69, 0x58, 0x02, 0x3f, 0xf1, 0xf3, 0xf8, 0x7d, 0x2b,
  0x8e, 0xd0, 0x34, 0x99, 0x26, 0xbe, 0xb7, 0xbb, 0xf2, 0xb7, 0xa4, 0x0a, 0xc7, 0x68, 0x27, 0x96,
  0xc7, 0x03, 0xf4, 0xc9, 0xfa, 0x57, 0x51, 0xe3, 0x5d, 0x4a, 0xdf, 0x48, 0xf0, 0x4a, 0xe9, 0xe8,
  0xeb, 0xe7, 0x18, 0x56, 0x16, 0xc1, 0xf7, 0xcb, 0xff, 0x00, 0xe3, 0xd8, 0x1f, 0xf0, 0x13, 0x51,
  0x2b, 0xb9, 0x42, 0x29, 0xeb, 0x72, 0x6a, 0x59, 0x6b, 0x6e, 0xdf, 0x81, 0xe1, 0x7a, 0xee, 0x3f,
  0xb5, 0x64, 0xe9, 0xd0, 0x74, 0xac, 0xa6, 0xfb, 0xc6, 0xb4, 0x35, 0x47, 0xf3, 0x2f, 0xc9, 0x1e,
  0x80, 0x55, 0x07, 0x18, 0x72, 0x2b, 0xd7, 0xa7, 0xf0, 0xa3, 0xe7, 0xb1, 0x0e, 0xf5, 0x1f, 0xa9,
  0x17, 0x6a, 0xb5, 0x6c, 0xc0, 0x48, 0x72, 0x4e, 0x0a, 0x30, 0xe3, 0xe9, 0x55, 0x45, 0x4c, 0xac,
  0x14, 0x83, 0xec, 0x69, 0xc9, 0x5d, 0x11, 0x4d, 0xda, 0x49, 0x9d, 0x36, 0x9b, 0x7a, 0x16, 0xcd,
  0xec, 0xd6, 0x50, 0x9b, 0xd9, 0x49, 0x24, 0xe3, 0x18, 0xff, 0x00, 0xeb, 0xd7, 0xb2, 0x68, 0x1e,
  0x3b, 0x8a, 0xe7, 0x47, 0x5d, 0x37, 0xc4, 0xf0, 0xc7, 0x79, 0x0a, 0x61, 0x56, 0x68, 0xdb, 0x32,
  0x0f, 0x4e, 0x38, 0xcf, 0xd7, 0xaf, 0xd6, 0xbe, 0x7a, 0x8a, 0x58, 0xa4, 0x93, 0xf7, 0xac, 0xeb,
  0xee, 0xa0, 0x1a, 0xb6, 0x2f, 0x04, 0x41, 0xa3, 0x0e, 0x58, 0x2b, 0x9d, 0xac, 0x47, 0x24, 0x76,
  0xae, 0x19, 0x50, 0x95, 0xef, 0x17, 0x6f, 0x91, 0xec, 0x47, 0x13, 0x09, 0x45, 0x29, 0xab, 0xdb,
  0x6d, 0x6d, 0x63, 0xdb, 0x35, 0xeb, 0x2f, 0x07, 0x18, 0xd4, 0x58, 0x78, 0x80, 0xc7, 0x25, 0xd4,
  0xa2, 0x26, 0x49, 0x54, 0x8f, 0x2d, 0x5b, 0x86, 0x27, 0x8e, 0x80, 0x66, 0xaf, 0x47, 0xa4, 0x78,
  0x3e, 0x3b, 0xc6, 0x9b, 0xfb, 0x7c, 0x48, 0x81, 0x70, 0x90, 0xc1, 0x13, 0x31, 0x0b, 0x80, 0x00,
  0x1c, 0x57, 0xcf, 0x93, 0xea, 0x53, 0xbc, 0xbc, 0x39, 0x03, 0x05, 0x73, 0xea, 0x08, 0xc1, 0x15,
  0x7e, 0x1f, 0x11, 0x6a, 0x4e, 0xe1, 0x26, 0xba, 0x77, 0x4e, 0x17, 0x2c, 0x72, 0x70, 0x06, 0x00,
  0xfa, 0x0a, 0x25, 0x86, 0x9b, 0x77, 0xba, 0x08, 0xe3, 0xa2, 0x9f, 0x2d, 0xdf, 0xe1, 0xfe, 0x47,
  0xb9, 0x6a, 0xfa, 0xfd, 0x88, 0xb2, 0x4d, 0x37, 0x45, 0x8b, 0xec, 0xb6, 0xa4, 0x1f, 0x32, 0x49,
  0x5b, 0x12, 0xc8, 0x3b, 0x83, 0xfd, 0xd0, 0x7b, 0xf7, 0x3d, 0x38, 0xaf, 0x26, 0xf1, 0x15, 0xf5,
  0xdd, 0xd1, 0x99, 0xa7, 0x95, 0x5a, 0x31, 0xb5, 0x50, 0x2b, 0x64, 0x01, 0x9a, 0xa3, 0x15, 0xe1,
  0xb8, 0xbd, 0x44, 0x2f, 0xb5, 0x36, 0x12, 0xcd, 0xeb, 0xc5, 0x52, 0x2e, 0x82, 0xc6, 0x75, 0x52,
  0x58, 0xee, 0x5e, 0x6a, 0xe9, 0x50, 0x94, 0x1d, 0xef, 0xbf, 0x91, 0x9d, 0x6c, 0x54, 0x1c, 0x39,
  0x52, 0xfc, 0x77, 0x28, 0xdc, 0xc8, 0x24, 0xbc, 0x91, 0x87, 0x42, 0xc7, 0x1f, 0x4a, 0x82, 0x4f,
  0xf5, 0x86, 0x95, 0x8f, 0xef, 0x33, 0xea, 0x73, 0x48, 0xe7, 0xe7, 0x35, 0xd9, 0x1d, 0x11, 0xe5,
  0x4d, 0xde, 0x4d, 0x90, 0x8a, 0x95, 0x86, 0x14, 0x12, 0xc2, 0xa2, 0x14, 0xf6, 0xfb, 0xb4, 0x31,
  0x26, 0x3a, 0x38, 0xcb, 0x3e, 0x15, 0x94, 0x93, 0xef, 0x52, 0xba, 0x3a, 0x64, 0x36, 0xd1, 0xcf,
  0xad, 0x55, 0x62, 0x43, 0x82, 0x3b, 0x0a, 0x90, 0x97, 0x7c, 0x75, 0xa5, 0xca, 0x5f, 0x3d, 0x90,
  0xe8, 0x6d, 0x9e, 0xe6, 0xe3, 0xcb, 0x0c, 0xab, 0x9e, 0xec, 0x78, 0xab, 0x77, 0x1a, 0x5c, 0x96,
  0x32, 0x20, 0x33, 0x43, 0x26, 0xee, 0x7e, 0x43, 0xd3, 0xeb, 0x59, 0xd1, 0x90, 0x24, 0x04, 0xe7,
  0x81, 0xfa, 0xd4, 0xab, 0x2b, 0x4d, 0x31, 0x2c, 0x7a, 0x74, 0xa2, 0xcc, 0x5c, 0xcb, 0xb1, 0xa3,
  0x6a, 0x5d, 0x6f, 0xe3, 0x24, 0x29, 0xf9, 0x71, 0xb4, 0x1a, 0x64, 0x8b, 0x24, 0x50, 0x5c, 0x24,
  0x8b, 0xb3, 0xa1, 0xc1, 0xed, 0xcd, 0x16, 0x05, 0x9b, 0x52, 0x88, 0x6d, 0x0d, 0xc5, 0x5b, 0xd4,
  0x13, 0x6c, 0x77, 0x3b, 0xa3, 0x2a, 0x77, 0x2e, 0x01, 0x39, 0xe2, 0xad, 0x45, 0xf2, 0xdc, 0xce,
  0x75, 0x15, 0xed, 0x63, 0x1d, 0x23, 0x77, 0x05, 0x86, 0x30, 0x3b, 0xd2, 0x3e, 0x77, 0x1a, 0x91,
  0x19, 0xb2, 0x06, 0x78, 0xcd, 0x32, 0x4f, 0xf5, 0x8d, 0x49, 0x0d, 0xbd, 0x48, 0xa3, 0x52, 0xe4,
  0x81, 0xd7, 0x19, 0xa9, 0x36, 0x12, 0x42, 0x93, 0x8c, 0xd4, 0x48, 0xdb, 0x5b, 0x8e, 0xe3, 0x15,
  0x22, 0xca, 0x78, 0x52, 0x83, 0xae, 0x72, 0x4d, 0x0c, 0x08, 0x98, 0x31, 0x73, 0x90, 0x7d, 0x2a,
  0xc4, 0x25, 0x89, 0x24, 0x8e, 0x95, 0x2a, 0xed, 0x67, 0x63, 0x80, 0x00, 0x1c, 0x01, 0x4e, 0x8d,
  0x77, 0x02, 0xaa, 0x41, 0xef, 0x8a, 0x57, 0x1d, 0x8a, 0x8e, 0x8d, 0xb8, 0xb0, 0x5c, 0x29, 0xe9,
  0x4d, 0x45, 0x70, 0xe4, 0xed, 0xe2, 0xb4, 0x11, 0x0a, 0xb3, 0x86, 0xc6, 0x18, 0x62, 0x9c, 0x88,
  0x8b, 0x32, 0x9f, 0x94, 0xa9, 0x18, 0x22, 0x98, 0x8d, 0x3f, 0x06, 0xd9, 0x47, 0x7d, 0xe2, 0x08,
  0xe3, 0x95, 0xb6, 0x9c, 0x1d, 0xa0, 0x90, 0x01, 0x38, 0x3c, 0x12, 0x7a, 0x55, 0x4d, 0x66, 0xf2,
  0x5b, 0xab, 0xd9, 0x64, 0x10, 0x79, 0x31, 0x92, 0x06, 0xcc, 0xe7, 0x91, 0xc7, 0x5a, 0x9e, 0xcd,
  0x17, 0xed, 0x91, 0x88, 0xa7, 0x5b, 0x6e, 0x40, 0x32, 0x37, 0x18, 0xf7, 0xaa, 0xda, 0x90, 0x52,
  0xe1, 0x91, 0xd9, 0x93, 0x18, 0xdd, 0xd7, 0x24, 0x75, 0xad, 0x1c, 0xbd, 0xcb, 0x19, 0x24, 0x9c,
  0xee, 0x67, 0x29, 0xf9, 0x85, 0x32, 0x43, 0xfb, 0xc3, 0x4a, 0x09, 0xdd, 0x48, 0xff, 0x00, 0x7c,
  0xd6, 0x68, 0xd5, 0x95, 0xea, 0x54, 0x21, 0x8e, 0x0e, 0x33, 0xef, 0x51, 0x52, 0x50, 0x32, 0xda,
  0x2e, 0xdc, 0x82, 0xb9, 0xfa, 0x1a, 0x4c, 0x71, 0x80, 0x0e, 0x6a, 0xbc, 0x7d, 0x0f, 0xd6, 0xa4,
  0x52, 0x7c, 0x89, 0x39, 0xee, 0x2a, 0x47, 0x72, 0x5f, 0x9b, 0xd0, 0x93, 0xf5, 0xa4, 0x50, 0xc1,
  0x86, 0xe0, 0x47, 0xd6, 0x9a, 0xa4, 0xf9, 0x2c, 0x72, 0x73, 0xc7, 0x34, 0xb1, 0xb1, 0x31, 0x39,
  0x24, 0x92, 0x07, 0x1c, 0xd0, 0x2b, 0xea, 0x4c, 0xdf, 0x73, 0xa1, 0xcf, 0xae, 0x69, 0xae, 0xc7,
  0x1b, 0x79, 0xc7, 0x5e, 0xb5, 0x5b, 0x71, 0x31, 0x49, 0x92, 0x4e, 0x31, 0x8a, 0x70, 0xe6, 0x34,
  0xfa, 0x53, 0x0b, 0x8f, 0xdc, 0x07, 0xd6, 0x99, 0x45, 0x14, 0xc4, 0x7f, 0xff, 0xd9
};
