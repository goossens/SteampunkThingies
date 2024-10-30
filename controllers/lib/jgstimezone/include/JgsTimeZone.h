//	Steampunk Thingies
//	Copyright (c) 2022-2024 Johan A. Goossens. All rights reserved.
//
//	This work is licensed under the terms of the MIT license.
//	For a copy, see <https://opensource.org/licenses/MIT>.


#pragma once


//
//	Include files
//

#include <functional>


//
//	JgsTimeZone
//

class JgsTimeZone {
public:
	// initialize
	void init(bool forceReload, std::function<void(const char*, const char*)> status);

	// process events
	void processEvents();

	// get local time
	int getYear();
	int getMonth();
	int getDay();
	int getWeekDay();
	int getHours();
	int getMinutes();
	int getSeconds();
	String getDateTime();

	// get location information
	String& getTimeZone() { return timezone; }
	String& getCity() { return city; }
	String& getState() { return state; }
	String& getZip() { return zip; }
	String& getCountry() { return country; }
	String& getAddress() { return address; }

private:
	// properties
	String timezone;
	String city;
	String state;
	String zip;
	String country;
	String address;

	// determine data based on geolocation
	void loadFromGeoLocation();

	// store/retrieve data from flash memory
	void storeData();
	void retrieveData();
};
