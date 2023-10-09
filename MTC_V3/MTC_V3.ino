/*
  Devin Hernandez
  Sophomore Project Lab
  PV-IES System
  10/9/23

  Third attempt to create an alternating PWM signal to control our gate driver. This time I am using timer registers instead of delays.
  This code is designed to work based in a control voltage that ranges from 0V - 5V. This control voltage comes from a potentiometer.
  It will be modified to take a control voltage from a Solar Panel to properly control a battery's output.

  Most of the code here is credited to John Wasser and Koepel, both from the Arduino Forum.
*/

const unsigned TOP = 16000;
int delta;

void setup() {
  Serial.begin(115200);
  delay(200);

  digitalWrite(9, LOW);
  pinMode(9, OUTPUT);
  digitalWrite(10, LOW);
  pinMode(10, OUTPUT);

  // Stop Timer/Counter1
  TCCR1A = 0;  // Timer/Counter1 Control Register A
  TCCR1B = 0;  // Timer/Counter1 Control Register B
  TIMSK1 = 0;  // Timer/Counter1 Interrupt Mask Register

  // Set Timer/Counter1 to Waveform Generation Mode 8:
  // Phase and Frequency correct PWM with TOP set by ICR1
  TCCR1B |= _BV(WGM13);                 // WGM=8
  TCCR1A |= _BV(COM1A1);                // Normal PWM on Pin 9
  TCCR1A |= _BV(COM1B1) | _BV(COM1B0);  // Inverted PWM on Pin 10

  ICR1 = TOP;
  // Difference between OCR1A and OCR1B is Dead Time
  OCR1A = (TOP / 2) - 8;
  OCR1B = (TOP / 2) + 8;

  // Start timer by setting the clock-select bits to non-zero
  TCCR1B |= _BV(CS10);   // prescale = 1
}

void loop() {
  int sensorValue = analogRead(A0); //pull in a value based on potentiometer
  float voltage = sensorValue * (5.0 / 1023.0);  //change that value to range from 0 - 5
  Serial.print(voltage);
  Serial.print(" ");
  //int voltage1000 = voltage * 1000;
  //Serial.println(voltage1000);
  int voltMap = voltage * (16000 / 5); //change voltage from 0 - 5 to 0 - 16k
  Serial.println(voltMap);

  OCR1A = delta + voltMap;
  OCR1B = delta + voltMap;

  Serial.print(OCR1A);
  Serial.print(" ");
  Serial.println(OCR1B);

  delay(1);
}
