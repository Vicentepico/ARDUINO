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
  myServo.attach(9);
  pinMode(yellowled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(redled, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
  digitalWrite(greenled, HIGH);
  myServo.write(0); 
  Serial.println("La caja esta abierta");
}
void loop() {
  if(locked == false){
    switchVal = digitalRead(switchPin);+
    if(switchVal == HIGH){
      locked = true;
      digitalWrite(greenled, LOW);
      digitalWrite(redled, HIGH);
      myServo.write(90);
      Serial.println("La caja esta cerrada");
      delay (1000);
    }
  }
  if (locked == true) {
    knockVal = analogRead(piezo);
    if (numberOfKnocks < 3 && knockVal > 0){
      if(checkForKnock(knockVal) == true){
        numberOfKnocks++
      }
      Serial.print(3-numberOfKnocks);
      Serial.println("Moras golpes para ir");
    }
    if(numberOfKnocks >= 3){
      locked = false;
      myServo.write(0);
      delay(20);
      digitalWrite(greenled, HIGH);
      digitalWrite(redled, LOW);
      Serial.println("La caja esta abierta");
    }
  }
}
boolean checkForKnock(int value) {
  if (value > quietKnock && value < loudKnock) {
    digitalWrite (yellowled, HIGH);
    delay(50);
    digitalWrite(yellowled, LOW);
    serial.print("Valor de golpe valido");
    serial.println(value);
    return true;
  }
  else{
    serial.print("Golpe suave detectado");
    serial.println(value);
    retunr false;
  }
}