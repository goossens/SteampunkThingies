//	Steampunk Thingies
//	Copyright (c) 2022-2024 Johan A. Goossens. All rights reserved.
//
//	This work is licensed under the terms of the MIT license.
//	For a copy, see <https://opensource.org/licenses/MIT>.


#pragma once


//
//	Include files
//

#include <TFT_eSPI.h>
#include <AiEsp32RotaryEncoder.h>

#include "AppContext.h"


//
//	BaseApp
//

class BaseApp {
public:
	// destructure
	virtual ~BaseApp() {}

	// run one cycle of this app
	void run(AppContext& context) {
		if (!isSetup) {
			setup(context);
			isSetup = true;
		}

		loop(context);
	}

	// these methods can be overriden by subclasses
	virtual void setup(AppContext& context) {}
	virtual void loop(AppContext& context) {}

	virtual void onClick(AppContext& context) {}
	virtual void onRotate(AppContext& context, int delta) {}

private:
	// properties
	bool isSetup = false;
};
