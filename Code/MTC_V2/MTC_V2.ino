/*
  Devin Hernandez
  Sophomore Project Lab
  PV-IES
  10/2/23

  Software Version: 0.2.x
*/

int potPin = A0;
int ledPin = 9;
int ledPinGreen = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potValue = analogRead(potPin);
  int brightness = map(potValue, 0, 1023, 0, 255);
  int brightnessGreen = map(potValue, 0, 1023, 255, 0);
  //int brightnessGreen = (brightness*-1)+256;
  Serial.print(brightness);
  Serial.print(" ");
  Serial.println(brightnessGreen);

  analogWrite(ledPin, brightness);
  analogWrite(ledPinGreen, brightnessGreen);
  //delay(1);
}
