/**
 *  Nome: Pedro Leonel de Lorena, Leonardo Ferrarese Correa, Lais Rodrigues Sevilhano & Luigi Arnosti Reginato
 *  Descrição: Neste projeto iremos tratar a mensagem que recebemos do json do esp publisher e apos tratar o esp vai realizar as ações da tela retratil
 *  Projeto: MODULO RECEIVER TELA RETRATIL
 *  Data: 21/05/2026
 *  Versão: 1.0.0
 */

#include <Arduino.h>
#include <DebugManager.h>
#include <ArduinoJson.h>
#include <ESP32Connectivity.h>
#include <Bounce2.h>
#include "secrets.h"
#include "postarJson.h"
#include "Conectividade.h"

//==============================
//* Variavel Global

const int pinoUp = 10;
const int pinoDown = 11;
const int pinoPause = 12;
const int pinoTela = 0;

//==============================
//* Criação de objetos

Bounce TELA = Bounce();
Bounce UP = Bounce();
Bounce DOWN = Bounce();
Bounce PAUSE = Bounce();
ESP32Connectivity telaRetratil;

int8_t tela = 0;

void setup()
{
  Serial.begin(115200);
  configurarDebug(DEBUG_NIVEL_INICIAL, PINO_HABILITAR_DEBUG_COMPLETO);
  telaRetratil.beginAWS(wifiConfig, awsConfig, topicosConfig);

  TELA.attach(pinoTela, INPUT_PULLUP);
  UP.attach(pinoUp, INPUT_PULLUP);
  DOWN.attach(pinoDown, INPUT_PULLUP);
  PAUSE.attach(pinoPause, INPUT_PULLUP);
}

void loop()
{
  telaRetratil.update();

  UP.update();
  DOWN.update();
  PAUSE.update();
  TELA.update();

  if (UP.fell())
  {
    postarBotaoUp();
  }

  if (DOWN.fell())
  {
    postarBotaoDown();
  }

  if (PAUSE.fell())
  {
    postarBotaoPause();
  }

  if (TELA.fell())
  {
    tela = !tela;
    postarBotaoPause();

    Serial.println("Tela: " + String(tela));
  }
}