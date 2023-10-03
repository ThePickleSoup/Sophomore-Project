/*
  Devin Hernandez
  Sophomore Project Lab
  PV-IES System

*/

void setup() {
  // put your setup code here, to run once:
  // setup pins 2 and 3 for alternating PWM signal
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  float delayOne;
  float delayTwo;
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.println(voltage);

  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  delay(delayOne); // Wait
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  delay(delayTwo); // Wait
}
