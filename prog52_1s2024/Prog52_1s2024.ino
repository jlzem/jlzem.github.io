/* 
   Código demonstrativo para a aula de Sistemas Embarcados,
   Curso de Ciência da Computação e Engenharia da Computação
   EEP.
*/ 

#include <WiFi.h>

void setup() {

  Serial.begin(115200);
  while (!Serial)    {     }

  WiFi.begin("Wokwi-GUEST", "");
  
  while(WiFi.status() != WL_CONNECTED) { 
    delay(250);
  }

  Serial.println("-----------------------------------------------");
  Serial.print("Endereco IP: ");
  Serial.println(WiFi.localIP());
  Serial.println("-----------------------------------------------");
   
  delay(1000);

}

void loop() {

  while(1) { delay(1000); };

}
