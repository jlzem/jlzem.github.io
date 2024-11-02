/* 
   Código demonstrativo para a aula de Bancos de Dados aplicados à Internet das Coisas,
   Curso de Engenharia e Administração de Sistemas de Banco de Dados,
   Faculdade de Tecnologia - UNICAMP.
*/

int pino_Led  = 13;
int porta_LDR = A3;
  
void setup(){  
  
  Serial.begin(9600);
  
  pinMode(pino_Led, OUTPUT);
  
}  
   
void loop() {  

  int valor_LDR = analogRead(porta_LDR);
  int luminosidade = map(valor_LDR,3,1002,0,100);

  Serial.print("LDR: ");
  Serial.print(valor_LDR);
  Serial.print(", Luminosidade: ");
  Serial.print(luminosidade);
  Serial.println(" %");
  
  if ( luminosidade < 51 )  {  
    digitalWrite(pino_Led, HIGH);  
  } else  {  
    digitalWrite(pino_Led, LOW);  
  } 

  delay(500);
  
}  
