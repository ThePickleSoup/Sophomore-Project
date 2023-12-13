#define s1_pin 5  // Pin for S1 (High)
#define s2_pin 6  // Pin for S2 (LOW)
#define s3_pin 9  // Pin for S3 (connected to buck mode in the diagram) HIGH
#define s4_pin 10  // Pin for S4 (connected to boost mode in the diagram) LOW

void setup() {
  // Set fast frequency for 62khz
  TCCR0B = TCCR0B & B11111000 | B00000001;
  TCCR1B = TCCR1B & B11111000 | B00000001;

  // Initialize both pins to low
  analogWrite(s1_pin, 0);
  analogWrite(s2_pin, 0);
  analogWrite(s3_pin, 0);
  analogWrite(s4_pin, 0);

  // Set PWM pins as outputs
  pinMode(s1_pin, OUTPUT);
  pinMode(s2_pin, OUTPUT);
  pinMode(s3_pin, OUTPUT);
  pinMode(s4_pin, OUTPUT);
}

void loop() {
  // Boost mode: S1 closed, S2 switching
  analogWrite(s1_pin, 255);   // S1 closed
  analogWrite(s2_pin, 128);     // S2 switching at 50% duty cycle

  // Boost mode: S3 open, S4 switching (power runs from right to left)
  analogWrite(s3_pin, 0);   // S3 open
  analogWrite(s4_pin, 128);     // S4 switching
}
