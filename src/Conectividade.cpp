#include <Arduino.h>
#include <ESP32Connectivity.h>


#include "secrets.h"

ConfigWiFi wifiConfig = {
    WIFI_SSID,
    WIFI_SENHA
};

ConfigAWS awsConfig = {
    "a6t7fzch59vsw-ats.iot.us-east-1.amazonaws.com",
    8883,
    "telaRetratilPublisher",
    awsCertCA,
    awsCertCRT,
    awsCertPrivate
};

ConfigTopicos topicosConfig = {
    pub, 1,
    rec, 1
};
