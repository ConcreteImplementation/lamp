#include <ArduinoJson.h>
#include <SPIFFS.h>

#include "ApiServer.hpp"
#include "Color.hpp"

ApiServer::ApiServer(IColor* color)
	: color(color)
{
	bool reussi = SPIFFS.begin(true);
	if( ! reussi) Serial.println("Erreur ouvertur SPIFFS");


	server.serveStatic("/lamp", SPIFFS, "/index.html");

	server.on("/", HTTPMethod::HTTP_GET, [this](){
		_printRequestInfo();
		server.sendHeader("Location", "lamp", true);
		server.send(301, "text/plain", "");
	});
	server.on("/api/hsv", HTTPMethod::HTTP_POST, [this]() {
	 this->setHSV();
	});
	server.on("/api/rgb", HTTPMethod::HTTP_POST, [this]() {
		this->setRGB();
	});

	server.onNotFound([this]() {
		this->ressourceNonTrouvee();
	});

	server.enableCORS(true);
	server.begin();
}

void ApiServer::_printRequestInfo() {
	Serial.println("\n\n\n");

	Serial.println(server.uri());
	Serial.print("requested from: ");
	Serial.println(server.client().remoteIP());

	Serial.println("Header: ");
	for(int i = 0; i < server.headers(); ++i) {
		Serial.print(i);
		Serial.print(". ");
		Serial.print(server.headerName(i));
		Serial.print(": '");
		Serial.print(server.header(i) );
		Serial.println("'");
	}

	Serial.println("args: ");
	for(int i = 0; i < server.args(); ++i) {
		Serial.print(i);
		Serial.print(". ");
		Serial.print(server.argName(i));
		Serial.print(": '");
		Serial.print(server.arg(i) );
		Serial.println("'");
	}
	Serial.print("hostheader: '");
	Serial.print(server.hostHeader() );
	Serial.println("'");

	Serial.println("\n\n\n");
}

void ApiServer::setHSV() {
	_printRequestInfo();
	

	DynamicJsonDocument deserialisation(1024);
	const char* body = server.arg("plain").c_str();
	DeserializationError erreur = deserializeJson(deserialisation, body);
	if(erreur) {
		Serial.print(F("deserializeJson() a echoue: "));
		Serial.println(erreur.f_str());
		server.send(400, "text/plain", "invalid.");
		return;
	}

	int hue = deserialisation["hue"] ? deserialisation["hue"] :   0;
	int sat = deserialisation["sat"] ? deserialisation["sat"] : 255;
	int val = deserialisation["val"] ? deserialisation["val"] : 255;

	Serial.print("hue: ");
	Serial.println(hue);

	Serial.print("sat: ");
	Serial.println(sat);

	Serial.print("val: ");
	Serial.println(val);

	color->setHSV(hue, sat, val);
	
	server.send(200, "text/plain", String(color->getAsNumber()));
}



void ApiServer::setRGB() {
	_printRequestInfo();
	

	DynamicJsonDocument deserialisation(1024);
	const char* body = server.arg("plain").c_str();
	DeserializationError erreur = deserializeJson(deserialisation, body);
	if(erreur) {
		Serial.print(F("deserializeJson() a echoue: "));
		Serial.println(erreur.f_str());
		server.send(400, "text/plain", "invalid.");
		return;
	}

	int r = deserialisation["r"] ;
	int g = deserialisation["g"] ;
	int b = deserialisation["b"] ;

	Serial.print("r: ");
	Serial.println(r);

	Serial.print("g: ");
	Serial.println(g);

	Serial.print("b: ");
	Serial.println(b);

	color->setRGB(r, g, b);

	server.send(200, "text/plain", String(color->getAsNumber()));
}



void ApiServer::ressourceNonTrouvee() {
  Serial.println("Ressource '" + server.uri() + "' non trouvee !");
	_printRequestInfo();

  server.send(404, "text/plain", "'" + server.uri() + "' introuvable.");
}


void ApiServer::tick() { server.handleClient(); }

