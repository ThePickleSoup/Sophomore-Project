/*
  Devin Hernandez
  Sophomore Project Lab
  PV-IES System
  10/9/23

  Fourth attempt to create an alternating PWM signal to control our gate driver. This time I am using the TimerOne library to control PWM.
  This code is designed to work based in a control voltage that ranges from 0V - 5V. This control voltage comes from a potentiometer.
  It will be modified to take a control voltage from a Solar Panel to properly control a battery's output.

  This code was generated by ChatGPT and further modified for use.

  Pins used:
    D9    PWM logic HIGH output
    D10   PWM Logic LOW output - is the compliment of D9
    A0    Analog input for the potentiometer - controls the PWM output of D9


  Software Version: 0.4.0 
  Changelog:
      > 0.4.0   10/10/23
        -Code Generated
        


*/

#include <TimerOne.h>

const unsigned TOP = 16000;

void setup() {
  Serial.begin(115200);
  delay(200);

  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  Timer1.stop(); // Stop Timer1

  Timer1.initialize(1000000 / 500); // Set the timer to a 500 Hz (2000 µs period) frequency

  Timer1.pwm(9, TOP / 2 - 8);
  Timer1.pwm(10, TOP / 2 + 8);
}

void loop() {
  int sensorValue = analogRead(A0); // Read a value based on the potentiometer
  float voltage = sensorValue * (5.0 / 1023.0); // Map it to a range from 0 to 5
  int voltMap = voltage * (TOP / 5); // Map voltage from 0 to 5 to 0 to 16k

  // Add the value calculated from the potentiometer input to the compare registers.
  Timer1.pwm(9, constrain(voltMap - 8, 0, TOP));
  Timer1.pwm(10, constrain(voltMap + 8, 0, TOP));
}
