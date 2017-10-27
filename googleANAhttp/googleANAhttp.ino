#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "ssid_ap";
const char* password = "mot2passeAP";
const char* hostString = "ESPpostGA2";

unsigned long previousMillis = 0;
volatile int compteur = 0;

int envoiGA(int nbr) {
  HTTPClient http;
  int ret = -1;

  String eventData = "v=1&tid=UA-xxxxxxxx-x&cid=0000&t=event&ec=physique&ea=mouvement&el=Mouvement porte&ev=";
  eventData += nbr;

  Serial.print("Envoi GA: ");
  Serial.println(eventData);

  if(WiFi.status()== WL_CONNECTED) {
    http.begin("http://www.google-analytics.com/collect");
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    int httpCode = http.POST(eventData);
    
    Serial.print("Reponse GA: ");
    Serial.println(httpCode);
    http.end();
    
    if(httpCode == 200) {
      ret = 0;
    }
  }
  
  return ret;
}
  
void IRint() {
  digitalWrite(D4, LOW);
  compteur++;
}

void setup() {
  uint8_t i = 0;

  pinMode(D4, OUTPUT);
  pinMode(D3, INPUT_PULLUP);
  
  Serial.begin(19200);

  // mon nom d'hôte
  Serial.println("");
  Serial.print("Hostname: ");
  Serial.println(hostString);
  WiFi.hostname(hostString);

  // connexion Wifi client (STAtion)
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("\nConnexion à ");
  Serial.println(ssid);
  while (WiFi.status() != WL_CONNECTED && i++ < 20) delay(500);
  if(i == 21){
    Serial.print("Erreur de connexion sur "); Serial.println(ssid);
    while (1) {
      // erreur DHCP
    }
  }
  // Affichage adresse
  Serial.print("adresse IP: ");
  Serial.println(WiFi.localIP());

  // démarrage mDNS-SD
  if (!MDNS.begin(hostString)) {
    Serial.println("Erreur configuration mDNS!");
  } else {
    Serial.println("Répondeur mDNS démarré");
  }

  attachInterrupt(digitalPinToInterrupt(D3), IRint, RISING);

  sei();
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= 10000) {
    previousMillis = currentMillis;
    if(compteur) {
      Serial.print("compteur= ");
      Serial.println(compteur);
      envoiGA(compteur);
      compteur=0;
      digitalWrite(D4, HIGH);
    }
  }
}
