#include <Wire.h>
#include <LiquidCrystal_I2C.h>
const int trigPin = 10;
const int echoPin = 9;
long zaman;
int mesafe;

LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  Serial.begin(9600);
lcd.init();                      // Initialize the LCD
  lcd.backlight();                 // Turn on the backlight    
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  zaman = pulseIn(echoPin, HIGH);
  
  mesafe = zaman * 0.034 / 2;
  mesafe = mesafe - 1;
  Serial.println(mesafe);
  Serial.println(" cm");
 lcd.setCursor(0, 0);
     lcd.clear();
  lcd.print("Distance: ");
  lcd.print(mesafe);
  lcd.print("cm");
    delay(500); 

}