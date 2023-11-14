#include <SPI.h> // Include SPI library for communication with MFRC522
#include <MFRC522.h> // Include MFRC522 library for RFID
#include <Wire.h> // Include Wire library for I2C devices

#define SS_PIN 21 // Define Slave Select pin for SPI
#define RST_PIN 22 // Define Reset pin for MFRC522
const int LED1 = 5; // Define pin for LED1
const int LED2 = 2; // Define pin for LED2
const int Trig = 14; // Define pin for Trigger of Ultrasonic Sensor
const int Echo = 25; // Define pin for Echo of Ultrasonic Sensor
float jarak, waktu; // Declare variables for distance and time

#define Suara 0.034 // Define speed of sound in cm/us

MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance

void setup() {
  Serial.begin(9600); // Start serial communication at 9600 baud rate
  SPI.begin(); // Start SPI communication
  mfrc522.PCD_Init(); // Initialize MFRC522
  pinMode(LED1, OUTPUT); // Set LED1 pin as output
  pinMode(LED2, OUTPUT); // Set LED2 pin as output
  pinMode(Trig, OUTPUT); // Set Trigger pin as output
  pinMode(Echo, INPUT); // Set Echo pin as input
}

void loop() {
  digitalWrite(Trig, HIGH); // Send a 10us high pulse on Trig pin
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  waktu = pulseIn(Echo, HIGH); // Read the time for which the Echo pin stays high
  jarak = waktu * Suara/2; // Calculate the distance

  if ( ! mfrc522.PICC_IsNewCardPresent()) // If no new card is present, return
  {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) // If card serial can't be read, return
  {
    return;
  }

  String content=""; // Declare a string to store the card data

  byte letter;

  for (byte i = 0; i < mfrc522.uid.size; i++) // Loop through the card data
  {
    Serial.print(mfrc522.uid.uidByte[i]<0x10 ? "0" : " "); // Print the card data
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i]< 0x10 ? " 0" : " ")); // Add the card data to the string
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  content.toUpperCase(); // Convert the card data to uppercase

  if((content.substring(1) == "F5 E9 DE 20") && (jarak < 20)) // If the card data matches and the distance is less than 20
  {
    Serial.println("CARD ACCESS GRANTED"); // Print access granted message
    Serial.println("Welcome...");
    digitalWrite(LED1, HIGH); // Turn on LED1
    delay(2000);
    digitalWrite(LED1, LOW); // Turn off LED1
    delay(1000);
  }
  else if((content.substring(1) == "51 F1 5D 27") && (jarak<20)) // If the keychain data matches and the distance is less than 20
  {
    Serial.println("KEYCHAIN ACCESS GRANTED"); // Print access granted message
    Serial.println("Welcome...");
    digitalWrite(LED2, HIGH); // Turn on LED2
    delay(2000);
    digitalWrite(LED2, LOW); // Turn off LED2
    delay(1000);
  }
  else if(jarak>20)
    {
    Serial.println("Kurang Dekat");
    delay(2000);
    }
  else
  {
    Serial.println("USER NOT DEFINED"); // If no match is found, print access denied message
    Serial.println("ACCESS DENIED!");
    delay(2000);
    digitalWrite(LED1, LOW); // Turn off LED1
    digitalWrite(LED2, LOW); // Turn off LED2
  }
}
