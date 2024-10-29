//	Steampunk Thingies
//	Copyright (c) 2022-2024 Johan A. Goossens. All rights reserved.
//
//	This work is licensed under the terms of the MIT license.
//	For a copy, see <https://opensource.org/licenses/MIT>.


//
//	Include files
//

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiManager.h>

#include "JgsLog.h"
#include "JgsWifi.h"


//
//	wiFiEvent
//

static void wiFiEvent(WiFiEvent_t event) {
	switch (event) {
		case ARDUINO_EVENT_WIFI_READY: JgsLog::print("WiFi interface ready\n"); break;
		case ARDUINO_EVENT_WIFI_SCAN_DONE: JgsLog::print("Completed scan for access points\n"); break;
		case ARDUINO_EVENT_WIFI_STA_START: JgsLog::print("WiFi client started\n"); break;
		case ARDUINO_EVENT_WIFI_STA_STOP: JgsLog::print("WiFi clients stopped\n"); break;
		case ARDUINO_EVENT_WIFI_STA_CONNECTED: JgsLog::print("Connected to access point\n"); break;
		case ARDUINO_EVENT_WIFI_STA_DISCONNECTED: JgsLog::print("Disconnected from WiFi access point\n"); break;
		case ARDUINO_EVENT_WIFI_STA_AUTHMODE_CHANGE: JgsLog::print("Authentication mode of access point has changed\n"); break;
		case ARDUINO_EVENT_WIFI_STA_GOT_IP: JgsLog::print("Obtained IP address: %s\n", WiFi.localIP()); break;
		case ARDUINO_EVENT_WIFI_STA_LOST_IP: JgsLog::print("Lost IP address and IP address is reset to 0\n"); break;
		case ARDUINO_EVENT_WPS_ER_SUCCESS: JgsLog::print("WiFi Protected Setup (WPS): succeeded in enrollee mode\n"); break;
		case ARDUINO_EVENT_WPS_ER_FAILED: JgsLog::print("WiFi Protected Setup (WPS): failed in enrollee mode\n"); break;
		case ARDUINO_EVENT_WPS_ER_TIMEOUT: JgsLog::print("WiFi Protected Setup (WPS): timeout in enrollee mode\n"); break;
		case ARDUINO_EVENT_WPS_ER_PIN: JgsLog::print("WiFi Protected Setup (WPS): pin code in enrollee mode\n"); break;
		case ARDUINO_EVENT_WIFI_AP_START: JgsLog::print("WiFi access point started\n"); break;
		case ARDUINO_EVENT_WIFI_AP_STOP: JgsLog::print("WiFi access point stopped\n"); break;
		case ARDUINO_EVENT_WIFI_AP_STACONNECTED: JgsLog::print("Client connected\n"); break;
		case ARDUINO_EVENT_WIFI_AP_STADISCONNECTED: JgsLog::print("Client disconnected\n"); break;
		case ARDUINO_EVENT_WIFI_AP_STAIPASSIGNED: JgsLog::print("Assigned IP address to client\n"); break;
		case ARDUINO_EVENT_WIFI_AP_PROBEREQRECVED: JgsLog::print("Received probe request\n"); break;
		case ARDUINO_EVENT_WIFI_AP_GOT_IP6: JgsLog::print("AP IPv6 is preferred\n"); break;
		case ARDUINO_EVENT_WIFI_STA_GOT_IP6: JgsLog::print("STA IPv6 is preferred\n"); break;
		case ARDUINO_EVENT_ETH_GOT_IP6: JgsLog::print("Ethernet IPv6 is preferred\n"); break;
		case ARDUINO_EVENT_ETH_START: JgsLog::print("Ethernet started\n"); break;
		case ARDUINO_EVENT_ETH_STOP: JgsLog::print("Ethernet stopped\n"); break;
		case ARDUINO_EVENT_ETH_CONNECTED: JgsLog::print("Ethernet connected\n"); break;
		case ARDUINO_EVENT_ETH_DISCONNECTED: JgsLog::print("Ethernet disconnected\n"); break;
		case ARDUINO_EVENT_ETH_GOT_IP: JgsLog::print("Obtained IP address\n"); break;
		default: JgsLog::print("[WiFi-event] event: %d\n", event); break;
	}
}


