#include <Arduino.h>
#include <Wire.h>              // Memanggil library wire.h
#include <LiquidCrystal_I2C.h> // Memanggil library LCD dengan I2C
LiquidCrystal_I2C lcd(0x27, 20, 4); // Alamat I2C(0x27) LCD dan Jenis LCD (20x4)
#define LDRT A0                 // Deklarasi LDR pada pin A0
#define LDRB A1


int nilaildrt;
int nilaildrb;


void bacaLDR()
{
nilaildrt=analogRead(LDRT);
nilaildrb=analogRead(LDRB);

}


void setup() {
  Serial.begin(9600);     // Baud komunikasi serial pada 9600
  lcd.init();             // instruksi untuk memulai LCD
  lcd.begin(20,4);        // instruksi untuk menggunakan lcd 20x4
  lcd.backlight();        // instruksi untuk mengaktifkan lampu latar LCD
  lcd.setCursor(3,0);
  lcd.print("Hello, world!");
  lcd.setCursor(4,1);
  lcd.print("TEST PROJECT");
  lcd.setCursor(3,2);
  lcd.print("Project Juan");
  lcd.setCursor(3,3);
  lcd.print("SOLAR TRACKER");
  delay(500);
  pinMode(LDRT,INPUT);
  pinMode(LDRB,INPUT);
}
void loop() {
    bacaLDR();  
    lcd.clear();
    lcd.setCursor(0,2);
    lcd.print("Timur");
    lcd.setCursor(11,2);
    lcd.print("Barat");
    lcd.setCursor(0,3);
    lcd.print("NA: "); 
    lcd.print(nilaildrt);
    lcd.setCursor(11,3);
    lcd.print("NA: "); 
    lcd.print(nilaildrb);

    delay(1000);
    
    Serial.print("nilai LDR Timur: ");Serial.print(nilaildrt);
    Serial.print(" nilai LDR Barat: ");Serial.println(nilaildrb);   
} 