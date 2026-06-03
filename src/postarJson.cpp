#include <Arduino.h>
#include "secrets.h"
#include <ESP32Connectivity.h>
#include <ArduinoJson.h>
#include <ezTime.h>
#include "postarJson.h"


void postarBotaoDown()
{
    Timezone carimbo;

    waitForSync();

    carimbo.setLocation("America/Sao_Paulo");
    setInterval(60);

    JsonDocument doc;

    doc["telaRetratil"]["tela"] = tela;
    doc["telaRetratil"]["UP"] = false;
    doc["telaRetratil"]["PAUSE"] = false;
    doc["telaRetratil"]["DOWN"] = true;
    doc["telaRetratil"]["timestamp"] = carimbo.now();
    doc["telaRetratil"]["tempo"] = carimbo.dateTime();

    String texto;
    serializeJson(doc, texto);
    telaRetratil.publicar(0, texto.c_str());
}

void postarBotaoUp()
{
    Timezone carimbo;

    waitForSync();

    carimbo.setLocation("America/Sao_Paulo");
    setInterval(60);

    JsonDocument doc;

    doc["telaRetratil"]["tela"] = tela;
    doc["telaRetratil"]["UP"] = true;
    doc["telaRetratil"]["PAUSE"] = false;
    doc["telaRetratil"]["DOWN"] = false;
    doc["telaRetratil"]["timestamp"] = carimbo.now();
    doc["telaRetratil"]["tempo"] = carimbo.dateTime();

    String texto;
    serializeJson(doc, texto);
    telaRetratil.publicar(0, texto.c_str());
}

void postarBotaoPause()
{
    Timezone carimbo;

    waitForSync();

    carimbo.setLocation("America/Sao_Paulo");
    setInterval(60);

    JsonDocument doc;

    doc["telaRetratil"]["tela"] = tela;
    doc["telaRetratil"]["UP"] = false;
    doc["telaRetratil"]["PAUSE"] = true;
    doc["telaRetratil"]["DOWN"] = false;
    doc["telaRetratil"]["timestamp"] = carimbo.now();
    doc["telaRetratil"]["tempo"] = carimbo.dateTime();

    String texto;
    serializeJson(doc, texto);
    telaRetratil.publicar(0, texto.c_str());
}