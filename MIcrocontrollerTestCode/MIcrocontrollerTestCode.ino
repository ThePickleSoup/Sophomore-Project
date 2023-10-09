/*
  Devin Hernandez
  Sophomore Project Lab
  PV-IES System

*/

void setup() {
  // put your setup code here, to run once:
  // setup pins 2 and 3 for alternating PWM signal
  pinMode(9, OUTPUT);
  digitalWrite(9, LOW);
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);
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
  //float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.print(voltage);
  Serial.print(" ");

  delayOne = 
  delayTwo = 
  Serial.print(delayOne);
  Serial.print(" ");
  Serial.println(delayTwo);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  delay(delayOne); // Wait
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  delay(delayOne); // Wait
}
