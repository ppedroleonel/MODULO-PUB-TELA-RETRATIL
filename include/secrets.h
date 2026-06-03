#ifndef SECRETS_H
#define SECRETS_H

#include <Arduino.h>
#include <ESP32Connectivity.h>

extern const char *WIFI_SSID;
extern const char *WIFI_SENHA;

extern const char *awsCertCA;
extern const char *awsCertCRT;
extern const char *awsCertPrivate;

extern const char* pub[];
extern const char* rec[];

extern const int DEBUG_NIVEL_INICIAL;

extern const int PINO_HABILITAR_DEBUG_COMPLETO;
#endif