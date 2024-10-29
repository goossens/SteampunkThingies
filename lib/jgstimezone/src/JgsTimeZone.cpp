//	Steampunk Thingies
//	Copyright (c) 2022-2024 Johan A. Goossens. All rights reserved.
//
//	This work is licensed under the terms of the MIT license.
//	For a copy, see <https://opensource.org/licenses/MIT>.


//
//	Include files
//

#include <Arduino.h>
#include <EEPROM.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include <ezTime.h>
#include <Arduino_JSON.h>

#include "JgsLog.h"
#include "JgsTimeZone.h"


//
//	Globals
//

static constexpr const char* url = "https://ipapi.co/json/";

static constexpr const char* certificate = \
	"-----BEGIN CERTIFICATE-----\n" \
	"MIICGzCCAaGgAwIBAgIQQdKd0XLq7qeAwSxs6S+HUjAKBggqhkjOPQQDAzBPMQsw\n" \
	"CQYDVQQGEwJVUzEpMCcGA1UEChMgSW50ZXJuZXQgU2VjdXJpdHkgUmVzZWFyY2gg\n" \
	"R3JvdXAxFTATBgNVBAMTDElTUkcgUm9vdCBYMjAeFw0yMDA5MDQwMDAwMDBaFw00\n" \
	"MDA5MTcxNjAwMDBaME8xCzAJBgNVBAYTAlVTMSkwJwYDVQQKEyBJbnRlcm5ldCBT\n" \
	"ZWN1cml0eSBSZXNlYXJjaCBHcm91cDEVMBMGA1UEAxMMSVNSRyBSb290IFgyMHYw\n" \
	"EAYHKoZIzj0CAQYFK4EEACIDYgAEzZvVn4CDCuwJSvMWSj5cz3es3mcFDR0HttwW\n" \
	"+1qLFNvicWDEukWVEYmO6gbf9yoWHKS5xcUy4APgHoIYOIvXRdgKam7mAHf7AlF9\n" \
	"ItgKbppbd9/w+kHsOdx1ymgHDB/qo0IwQDAOBgNVHQ8BAf8EBAMCAQYwDwYDVR0T\n" \
	"AQH/BAUwAwEB/zAdBgNVHQ4EFgQUfEKWrt5LSDv6kviejM9ti6lyN5UwCgYIKoZI\n" \
	"zj0EAwMDaAAwZQIwe3lORlCEwkSHRhtFcP9Ymd70/aTSVaYgLXTWNLxBo1BfASdW\n" \
	"tL4ndQavEi51mI38AjEAi/V3bNTIZargCyzuFJ0nN6T5U6VR5CmD1/iQMVtCnwr1\n" \
	"/q4AaOeMSQ+2b1tbFfLn\n" \
	"-----END CERTIFICATE-----\n";

static Timezone localTime;


//
//	JgsTimeZone::init
//

void JgsTimeZone::init(bool forceReload, std::function<void(const char*, const char*)> status) {
#ifndef DISABLE_LOGGING
	setDebug(INFO, Serial);
#endif

	status("Getting Time...", "");
	waitForSync();

	if (forceReload) {
		status("Getting Location...", "");
		loadFromGeoLocation();
		storeData();

	} else {
		retrieveData();
	}

	address = city + ", " + state + " " + zip;
	localTime.setPosix(timezone);

	JgsLog::print("\n");
	JgsLog::print("Location: %s\n", address.c_str());
	JgsLog::print("Timezone: %s\n", timezone.c_str());
	JgsLog::print("Time: %s\n", localTime.dateTime().c_str());
}

//
//	JgsTimeZone::processEvents
//

void JgsTimeZone::processEvents() {
	events();
}


//
//	JgsTimeZone::get...
//

int JgsTimeZone::getYear() { return localTime.year(); }
int JgsTimeZone::getMonth() { return localTime.month(); }
int JgsTimeZone::getDay() { return localTime.day(); }
int JgsTimeZone::getWeekDay() { return localTime.weekday(); }
int JgsTimeZone::getHours() { return localTime.hour(); }
int JgsTimeZone::getMinutes() { return localTime.minute(); }
int JgsTimeZone::getSeconds() { return localTime.second(); }
String JgsTimeZone::getDateTime() { return localTime.dateTime("D, d M Y H:i:s T"); }


//
//	JgsTimeZone::loadFromGeoLocation
//

void JgsTimeZone::loadFromGeoLocation() {
	WiFiClientSecure client;
	client.setCACert(certificate);
	HTTPClient https;

	https.begin(client, url);
	int httpResponseCode = https.GET();
	String geoDataJSON;

	if (httpResponseCode > 0) {
		geoDataJSON = https.getString();

	} else {
		JgsLog::print("Failed to access [%s], error [%s]\n", url, https.errorToString(httpResponseCode).c_str());
		JgsLog::print("restarting...\n");
		delay(2000);
		ESP.restart();
	}

	https.end();

	JSONVar geodata = JSON.parse(geoDataJSON);
	String olson = geodata["timezone"];
	String ct = geodata["city"];
	String rc = geodata["region_code"];
	String pt = geodata["postal"];
	String cn = geodata["country_name"];

	city = ct;
	state = rc;
	zip = pt;
	country = cn;

	int retry = 5;

	while (!localTime.setLocation(olson) && retry >= 0) {
		JgsLog::print("Error setting location [%s]: %s\n", olson.c_str() + errorString());
		delay(5000);
		retry--;
	}

	if (retry < 0) {
		JgsLog::print("Can't get location, restarting...\n");
		delay(2000);
		ESP.restart();
	}

	timezone = localTime.getPosix();
}


//
//	JgsTimeZone::storeData
//

void JgsTimeZone::storeData() {
	EEPROM.begin(512);
	EEPROM.writeString(0, timezone);
	EEPROM.writeString(32, city);
	EEPROM.writeString(64, state);
	EEPROM.writeString(96, zip);
	EEPROM.writeString(128, country);
	EEPROM.commit();
	EEPROM.end();
}


//
//	JgsTimeZone::retrieveData
//

void JgsTimeZone::retrieveData() {
	EEPROM.begin(512);
	timezone = EEPROM.readString(0);
	city = EEPROM.readString(32);
	state = EEPROM.readString(64);
	zip = EEPROM.readString(96);
	country = EEPROM.readString(128);
	EEPROM.end();
}
