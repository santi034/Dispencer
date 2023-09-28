#include Arduino.h
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

// Credenciales de acceso a tu red WiFi
const char* ssid = "Escuela Italiana";
const char* password = "italiana2020";

// Configura los parametros de tu bot de Telegram
#define BOTtoken "5987717272:AAFESsMLruCSXeD4xWEaun0wG6Z_zsOAkXI"  // your Bot Token (Get from Botfather)
#define BOT_ID "6296645697"

X509List cert(TELEGRAM_CERTIFICATE_ROOT);
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

const int buttonPin = 4;
int buttonState = 0;

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT);
  client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi conectado");

  // El bot mandará un mensaje cuando esté listo para usarse
  bot.sendMessage(BOT_ID, "Bot preparado", "");
}

void loop() {
  buttonState = digitalRead(buttonPin);

  // Cuando se pulsa el botón, se le pide al bot que mande un mensaje diciendo "Boton presionado"
  if (buttonState == HIGH) {
    bot.sendMessage(BOT_ID, "Boton presionado", "");
    delay(300);
  } else {
    // No hace nada si no se pulsa el botón
  }
}