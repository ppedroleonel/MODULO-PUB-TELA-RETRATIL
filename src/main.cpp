/**
 *  Nome: Pedro Leonel de Lorena, Leonardo Ferrarese Correa, Lais Rodrigues Sevilhano & Luigi Arnosti Reginato
 *  Descrição: Neste projeto iremos tratar a mensagem que recebemos do json do esp publisher e apos tratar o esp vai realizar as ações da tela retratil 
 *  Projeto: MODULO RECEIVER TELA RETRATIL
 *  Data: 21/05/2026
 *  Versão: 0.0.4
 */

#include <Arduino.h>
#include "WiFiManager.h"
#include "MqttManager.h"
#include "DebugManager.h"
#include <ArduinoJson.h>
#include <secrets.h>
#include <Bounce2.h>

//==============================
//* Variavel Global

const int pinoUp = 0;
const int pinoDown = 5;
const int pinoPause = 12;

//==============================
//* Criação de objetos

Bounce UP = Bounce();
Bounce DOWN = Bounce();
Bounce PAUSE = Bounce();

void setup()
{
  configurarDebug();
  conectarWiFi();
  configurarMQTT();
  conectarMQTT();
  
  UP.attach(pinoUp, INPUT_PULLUP);
  DOWN.attach(pinoDown, INPUT_PULLUP);
  PAUSE.attach(pinoPause, INPUT_PULLUP);
}

void loop()
{
  garantirWiFiConectado();
  garantirMQTTConectado();
  loopMQTT();
  
  UP.update();
  DOWN.update();
  PAUSE.update();
  
  if(UP.fell())
  {
    postarBotaoUp();
  }
  
  if(DOWN.fell())
  {
    postarBotaoDown();
  }
  
  if(PAUSE.fell())
  {
    postarBotaoPause();
  }
}