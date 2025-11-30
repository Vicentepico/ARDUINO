#include <Servo.h>
Servo myServo;
const int piezo = A0;
const int switchPin = 2;
const int yellowled = 3;
const int greenled = 4;
const int redled = 5;
int knockVal;
int switchVal;
const int quietKnock = 10;
const int loudKnock = 100;
boolean locked = false;
int numberOfKnocks = 0;
void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  myServo.attach(servoPin);
  myServo.write(0); // Cerrado
}

void loop() {
  buttonState = digitalRead(buttonPin);

  // Detecta cambio de estado del botón
  if (buttonState == LOW && lastButtonState == HIGH) {
    locked = !locked; // Cambia el estado del cerrojo

    if (locked) {
      myServo.write(0);   // Cerrado
    } else {
      myServo.write(90);  // Abierto
    }
    delay(500); // Evita rebotes
  }
  lastButtonState = buttonState;
}