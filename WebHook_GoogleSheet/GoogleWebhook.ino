#include <WiFi.h>
#include <HTTPClient.h>

HTTPClient cliente;

void setup() {

  Serial.begin(115200);
  while (!Serial)    {     }

  WiFi.begin("Wokwi-GUEST", "");

  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
  }

  Serial.println("-----------------------------------------------");
  Serial.print("Endereco IP: ");
  Serial.println(WiFi.localIP());
  Serial.println("-----------------------------------------------");

  delay(1000);

}

void loop() {

  char payload[500];

  int v1 = analogRead(32);
  int v2 = analogRead(33);
  int v3 = analogRead(34);
  int v4 = analogRead(35);

  Serial.println("");
  Serial.print("A0: ");
  Serial.println(v1);
  Serial.print("A1: ");
  Serial.println(v2);
  Serial.print("A2: ");
  Serial.println(v3);
  Serial.print("A3: ");
  Serial.println(v4);
  Serial.println("");

  sprintf(payload, "https://script.google.com/macros/s/AKfycbwrZZX-3thV0mnbZlxUil1uEzmcQnZcKcSoBacmGd9_O-NtaNLEDaVGcF0svta6G2Gj/exec?gid=0&Campo01=%d&Campo02=%d&Campo03=%d&Campo04=%d", v1, v2, v3, v4 );
  Serial.println(payload);
  Serial.println("Requisicao: GET");

  cliente.begin(payload);

  int statusCode = cliente.GET();
  String response = cliente.getString();

  Serial.print("Status: ");
  Serial.println(statusCode);
  Serial.print("Retorno: ");
  Serial.println(response);
  Serial.println();

  delay(15000);

}
