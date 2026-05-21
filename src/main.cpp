/**
 *  Nome: Pedro Leonel de Lorena, Leonardo Ferrarese Correa, Lais Rodrigues Sevilhano & Luigi Arnosti Reginato
 *  Descrição: Neste projeto iremos tratar a mensagem que recebemos do json do esp publisher e apos tratar o esp vai realizar as ações da tela retratil 
 *  Projeto: MODULO RECEIVER TELA RETRATIL
 *  Data: 21/05/2026
 *  Versão: 0.0.1
 */

#include <Arduino.h>
#include "WiFiManager.h"
#include "MqttManager.h"
#include "DebugManager.h"
#include <ArduinoJson.h>
#include <secrets.h>

//==============================
//* Variavel Global


//==============================

//==============================
//* FUNÇÃO

void tratarMensagemRecebida(const char *topico, const String &mensagem);
void tratarJsonComando(const String &mensagem);

//==============================


void setup()
{
  configurarDebug();
  conectarWiFi();
  configurarMQTT();
  registrarCallBackMensagem(tratarMensagemRecebida);
  conectarMQTT();
}

void loop()
{

  garantirWiFiConectado();
  garantirMQTTConectado();
  loopMQTT();

}

void tratarMensagemRecebida(const char *topico, const String &mensagem)
{
  debugInfo("==================================");
  debugInfo("Mensagem recebida na aplicação");
  debugInfo("==================================");

  if (topico == nullptr)
  {
    debugErro("Tópico MQTT inválido");
    return;
  }

  debugInfo("Tópico: " + String(topico));
  debugInfo("Mensagem " + mensagem);

  debugInfo(String(strcmp(topico, TOPICO_COMANDO)));

  if (strcmp(topico, TOPICO_COMANDO) == 0)
  {
    tratarJsonComando(mensagem);
    return;
  }

  debugErro("Tópico näo tratado: " + String(topico));
}



void tratarJsonComando(const String &mensagem)
{
  JsonDocument doc;

  deserializeJson(doc, mensagem);

  DeserializationError erro = deserializeJson(doc, mensagem);

  if (erro)
  {
    debugErro("Erro ao interpretar o JSON.");
    debugErro(erro.c_str());
    return;
  }

  if (doc["lampada"].is<bool>())
  {
    bool lampada = doc["lampada"].as<bool>();

  }
  else
  {
    debugErro("Checar a conexão da lampamda com o LED");
    debugErro("Checar erro no JSON");
  }
  
}
