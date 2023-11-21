#include <LiquidCrystal_I2C.h>

const int Trig = 14; // Define pin for Trigger of Ultrasonic Sensor
const int Echo = 25; // Define pin for Echo of Ultrasonic Sensor
float jarak, waktu; // Declare variables for distance and time
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define Suara 0.034 // Define speed of sound in cm/us

void setup() {
  // put your setup code here, to run once:
  pinMode(Trig, OUTPUT); // Set Trigger pin as output
  pinMode(Echo, INPUT); // Set Echo pin as input
  lcd.init();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(Trig, HIGH); // Send a 10us high pulse on Trig pin
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  waktu = pulseIn(Echo, HIGH); // Read the time for which the Echo pin stays high
  jarak = waktu * Suara/2; // Calculate the distance
  lcd.setCursor(0, 0);
  lcd.print(jarak);
  delay(500);
  lcd.clear();

}
