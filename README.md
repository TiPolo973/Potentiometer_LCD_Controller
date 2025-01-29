# I2C Potentiometer Display  

📌 **Contrôler l'intensité d'une LED avec un potentiomètre et afficher la valeur en pourcentage sur un écran LCD I2C**  

## 🔥 Présentation  
Ce projet utilise un **ESP32**, un **potentiomètre**, un **écran LCD I2C** et une **LED** pour démontrer comment :  
✅ Lire une valeur analogique d’un potentiomètre  
✅ Ajuster la luminosité d'une LED en fonction de cette valeur  
✅ Afficher l’intensité lumineuse en pourcentage sur un écran LCD  

## 🛠 Matériel requis  
- ESP32  
- Potentiomètre  
- LED + Résistance (150Ω)  
- Écran LCD I2C (16x2)  
- Câbles de connexion  

## ⚡ Schéma de connexion  
| Composant | ESP32 |  
|-----------|-------|  
| Potentiomètre (VCC) | 3.3V |  
| Potentiomètre (GND) | GND |  
| Potentiomètre (Signal) | GPIO 4 |  
| LED (Anode) | GPIO 2 (avec résistance) |  
| LED (Cathode) | GND |  
| LCD I2C (SDA) | GPIO 21 |  
| LCD I2C (SCL) | GPIO 22 |  

## 🚀 Installation et utilisation  
1. **Télécharger le code** depuis ce repository  
2. **Installer la bibliothèque requise** dans l'IDE Arduino :  
   - `LiquidCrystal_I2C` pour l'affichage LCD  
3. **Flasher le code sur l'ESP32**  
4. **Observer l'affichage** : la valeur du potentiomètre est affichée en pourcentage sur l'écran LCD et contrôle l'intensité de la LED  

## 📝 Code principal  
```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  lcd.init();  // Initialisation de l'écran LCD
  lcd.backlight();
  
  lcd.setCursor(1, 0); // Colonne 1 Ligne 0
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
