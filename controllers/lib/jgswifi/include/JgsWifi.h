//	Steampunk Thingies
//	Copyright (c) 2022-2025 Johan A. Goossens. All rights reserved.
//
//	This work is licensed under the terms of the MIT license.
//	For a copy, see <https://opensource.org/licenses/MIT>.


#pragma once


//
//	Include files
//

#include <functional>


//
//	JgsWifi
//

class JgsWifi {
public:
	// initialize wifi network
	void init(std::function<void(const char*, const char*)> status);

	// see if wify is still connected
	bool isConnected();

	// try to reconnect to wifi or restart if we continue to fail
	void reconnect(std::function<void(const char*, const char*)> status);

	// was wifi network changed
	inline bool isConfigChanged() { return configChanged; }

	// get wifi connection details
	inline String& getSSID() { return ssid; }
	inline String& getIP() { return ip; }
	inline String& getMacAddress() { return macAddress; }
	int getRSSI();

	// reset wifi settings
	void reset();

private:
	// has network configuration changed
	bool configChanged = false;

	// current network connection
	String ssid;
	String ip;
	String macAddress;
};