//
//	JgsWifi::init
//

void JgsWifi::init(std::function<void(const char*, const char*)> status) {
	// explicitly set wifi mode, esp defaults to STA+AP
	WiFi.mode(WIFI_STA);

	// configure wifi manager
	WiFiManager wm;

	// do we have a saved access point?
	if (wm.getWiFiIsSaved()) {
		// yes, just try to connect to it
		JgsLog::print("Connecting to WiFi access point [%s]\n", wm.getWiFiSSID(true));
		status("Connecting to WiFi", wm.getWiFiSSID(true).c_str());

		auto startMillis = millis();
		auto currentMillis = startMillis;
		WiFi.begin(wm.getWiFiSSID(true), wm.getWiFiPass(true));

		while (WiFi.status() != WL_CONNECTED && (currentMillis - startMillis) < 30000) {
			delay(1000);
			currentMillis = millis();
		}

		// see if we timed out
		if (WiFi.status() != WL_CONNECTED) {
			JgsLog::print("Failed to connect to WiFi, restarting...\n");
			status("WiFi connection failed", "Restarting...");
			delay(2000);
			ESP.restart();
		}

	} else {
		// show info screen when we enter AP mode to let user configure wifi
		wm.setAPCallback([status] (WiFiManager*) {
			status("Configuring WiFi...", "");
		});

		// set flag when user changes wifi settings
		wm.setSaveConfigCallback([this] () {
			JgsLog::print("WiFi configuration has changed\n");
			configChanged = true;
		});

		// use wifi manager to get stored network settings or start
		// access point in captive mode to let user specify details
		if (!wm.autoConnect("JoGoStudio")) {
			JgsLog::print("Failed to connect to WiFi, restarting...\n");
			status("Failed WiFi init", "Restarting...");
			delay(2000);
			ESP.restart();
		}
	}

	// we are now connected to wifi
	ssid = wm.getWiFiSSID();
	ip = WiFi.localIP().toString();

	byte mac[6];
	WiFi.macAddress(mac);

	char buffer[18];
	snprintf(buffer, sizeof(buffer), "%02x:%02x:%02x:%02x:%02x:%02x", mac[5], mac[4], mac[3], mac[2], mac[1], mac[0]);
	macAddress = buffer;

	JgsLog::print("\n");
	JgsLog::print("Connected to WiFi network\n");
	JgsLog::print("SSID: %s\n", wm.getWiFiSSID());
	JgsLog::print("IP address: %s\n", ip.c_str());
	JgsLog::print("MAC address: %s\n", macAddress.c_str());
	JgsLog::print("RSSI: %d dB\n", WiFi.RSSI());
}


//
//	JgsWifi::isConnected
//

bool JgsWifi::isConnected() {
	return WiFi.status() == WL_CONNECTED;
}


//
//	JgsWifi::reconnect
//

void JgsWifi::reconnect(std::function<void(const char *, const char *)> status) {
	// try to reconnect
	JgsLog::print("Reconnecting to WiFi access point [%s]\n", ssid.c_str());
	status("Reconnecting to WiFi", ssid.c_str());

	auto startMillis = millis();
	auto currentMillis = startMillis;
	WiFi.reconnect();

	while (WiFi.status() != WL_CONNECTED && (currentMillis - startMillis) < 30000) {
		delay(1000);
		currentMillis = millis();
	}

	// see if we timed out
	if (WiFi.status() != WL_CONNECTED) {
		JgsLog::print("Failed to reconnect to WiFi, restarting...");
		status("WiFi reconnect failed", "Restarting...");
		delay(2000);
		ESP.restart();
	}
}


//
//	JgsWifi::getRSSI
//

int JgsWifi::getRSSI() {
	return WiFi.RSSI();
}


//
//	JgsWifi::reset
//

void JgsWifi::reset() {
	// reset wifi manager
	WiFiManager wm;
	wm.resetSettings();
}
