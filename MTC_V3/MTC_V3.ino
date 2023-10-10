/*
  Devin Hernandez
  Sophomore Project Lab
  PV-IES System
  10/9/23

  Third attempt to create an alternating PWM signal to control our gate driver. This time I am using timer registers instead of delays.
  This code is designed to work based in a control voltage that ranges from 0V - 5V. This control voltage comes from a potentiometer.
  It will be modified to take a control voltage from a Solar Panel to properly control a battery's output.

  Most of the code here is credited to John Wasser and Koepel, both from the Arduino Forum.

  Pins used:
    D9    PWM logic HIGH output
    D10   PWM Logic LOW output - is the compliment of D9
    A0    Analog input for the potentiometer - controls the PWM output of D9


  Software Version: 0.3.1  
  Changelog:
      > 0.3.0   10/9/23
        -Created Program
      > 0.3.1   10/10/23
        -Removed "delta," an unneeded variable
        -Removed the delay at the end of the loop
        -Added constrain() functions for stability


*/

const unsigned TOP = 16000;

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
  int sensorValue = analogRead(A0); // pull in a value based on potentiometer
  float voltage = sensorValue * (5.0 / 1023.0);  // change that value to range from 0 - 5
  int voltMap = voltage * (16000 / 5); // change voltage from 0 - 5 to 0 - 16k

  // add the value calulated from the potentiometer input to the compare registers.
  OCR1A = voltMap - 8; 
  OCR1B = voltMap + 8;

  // constrain values to a range of 0 - 16k
  OCR1A = constrain(OCR1A, 0, TOP);
  OCR1B = constrain(OCR1B, 0, TOP); 
  //delay(1);
}
