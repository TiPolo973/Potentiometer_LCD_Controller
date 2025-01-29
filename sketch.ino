#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {
  Serial.begin(115200);
  lcd.init();  // initialize the lcd

  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(1, 0); // Colonne 1 Ligne 0  // Laisser uniquement les lignes 0 et 1
  lcd.print("potentiometre");
  pinMode(2, OUTPUT);


}


void loop() {

  int value = analogRead(4);
  int res_value = map(value, 0, 1023, 0, 255);
  int pourcentage = (res_value * 100) / 1020;
  String message = String(pourcentage) + "%";
  lcd.setCursor(1, 1);
  lcd.print("led a :");
  lcd.setCursor(9, 1);
  lcd.print(message);
  analogWrite(2, res_value);
  delay(1000);

}