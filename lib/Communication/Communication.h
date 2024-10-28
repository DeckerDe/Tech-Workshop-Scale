#pragma once
#include<PubSubClient.h>

class Communication
{
    public:
      Communication(const char* ssid, const char* password);
    
    private:
      PubSubClient client;
      void connectMqtt();
};