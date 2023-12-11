int red1 = 2;
int yel1 = 3;
int gre1 = 4;
int red2 = 8;
int yel2 = 9;
int gre2 = 10;

void setup() {
  // put your setup code here, to run once:
pinMode(red1, OUTPUT);
pinMode(red2, OUTPUT);
pinMode(yel1, OUTPUT);
pinMode(yel2, OUTPUT);
pinMode(gre1, OUTPUT);
pinMode(gre2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Red1 Lights up for 3 seconds, Green 2 for 2 Seconds + Yellow 2 1 Seconds
  digitalWrite(red1, HIGH);
  digitalWrite(yel1, LOW);
  digitalWrite(gre1, LOW);
  digitalWrite(red2, LOW);
  digitalWrite(yel2, LOW);
  digitalWrite(gre2, HIGH);
  delay(2000);
  digitalWrite(red1, HIGH);
  digitalWrite(yel1, HIGH);
  digitalWrite(gre1, LOW);
  digitalWrite(red2, LOW);
  digitalWrite(yel2, HIGH);
  digitalWrite(gre2, LOW);
  delay(1000);
  //Red 2 Lights up for 3 seconds, Green 1 for 2 Seconds + Yellow 1 1 Seconds

  digitalWrite(red1, LOW);
  digitalWrite(yel1, LOW);
  digitalWrite(gre1, HIGH);
  digitalWrite(red2, HIGH);
  digitalWrite(yel2, LOW);
  digitalWrite(gre2, LOW);
  delay(2000);
  digitalWrite(red1, LOW);
  digitalWrite(yel1, HIGH);
  digitalWrite(gre1, LOW);
  digitalWrite(red2, HIGH);
  digitalWrite(yel2, HIGH);
  digitalWrite(gre2, LOW);
  delay(2000);
}
