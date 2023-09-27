void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  delay(1); // Wait for 1 millisecond(s)
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  delay(1); // Wait for 1 millisecond(s)
}
