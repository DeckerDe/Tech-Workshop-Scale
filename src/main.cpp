
#include <Arduino.h>
#include <Communication.h>
#include <Scale.h>

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 13;
const int LOADCELL_SCK_PIN = 12;

const char *ssid = "DNET-2.4G";
const char *password = "micasa33";

#define ONBOARD_LED 2

Scale scale = Scale(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

void setup()
{
  Serial.begin(115200);
  Serial.println("Starting");
  auto comm = Communication(ssid, password);
  pinMode(ONBOARD_LED, OUTPUT);
  
}

void loop()
{ /*
delay(1000);
Serial.println("Up");
digitalWrite(ONBOARD_LED,HIGH);
delay(100);
digitalWrite(ONBOARD_LED,LOW);
  if (scale.is_ready())
  {
    scale.set_scale();
    Serial.println("Tare... remove any weights from the scale.");
    delay(5000);
    scale.tare();
    Serial.println("Tare done...");
    Serial.print("Place a known weight on the scale...");
    delay(5000);
    long reading = scale.get_units(10);
    Serial.print("Result: ");
    Serial.println(reading);
  }
  else
  {
    Serial.println("Failed to start Scale");
  }
  
  delay(1000);
*/
 if (scale.is_ready())
  {
    Serial.println("Scale is ready");
  }
  else
  {
    Serial.println("Failed to start Scale");
  }
  delay(1000);
}
