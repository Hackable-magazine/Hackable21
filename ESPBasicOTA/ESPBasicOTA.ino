#include <ESP8266WiFi.h>
#include <ArduinoOTA.h>

// SSID du point d'accès
const char* ssid = "ssidAP";
// mot de passe wifi
const char* password = "mot2passe";
// Nom d'hôte (pour mDNS)
const char* hostString = "espOTAtest2";
// mot de passe pour l'OTA
const char* otapass = "123456";

// gestion du temps pour loop()
unsigned long previousMillis = 0;
// gestion du temps pour calcul de la durée de la MaJ
unsigned long otamillis;

void confOTA() {
  // Port 8266 (défaut)
  ArduinoOTA.setPort(8266);

  // Hostname défaut : esp8266-[ChipID]
  ArduinoOTA.setHostname(hostString);

  // mot de passe pour OTA
  ArduinoOTA.setPassword(otapass);

  // lancé au début de la MaJ
  ArduinoOTA.onStart([]() {
    Serial.println("/!\\ MaJ OTA");
    otamillis=millis();
  });

  // lancé en fin MaJ
  ArduinoOTA.onEnd([]() {
    Serial.print("\n/!\\ MaJ terminee en ");
    Serial.print((millis()-otamillis)/1000.0);
    Serial.println(" secondes");
  });

  // lancé lors de la progression de la MaJ
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progression: %u%%\r", (progress / (total / 100)));
  });

  // En cas d'erreur
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Erreur[%u]: ", error);
    switch(error) {
      // erreur d'authentification, mauvais mot de passe OTA
      case OTA_AUTH_ERROR:     Serial.println("OTA_AUTH_ERROR");
                               break;
      // erreur lors du démarrage de la MaJ (flash insuffisante)
      case OTA_BEGIN_ERROR:    Serial.println("OTA_BEGIN_ERROR");
                               break;
      // impossible de se connecter à l'IDE Arduino
      case OTA_CONNECT_ERROR:  Serial.println("OTA_CONNECT_ERROR");
                               break;
      // Erreur de réception des données
      case OTA_RECEIVE_ERROR:  Serial.println("OTA_RECEIVE_ERROR");
                               break;
      // Erreur lors de la confirmation de MaJ
      case OTA_END_ERROR:      Serial.println("OTA_END_ERROR");
                               break;
      // Erreur inconnue
      default:                 Serial.println("Erreur inconnue");
    }
  });

  // Activation fonctionnalité OTA
  ArduinoOTA.begin();
}

void setup() {
  // moniteur série
  Serial.begin(115200);
  //Serial.println("\e[2J");
  // Démarrage
  Serial.println("\r\nBoot...");

  // mode Wifi client
  WiFi.mode(WIFI_STA);
  // connexion
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    // impossible de se connecter au point d'accès
    // reboot après 5s
    Serial.println("Erreur connexion Wifi ! Reboot...");
    delay(5000);
    ESP.restart();
  }

  // configuration OTA
  confOTA();

  // Tout est prêt,on affiche notre IP
  Serial.print("Adresse IP: ");
  Serial.println(WiFi.localIP());  
}

void loop() {
  unsigned long currentMillis = millis();

  // 10s de passées ?
  if (currentMillis - previousMillis >= 10000) {
    previousMillis = currentMillis;
    Serial.println("pouet !");
  }

  // gestion OTA
  ArduinoOTA.handle();
}
