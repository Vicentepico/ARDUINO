const int SwitchPin = 2;
const int motorPin = 9;
int SwitchState = 0;
void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(SwitchPin, INPUT);
}
void loop() {
  SwitchState = digitalRead(SwitchPin);
  if (SwitchState == HIGH) {
    digitalWrite(motorPin, HIGH);
  } else {
    digitalWrite(motorPin, LOW);
  }
}