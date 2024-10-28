#include "WiFi.h"
#include "Communication.h"
#include <PubSubClient.h>


Communication::Communication(const char *ssid, const char *password)
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("\nConnecting to WiFi Network ..");

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(100);
  }

  Serial.println("\nConnected to the WiFi network");
  Serial.print("Local ESP32 IP: ");
  Serial.println(WiFi.localIP());

  connectMqtt();
};

void Communication::connectMqtt(){
  WiFiClient espClient;
  this->client.setClient(espClient);
  this->client.setServer("broker.hivemq.com", 1883);

  int retries = 0;
  
  while (!this->client.connected() and retries < 5)
  {
    Serial.println("Connecting to MQTT...");

    if (this->client.connect("ESPionClient"))
    {
      Serial.println("connected");
      client.publish("testTechWorkshop","Cheguei");
    }
    else
    {
      retries++;
      Serial.print("failed with state ");
      Serial.print(this->client.state());
      delay(2000);
    }
  }

}

/*
#include <Arduino.h>
//#include <Servo.h>
#include <Servo.h>

Servo ESC;

const int potPin = 0;

int potVal;


void setup()
{
  Serial.begin(9600);

  ESC.attach(9, 1000, 2000);
}


void loop()
{
  potVal = analogRead(potPin);
  Serial.println(potVal);

  potVal = map(potVal, 0, 1024, 0, 180);

  ESC.write(potVal);

  Serial.println(potVal);
  delay(500);
}
*/