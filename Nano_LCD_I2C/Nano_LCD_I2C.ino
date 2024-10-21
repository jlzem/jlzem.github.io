/* 
   Código demonstrativo para a aula de Sistemas Embarcados,
   Curso de Ciência da Computação e Engenharia da Computação
   EEP. 
*/

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  
  lcd.setCursor(0,0);
  lcd.print(" Escola de Eng. ");
  lcd.setCursor(0,1);
  lcd.print(" de  Piracicaba ");
 
  delay(3000);

  lcd.clear(); 
  lcd.setCursor(0,0);
  lcd.print("    Sistemas    ");
  lcd.setCursor(0,1);
  lcd.print("   Embarcados   ");
  
  delay(3000);
  
  lcd.clear();
  
}