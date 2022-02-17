#include "WifiConfiguration.hpp"


const char* portalSSID = "lamp";
const char* portalPassword = "my/lamp/password";
IPAddress   portalAddress(192, 168, 23, 1);
IPAddress   portalGateway(192, 168, 23, 1);
IPAddress   subnetMask(255, 255, 255, 0);

void WifiConfiguration::StartWifiConfiguration(bool isDebug) {
	WiFiManager wifiManager;
	wifiManager.setDebugOutput(isDebug);
	wifiManager.setConfigPortalTimeout(180);
	wifiManager.setAPStaticIPConfig(portalAddress, portalGateway, subnetMask);
	wifiManager.setAPCallback([](WiFiManager* p_wifiManager) {
		Serial.println("Wifi connexion failed. Starting WiFiManager.");
	});


	wifiManager.autoConnect(portalSSID, portalPassword);

	if(WiFi.isConnected() == false) {
		Serial.println("configuration wifi: erreur connexion reseau.");
		return;
	}

	Serial.println("connexion reseau reussie.");
}