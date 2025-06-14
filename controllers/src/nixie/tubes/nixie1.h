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


// array size is 2925
const uint8_t nixie1[] PROGMEM = {
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
  0x7a, 0x28, 0xa5, 0xab, 0x20, 0x28, 0xa2, 0x8a, 0x00, 0xb5, 0x6a, 0x88, 0x07, 0x98, 0xe8, 0x19,
  0x77, 0x6d, 0xf9, 0xb9, 0x02, 0xae, 0xeb, 0xf6, 0x30, 0x59, 0xcf, 0x09, 0x82, 0x26, 0x8b, 0x7a,
  0x65, 0x91, 0xbf, 0x30, 0x47, 0xd4, 0x1a, 0xd1, 0xd1, 0x6c, 0x45, 0xc6, 0x94, 0x90, 0x49, 0x10,
  0xda, 0xf3, 0x79, 0xdb, 0xb6, 0xf3, 0x8c, 0x60, 0x0c, 0xfa, 0x55, 0x2d, 0x6c, 0xcb, 0x75, 0x9b,
  0xb9, 0x01, 0x2c, 0x5b, 0x96, 0xed, 0xe9, 0xfe, 0x15, 0x8a, 0x92, 0x94, 0xf4, 0x7b, 0x6e, 0x56,
  0xda, 0x18, 0x94, 0x51, 0x45, 0x6c, 0x48, 0x51, 0x45, 0x14, 0x00, 0x51, 0x45, 0x14, 0x00, 0x52,
  0xa2, 0xee, 0x60, 0x28, 0x00, 0x93, 0x80, 0x32, 0x7d, 0xab, 0xaf, 0xd0, 0x7c, 0x25, 0x74, 0xd0,
  0x0b, 0xdb, 0xc8, 0x08, 0x8a, 0x55, 0x2b, 0x1a, 0xec, 0xdc, 0x7e, 0xa4, 0x0e, 0x94, 0xd2, 0xb8,
  0x9c, 0x92, 0xdc, 0xd7, 0xd1, 0xb4, 0x6b, 0xe9, 0x6c, 0x52, 0xf5, 0xee, 0xec, 0xad, 0xa0, 0x25,
  0x40, 0x80, 0xc8, 0x0b, 0xed, 0xf5, 0xe4, 0xf1, 0xf4, 0xfe, 0x55, 0x62, 0x7d, 0x23, 0x49, 0xb4,
  0x69, 0x56, 0xea, 0xe6, 0x39, 0x6d, 0xd9, 0x0e, 0xf5, 0x46, 0xe7, 0x9e, 0xb8, 0x19, 0x23, 0x8e,
  0xa3, 0x9e, 0xa2, 0xa2, 0xba, 0xd1, 0xac, 0x10, 0x2c, 0x76, 0xd0, 0x17, 0x40, 0x32, 0x24, 0x6b,
  0x6f, 0x2d, 0xf3, 0x8e, 0x46, 0x32, 0x72, 0x33, 0xdf, 0xde, 0x9f, 0x6d, 0xa2, 0x5a, 0xc8, 0xc9,
  0x1c, 0xa2, 0x70, 0x1b, 0x39, 0x55, 0xb6, 0xde, 0x47, 0xa7, 0x7a, 0x85, 0x18, 0xad, 0x52, 0xb0,
  0x9e, 0xff, 0x00, 0x17, 0xe0, 0x79, 0xbd, 0xc4, 0x42, 0x0b, 0x99, 0x62, 0x0d, 0xbc, 0x23, 0x15,
  0x0c, 0x3f, 0x88, 0x7a, 0xd4, 0x55, 0xdf, 0xf8, 0xbf, 0xc0, 0xf7, 0x51, 0x40, 0xfa, 0xe6, 0x9d,
  0x6d, 0x20, 0xb3, 0xc2, 0x89, 0xe1, 0x65, 0x2a, 0xd1, 0x37, 0x4c, 0x80, 0x7a, 0x82, 0x7f, 0x2a,
  0xe0, 0x7b, 0xfb, 0xd5, 0xb5, 0x61, 0xa9, 0x27, 0xb0, 0x94, 0x52, 0xd2, 0x52, 0x18, 0xa0, 0x12,
  0x40, 0x1d, 0x4d, 0x75, 0xde, 0x10, 0xf0, 0xfe, 0x83, 0xa8, 0x3c, 0xd7, 0x1a, 0xf6, 0xaf, 0x1d,
  0x95, 0xac, 0x38, 0xca, 0x9c, 0x97, 0x90, 0x9e, 0xca, 0xa3, 0x93, 0xf5, 0xae, 0x44, 0x54, 0xb9,
  0xc7, 0x20, 0xfe, 0x14, 0xd3, 0xb0, 0x9a, 0x6c, 0xf6, 0xa8, 0xee, 0xfe, 0x14, 0xe9, 0x10, 0x8f,
  0x26, 0xd2, 0xea, 0xe9, 0xb1, 0xd7, 0x68, 0x5c, 0xfe, 0x66, 0xb6, 0x34, 0x7f, 0x1d, 0xfc, 0x39,
  0x82, 0x35, 0x95, 0x60, 0x7b, 0x09, 0x32, 0x46, 0xc7, 0x47, 0x62, 0x07, 0xaf, 0xca, 0xa4, 0x73,
  0x5e, 0x00, 0x04, 0x8d, 0xc8, 0xc0, 0x1e, 0xe4, 0x0a, 0x18, 0x10, 0x7e, 0x7f, 0xbd, 0xf5, 0xaa,
  0xe7, 0x66, 0x7e, 0xc5, 0x3d, 0xd9, 0xed, 0xda, 0xb7, 0x8b, 0x7c, 0x2f, 0x7b, 0x74, 0x5b, 0x4f,
  0xbf, 0xb5, 0x8e, 0x3e, 0x99, 0x98, 0xca, 0xa4, 0x8f, 0xa0, 0x8c, 0xd4, 0x56, 0x9a, 0xce, 0x84,
  0x6e, 0x43, 0x4b, 0xe2, 0x6b, 0x38, 0x17, 0xb7, 0x94, 0x93, 0x39, 0x1f, 0x4f, 0x90, 0x57, 0x89,
  0x79, 0x8c, 0x0f, 0x5a, 0xb3, 0x0c, 0xac, 0x4a, 0xb9, 0xe4, 0x03, 0xc8, 0xa3, 0x99, 0x3e, 0x82,
  0xf6, 0x29, 0x6c, 0x7b, 0x3e, 0xa3, 0xe2, 0x3f, 0x0f, 0x42, 0xc0, 0x45, 0x7d, 0x1e, 0xa4, 0x84,
  0xe4, 0x97, 0x89, 0x87, 0xf3, 0x1c, 0xd5, 0x26, 0xd4, 0xfc, 0x01, 0x7c, 0x31, 0xac, 0x68, 0xca,
  0x88, 0xdc, 0x79, 0xd0, 0x46, 0x54, 0x83, 0xeb, 0xc1, 0x15, 0xe5, 0xf2, 0x5f, 0x49, 0x8f, 0x2e,
  0x18, 0xd5, 0x38, 0xce, 0xec, 0x64, 0xd5, 0x19, 0x66, 0x96, 0x46, 0xcc, 0x92, 0x33, 0x7d, 0x4d,
  0x53, 0x92, 0x5b, 0x0a, 0x34, 0xd9, 0xde, 0x78, 0xdf, 0xc0, 0x3a, 0x4e, 0x97, 0xa3, 0x47, 0xaf,
  0xf8, 0x77, 0x55, 0x4b, 0xcd, 0x36, 0x47, 0x08, 0x62, 0x66, 0xcb, 0xc6, 0x4f, 0x4f, 0xa8, 0xaf,
  0x39, 0xab, 0xcb, 0x79, 0x38, 0xb4, 0x36, 0x82, 0x69, 0x3c, 0x82, 0xdb, 0x8c, 0x7b, 0x8e, 0xd2,
  0x7d, 0x71, 0x54, 0xdc, 0x7c, 0xc6, 0xb3, 0x6e, 0xe6, 0xc9, 0x58, 0x11, 0x82, 0xb0, 0xc8, 0xc8,
  0xf4, 0xa9, 0x09, 0x04, 0xe1, 0x46, 0x39, 0xf4, 0xa8, 0x7b, 0xd5, 0x88, 0x57, 0x74, 0xc0, 0x7e,
  0x35, 0x0f, 0x42, 0xe2, 0xae, 0xd2, 0x18, 0x18, 0x73, 0x4a, 0x8c, 0xcc, 0x32, 0x15, 0x8f, 0xa9,
  0x14, 0x82, 0x26, 0x66, 0x3b, 0x54, 0x9c, 0x75, 0xc5, 0x5c, 0xb3, 0xb5, 0x73, 0x11, 0xc8, 0x2b,
  0x93, 0xd3, 0xd6, 0xa5, 0xce, 0xca, 0xe6, 0xd1, 0xa7, 0xcd, 0x2b, 0x15, 0x37, 0xed, 0x7d, 0xf8,
  0x19, 0x07, 0xb8, 0xcd, 0x4f, 0x10, 0xfd, 0xcb, 0x3e, 0xde, 0x09, 0xec, 0x31, 0x5a, 0x0f, 0xe1,
  0xdb, 0x87, 0x86, 0x4b, 0xa4, 0xd9, 0xe4, 0xc5, 0x86, 0x7c, 0xb8, 0x07, 0xf0, 0xf5, 0xa6, 0xdb,
  0x69, 0xcc, 0xc8, 0xf2, 0x1c, 0x08, 0xd9, 0xd5, 0x55, 0x73, 0xeb, 0xff, 0x00, 0xea, 0xa9, 0x8d,
  0x78, 0x3d, 0x8b, 0x9e, 0x0e, 0xa4, 0x5e, 0xa8, 0xa8, 0x1f, 0x13, 0x0c, 0x83, 0xf7, 0x2a, 0xb1,
  0x9b, 0x91, 0xc3, 0x71, 0x5a, 0x93, 0xda, 0x15, 0x99, 0x40, 0x04, 0x90, 0x87, 0x8c, 0x56, 0x53,
  0x44, 0x54, 0x9d, 0xca, 0x47, 0xd4, 0x1a, 0xd3, 0x9e, 0xf1, 0xb9, 0x93, 0xa5, 0xcb, 0x2b, 0x12,
  0x16, 0xf3, 0x24, 0x27, 0x03, 0x92, 0x48, 0xe3, 0x15, 0x03, 0x8f, 0x9c, 0xd4, 0xd2, 0x95, 0x57,
  0x40, 0xa7, 0xb7, 0xf5, 0xa8, 0x5f, 0xef, 0x9a, 0x68, 0xc9, 0xab, 0x31, 0x95, 0x6a, 0xdf, 0x99,
  0x90, 0xd5, 0x43, 0xda, 0xad, 0x5b, 0x7f, 0xad, 0x1f, 0xee, 0x1a, 0x52, 0xd9, 0x97, 0x4f, 0xe2,
  0x43, 0xd6, 0x3c, 0xcd, 0x9e, 0xdd, 0x87, 0xa9, 0xc5, 0x75, 0x1a, 0x0e, 0x9f, 0x0f, 0x9b, 0x13,
  0xea, 0x1b, 0xb6, 0xe0, 0xb3, 0x22, 0xfe, 0x1d, 0x7f, 0x31, 0x58, 0x7a, 0x6a, 0x2b, 0x5c, 0xa3,
  0x38, 0xce, 0xd1, 0xf2, 0x8f, 0x72, 0x6b, 0xa2, 0xb2, 0x72, 0xc8, 0xdc, 0xf0, 0xaa, 0x17, 0x39,
  0xea, 0x73, 0x92, 0x7f, 0x95, 0x79, 0xf8, 0x89, 0x3b, 0x72, 0xa3, 0xda, 0xc1, 0x52, 0x8d, 0xf9,
  0x99, 0xeb, 0x1e, 0x0e, 0xd3, 0xb4, 0x6b, 0x99, 0x26, 0x69, 0xec, 0xd0, 0x44, 0xab, 0x94, 0x45,
  0x72, 0x99, 0x6c, 0x7b, 0x1a, 0x5f, 0x14, 0xe8, 0xb6, 0xba, 0x56, 0x9e, 0x92, 0xf9, 0x3b, 0x96,
  0x76, 0x0e, 0xb1, 0x4b, 0xf3, 0x05, 0x5d, 0xc0, 0x74, 0x3d, 0x32, 0x09, 0xfa, 0x71, 0x4f, 0xf8,
  0x6b, 0x66, 0xda, 0x8e, 0xa2, 0xf2, 0x4b, 0xbb, 0xec, 0xd1, 0xa0, 0xc2, 0x37, 0xf1, 0x74, 0xfe,
  0x7d, 0x7e, 0x98, 0xf5, 0x35, 0xb5, 0xf1, 0x44, 0x66, 0x18, 0x7d, 0x36, 0x8f, 0xfd, 0x0c, 0x57,
  0x0c, 0x28, 0x2e, 0x47, 0x37, 0xdf, 0xe7, 0xf7, 0x9d, 0x93, 0xad, 0xfe, 0xd4, 0xa9, 0xa7, 0xa5,
  0xb6, 0xe8, 0x78, 0xc6, 0xb1, 0xa5, 0xdb, 0x99, 0x96, 0x7b, 0x06, 0x28, 0x19, 0x4f, 0xc9, 0xb7,
  0x8c, 0xfa, 0x66, 0xb8, 0xab, 0xa7, 0x6f, 0x35, 0xd4, 0x93, 0x81, 0x81, 0x83, 0x5d, 0x6d, 0xe5,
  0xd3, 0xac, 0xdf, 0xbb, 0x1b, 0xe2, 0x08, 0x48, 0x3d, 0x8b, 0x1e, 0x01, 0xff, 0x00, 0x3e, 0xf5,
  0xcb, 0x5e, 0x26, 0xe9, 0xb7, 0x9f, 0xbc, 0xc3, 0xe6, 0xe3, 0xbe, 0x6b, 0xbf, 0x0e, 0xe4, 0xa1,
  0x69, 0x3b, 0x9c, 0x58, 0xc8, 0x43, 0x9e, 0xf0, 0x56, 0x33, 0x67, 0x3f, 0xbe, 0x5e, 0x3b, 0x53,
  0x1b, 0xef, 0x1a, 0x9a, 0xe5, 0x36, 0xcc, 0x0e, 0x38, 0xc5, 0x42, 0xdf, 0x78, 0xd7, 0xa0, 0xb6,
  0x3c, 0x49, 0x6e, 0x46, 0xdd, 0xaa, 0xe5, 0xa7, 0xfa, 0xdc, 0xff, 0x00, 0xb0, 0x7f, 0x91, 0xaa,
  0x67, 0xa7, 0xe3, 0x57, 0x2d, 0x3f, 0xd6, 0x7f, 0xc0, 0x4f, 0xf2, 0x35, 0x33, 0xd9, 0x97, 0x4b,
  0xe2, 0x45, 0xeb, 0x56, 0x08, 0xd9, 0x3f, 0xdc, 0x27, 0xf1, 0xe6, 0xba, 0x2d, 0x21, 0x05, 0xcc,
  0x11, 0xe0, 0xa0, 0x6c, 0x02, 0x50, 0x8f, 0xbe, 0x72, 0x3b, 0x7e, 0x19, 0xc5, 0x60, 0x59, 0x02,
  0xd7, 0x0a, 0x17, 0x19, 0xf2, 0xcf, 0x51, 0x9c, 0x57, 0x45, 0x62, 0x91, 0xc3, 0x1e, 0x17, 0x6f,
  0x98, 0x31, 0xb9, 0x72, 0x03, 0x0f, 0xab, 0x74, 0x1f, 0x4a, 0xf3, 0x71, 0x0f, 0x43, 0xdf, 0xc1,
  0xc7, 0x54, 0xfa, 0x1e, 0xd5, 0xf0, 0xe2, 0x7f, 0x29, 0xe5, 0x0b, 0x6f, 0x70, 0xe3, 0x6f, 0x1f,
  0xbb, 0xc1, 0xeb, 0xd4, 0xe7, 0x15, 0x07, 0xc4, 0xeb, 0xdb, 0x89, 0x9e, 0x18, 0x92, 0xca, 0xe1,
  0x23, 0x31, 0xfc, 0xee, 0xc8, 0x0e, 0x7e, 0x6e, 0x83, 0x04, 0xf5, 0xe7, 0x9a, 0x83, 0xe1, 0x86,
  0xa5, 0x66, 0xd7, 0xd7, 0x68, 0x16, 0xec, 0xce, 0x89, 0xca, 0x00, 0xee, 0x3b, 0x74, 0xc7, 0x15,
  0x5b, 0xe2, 0x8e, 0xac, 0x16, 0xf2, 0x33, 0x25, 0xad, 0xdc, 0x3b, 0x21, 0xdd, 0xf3, 0x97, 0x19,
  0x19, 0xf4, 0xfb, 0xb9, 0xfc, 0x4d, 0x72, 0x45, 0xcb, 0xd9, 0x72, 0xf9, 0xfe, 0x85, 0xc9, 0x2f,
  0xae, 0xf3, 0x74, 0xb6, 0xe7, 0x93, 0x6a, 0xb2, 0x32, 0x4d, 0x14, 0x19, 0x45, 0xe0, 0xb3, 0x0c,
  0xf2, 0x0f, 0x6c, 0x8e, 0xdc, 0x7f, 0x3a, 0xc2, 0x99, 0xbe, 0x73, 0x83, 0xd4, 0x03, 0xf8, 0x56,
  0xe4, 0xb6, 0xa6, 0x69, 0x44, 0xd2, 0xb2, 0xee, 0x91, 0x4b, 0x32, 0x00, 0x01, 0xc9, 0xe9, 0x58,
  0x37, 0x2a, 0x52, 0x77, 0xcf, 0x03, 0x03, 0x15, 0xe8, 0x52, 0xb7, 0x25, 0x91, 0xcb, 0x88, 0x6f,
  0x9d, 0xb6, 0x52, 0xbb, 0x27, 0xcd, 0xc7, 0x6c, 0x66, 0xab, 0x37, 0xde, 0x35, 0x3d, 0xd1, 0xcd,
  0xc1, 0xfa, 0x0a, 0x84, 0x82, 0x4d, 0x77, 0x2d, 0x8f, 0x16, 0x7b, 0xb2, 0x33, 0x9d, 0xb5, 0x6e,
  0xcc, 0xfe, 0xf5, 0xb3, 0xfd, 0xc6, 0xff, 0x00, 0xd0, 0x4d, 0x53, 0x24, 0xed, 0xc7, 0xa9, 0xa9,
  0xe0, 0x38, 0x2d, 0xfe, 0xe9, 0xfe, 0x54, 0xa7, 0xb3, 0x2a, 0x9f, 0xc4, 0x8d, 0xed, 0x21, 0x96,
  0x18, 0x26, 0xb8, 0x62, 0x41, 0x2b, 0xb1, 0x71, 0xeb, 0xd7, 0x35, 0x73, 0x4d, 0x88, 0xba, 0x03,
  0x26, 0xf2, 0x01, 0x1f, 0x75, 0x72, 0x7b, 0x7e, 0x5f, 0x5a, 0xa5, 0xa4, 0x05, 0xb9, 0xb2, 0xb8,
  0xb5, 0x38, 0xf3, 0x54, 0x09, 0x63, 0xe3, 0xa9, 0x1d, 0x47, 0xe5, 0xfc, 0xab, 0x76, 0xce, 0x30,
  0x6d, 0x96, 0x64, 0xc1, 0x0c, 0xc3, 0x77, 0x1d, 0x1a, 0xbc, 0xba, 0xd2, 0xb3, 0x68, 0xfa, 0x1c,
  0x2c, 0x39, 0xa3, 0x17, 0xd8, 0xf6, 0x4f, 0x87, 0x31, 0xda, 0x11, 0x2a, 0x1b, 0x6b, 0x90, 0x02,
  0xf0, 0x56, 0x27, 0x5e, 0xfe, 0xa2, 0xb3, 0x3e, 0x27, 0x9b, 0x49, 0x75, 0x3b, 0x5d, 0x3a, 0x18,
  0xe6, 0x19, 0x8c, 0x4d, 0x3f, 0x99, 0xbf, 0x3b, 0x43, 0x71, 0xf7, 0xbb, 0x13, 0xfc, 0xab, 0x7b,
  0xe1, 0x84, 0x81, 0x85, 0xc8, 0xca, 0xf0, 0xbd, 0xb3, 0xeb, 0x5c, 0x97, 0x8c, 0xaf, 0x12, 0xfa,
  0xfa, 0xff, 0x00, 0x52, 0xe1, 0x85, 0xc9, 0x58, 0xe3, 0xc9, 0xfb, 0xb1, 0xa3, 0x00, 0xa3, 0xf1,
  0xc1, 0x6f, 0xc4, 0x57, 0x3b, 0xe5, 0x85, 0x24, 0xba, 0xb6, 0x5f, 0x2b, 0x96, 0x36, 0x5d, 0x92,
  0xf9, 0x1e, 0x6b, 0xaa, 0xc3, 0x8b, 0xd5, 0x8e, 0x2d, 0xc1, 0x42, 0x93, 0x82, 0x30, 0x33, 0xea,
  0x2b, 0x1a, 0xfc, 0xee, 0x50, 0xe3, 0xa0, 0xc2, 0xe7, 0xd4, 0xf1, 0xfe, 0x35, 0xbf, 0x74, 0x02,
  0x4e, 0xb7, 0x4d, 0x80, 0x00, 0x2a, 0xbd, 0x79, 0x35, 0x85, 0xa8, 0xb2, 0x2d, 0xba, 0xc2, 0x31,
  0xbc, 0x61, 0xdf, 0x1d, 0x89, 0x23, 0x8f, 0xc8, 0x0a, 0xec, 0xa2, 0xee, 0x92, 0x39, 0xf1, 0x4a,
  0xce, 0x4d, 0xf9, 0x18, 0xd7, 0x3f, 0xeb, 0xff, 0x00, 0x01, 0x50, 0x9e, 0xb5, 0x2c, 0xc7, 0x32,
  0x8f, 0xa0, 0xa8, 0xd8, 0x7c, 0xc6, 0xbd, 0x15, 0xb1, 0xe0, 0xcf, 0x72, 0x3e, 0xd5, 0x34, 0x4d,
  0xb5, 0xfe, 0xa0, 0x8a, 0x84, 0x54, 0x80, 0xed, 0xc1, 0xa1, 0xec, 0x11, 0x76, 0x68, 0xb5, 0x14,
  0xed, 0x04, 0xa5, 0xa3, 0x93, 0x63, 0x87, 0xc8, 0x23, 0xa8, 0xf4, 0x35, 0xd9, 0x68, 0xda, 0xed,
  0xbc, 0xdc, 0xdc, 0x6d, 0x86, 0x77, 0x21, 0x5c, 0x94, 0xdd, 0x14, 0x9e, 0xe7, 0x1c, 0xa9, 0xf7,
  0x15, 0xc2, 0x2b, 0xc6, 0xcd, 0x99, 0x37, 0x7b, 0xe2, 0xae, 0x45, 0x70, 0x20, 0x0c, 0xa8, 0xc5,
  0x90, 0x37, 0xca, 0x58, 0x73, 0x8a, 0xe3, 0xaf, 0x41, 0x54, 0x8d, 0x9e, 0xe7, 0xa7, 0x85, 0xc5,
  0x4a, 0x94, 0xae, 0x9e, 0x87, 0xbc, 0xe9, 0x3a, 0xe4, 0x3a, 0x76, 0x95, 0x35, 0x9c, 0x33, 0x79,
  0x73, 0xea, 0x2c, 0xb6, 0xb1, 0x4c, 0x92, 0xab, 0xa4, 0x7b, 0x8f, 0xcc, 0xd9, 0xe0, 0x8c, 0x2e,
  0x71, 0x91, 0xd7, 0x15, 0x3f, 0x8d, 0x57, 0x4c, 0x68, 0xad, 0xa2, 0xb4, 0x93, 0x65, 0xbd, 0xba,
  0xa2, 0xfe, 0xf1, 0x95, 0x01, 0xc1, 0x19, 0xc9, 0x27, 0x39, 0x3f, 0x4a, 0xf9, 0xee, 0xe7, 0x50,
  0x92, 0xe6, 0x54, 0xde, 0x7e, 0x45, 0x3c, 0x01, 0xfa, 0xd5, 0xa5, 0xd7, 0x2f, 0x64, 0x22, 0x39,
  0x67, 0x69, 0x22, 0xc8, 0xc6, 0xf3, 0x93, 0x81, 0xc0, 0x19, 0xf4, 0x1e, 0x95, 0xc7, 0xf5, 0x0a,
  0xb6, 0x5e, 0xf2, 0xfb, 0xb5, 0xfc, 0xce, 0xaf, 0xed, 0x0a, 0x5e, 0xd5, 0xce, 0xcc, 0xea, 0x35,
  0x7d, 0x56, 0xcc, 0x5e, 0x28, 0xb6, 0x4f, 0x32, 0x55, 0xce, 0xd3, 0x8f, 0xdd, 0xa7, 0xbf, 0x3f,
  0x78, 0xd7, 0x21, 0xe6, 0x3c, 0xbf, 0x69, 0x91, 0xd8, 0x92, 0x70, 0x49, 0x3d, 0xf9, 0xab, 0x4b,
  0x2f, 0x9f, 0x7a, 0xbb, 0x8e, 0x17, 0x69, 0x3c, 0x0f, 0x6a, 0xaa, 0x81, 0x56, 0xd6, 0x7c, 0x64,
  0xf2, 0x3a, 0xd7, 0xa1, 0x46, 0x82, 0xa7, 0x0b, 0x23, 0x83, 0x15, 0x8a, 0x95, 0x59, 0xdd, 0xec,
  0x55, 0x73, 0x99, 0x58, 0xfb, 0xd3, 0x5c, 0x7c, 0xc6, 0x8c, 0xfc, 0xd9, 0xa1, 0xbe, 0xf1, 0xae,
  0x95, 0xb1, 0xc1, 0x2d, 0xc8, 0xaa, 0x52, 0x3e, 0x50, 0x4b, 0x0a, 0x88, 0x53, 0xdb, 0xee, 0xd0,
  0xc1, 0x30, 0x58, 0x8b, 0x36, 0x15, 0x97, 0x26, 0xa5, 0x78, 0xdd, 0x06, 0x09, 0x51, 0x50, 0x31,
  0x21, 0xc1, 0x1d, 0x85, 0x3d, 0x8b, 0x3e, 0x2a, 0x6c, 0x57, 0x32, 0x42, 0x45, 0x0b, 0x4b, 0x26,
  0xc0, 0x40, 0xf7, 0x35, 0x2c, 0x96, 0xaf, 0x6e, 0xca, 0x0b, 0x29, 0xcf, 0xa1, 0xa8, 0x10, 0x80,
  0xf9, 0x39, 0xe0, 0x7e, 0xb4, 0xf5, 0x90, 0xc9, 0x29, 0xdd, 0xf8, 0x55, 0x13, 0xd4, 0xb9, 0x6e,
  0x59, 0x6e, 0xd3, 0xa1, 0x38, 0xc6, 0x29, 0x18, 0x3c, 0x70, 0xcc, 0x8e, 0xbb, 0x7a, 0x1c, 0x1f,
  0xad, 0x16, 0x59, 0x6b, 0xf8, 0xc6, 0xdc, 0xd5, 0xbb, 0xd4, 0xdb, 0x1d, 0xc6, 0x50, 0xa9, 0xdc,
  0xb8, 0x04, 0xe6, 0xa9, 0x47, 0xdd, 0xb9, 0x12, 0x9a, 0xbd, 0x8c, 0xa4, 0x8d, 0xd9, 0x49, 0x18,
  0xc0, 0xa4, 0x6f, 0xbc, 0x6a, 0x45, 0x27, 0x81, 0xda, 0x98, 0xff, 0x00, 0x7c, 0xd4, 0x94, 0xd9,
  0x1a, 0x29, 0x72, 0x40, 0xa9, 0x36, 0x64, 0x85, 0x24, 0x0c, 0xf7, 0x35, 0x12, 0x31, 0x53, 0xf5,
  0x15, 0x20, 0x90, 0xf0, 0x36, 0x8e, 0xbd, 0xe8, 0x02, 0x32, 0x09, 0x7c, 0x60, 0xd4, 0xd1, 0x6e,
  0x27, 0x91, 0xd2, 0xa5, 0x5d, 0xac, 0xe4, 0xe0, 0x00, 0x07, 0x00, 0x52, 0xa2, 0xee, 0x18, 0x52,
  0x0f, 0x7a, 0x57, 0x1d, 0x8a, 0xcc, 0x8d, 0x92, 0x76, 0xf1, 0xda, 0x9a, 0xa1, 0x83, 0x13, 0x8e,
  0x2a, 0xf2, 0x29, 0x0e, 0xc1, 0xb1, 0x82, 0x29, 0x42, 0xaa, 0xca, 0xa7, 0xe5, 0x2a, 0x46, 0x08,
  0xa6, 0x26, 0xcd, 0x2f, 0x09, 0x59, 0x47, 0x7b, 0xae, 0xc7, 0x1c, 0x8d, 0x83, 0x83, 0xb4, 0x12,
  0x00, 0x27, 0x07, 0x82, 0x4f, 0x4a, 0xab, 0xab, 0xdd, 0xcb, 0x73, 0x79, 0x2c, 0x82, 0x1f, 0x2a,
  0x32, 0x40, 0xd9, 0x9c, 0xf2, 0x38, 0xeb, 0x52, 0xda, 0x20, 0x37, 0x48, 0x23, 0x9d, 0x6d, 0xf9,
  0x00, 0xbb, 0x70, 0x07, 0xbd, 0x43, 0xa8, 0xaa, 0x96, 0x0c, 0x8c, 0xcc, 0x85, 0x71, 0xbb, 0xae,
  0x48, 0xeb, 0x5a, 0x39, 0x7b, 0x96, 0x32, 0x4a, 0xf3, 0xb9, 0x40, 0x1f, 0x98, 0x54, 0x6e, 0x7e,
  0x73, 0x4a, 0x09, 0xcd, 0x23, 0xfd, 0xf3, 0x59, 0xa3, 0x56, 0x43, 0x52, 0x21, 0x0c, 0x79, 0xc6,
  0x7d, 0xea, 0x3a, 0x4a, 0x06, 0x5a, 0x45, 0xdb, 0x90, 0x57, 0xf2, 0x34, 0x98, 0xf9, 0x78, 0x1c,
  0xd4, 0x09, 0xd0, 0xfd, 0x69, 0xea, 0x4f, 0x90, 0xff, 0x00, 0x51, 0x48, 0x77, 0x24, 0xf9, 0xbd,
  0x09, 0x34, 0x00, 0xc1, 0x86, 0xe0, 0x47, 0xd6, 0x9a, 0xa4, 0xf9, 0x2c, 0x73, 0xcf, 0x14, 0xa8,
  0xc4, 0xc6, 0xe4, 0x92, 0x70, 0x38, 0xa0, 0x57, 0x25, 0x6f, 0xbb, 0xf7, 0x4e, 0x7d, 0x73, 0x4d,
  0x76, 0x38, 0xdb, 0xce, 0x3a, 0xf5, 0xa8, 0x0b, 0x13, 0x1b, 0xe4, 0x9e, 0x31, 0x4b, 0xfc, 0x0b,
  0xf4, 0xa0, 0x07, 0xee, 0x03, 0xeb, 0x4c, 0xa2, 0x92, 0x98, 0x8f, 0xff, 0xd9
};
