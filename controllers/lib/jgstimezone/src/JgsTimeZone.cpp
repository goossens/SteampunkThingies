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

// certificate downloaded with cirtificate.sh script
static constexpr const char* certificate = \
	"-----BEGIN CERTIFICATE-----\n" \
	"MIIDejCCAmKgAwIBAgIQf+UwvzMTQ77dghYQST2KGzANBgkqhkiG9w0BAQsFADBX\n" \
	"MQswCQYDVQQGEwJCRTEZMBcGA1UEChMQR2xvYmFsU2lnbiBudi1zYTEQMA4GA1UE\n" \
	"CxMHUm9vdCBDQTEbMBkGA1UEAxMSR2xvYmFsU2lnbiBSb290IENBMB4XDTIzMTEx\n" \
	"NTAzNDMyMVoXDTI4MDEyODAwMDA0MlowRzELMAkGA1UEBhMCVVMxIjAgBgNVBAoT\n" \
	"GUdvb2dsZSBUcnVzdCBTZXJ2aWNlcyBMTEMxFDASBgNVBAMTC0dUUyBSb290IFI0\n" \
	"MHYwEAYHKoZIzj0CAQYFK4EEACIDYgAE83Rzp2iLYK5DuDXFgTB7S0md+8Fhzube\n" \
	"Rr1r1WEYNa5A3XP3iZEwWus87oV8okB2O6nGuEfYKueSkWpz6bFyOZ8pn6KY019e\n" \
	"WIZlD6GEZQbR3IvJx3PIjGov5cSr0R2Ko4H/MIH8MA4GA1UdDwEB/wQEAwIBhjAd\n" \
	"BgNVHSUEFjAUBggrBgEFBQcDAQYIKwYBBQUHAwIwDwYDVR0TAQH/BAUwAwEB/zAd\n" \
	"BgNVHQ4EFgQUgEzW63T/STaj1dj8tT7FavCUHYwwHwYDVR0jBBgwFoAUYHtmGkUN\n" \
	"l8qJUC99BM00qP/8/UswNgYIKwYBBQUHAQEEKjAoMCYGCCsGAQUFBzAChhpodHRw\n" \
	"Oi8vaS5wa2kuZ29vZy9nc3IxLmNydDAtBgNVHR8EJjAkMCKgIKAehhxodHRwOi8v\n" \
	"Yy5wa2kuZ29vZy9yL2dzcjEuY3JsMBMGA1UdIAQMMAowCAYGZ4EMAQIBMA0GCSqG\n" \
	"SIb3DQEBCwUAA4IBAQAYQrsPBtYDh5bjP2OBDwmkoWhIDDkic574y04tfzHpn+cJ\n" \
	"odI2D4SseesQ6bDrarZ7C30ddLibZatoKiws3UL9xnELz4ct92vID24FfVbiI1hY\n" \
	"+SW6FoVHkNeWIP0GCbaM4C6uVdF5dTUsMVs/ZbzNnIdCp5Gxmx5ejvEau8otR/Cs\n" \
	"kGN+hr/W5GvT1tMBjgWKZ1i4//emhA1JG1BbPzoLJQvyEotc03lXjTaCzv8mEbep\n" \
	"8RqZ7a2CPsgRbuvTPBwcOMBBmuFeU88+FSBX6+7iP0il8b4Z0QFqIwwMHfs/L6K1\n" \
	"vepuoxtGzi4CZ68zJpiq1UvSqTbFJjtbD4seiMHl\n" \
	"-----END CERTIFICATE-----\n";

static Timezone localTime;


//
//	JgsTimeZone::init
//

void JgsTimeZone::init(bool forceReload, std::function<void(const char*, const char*)> status) {
#if ENABLE_LOGGING
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
