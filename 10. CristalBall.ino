#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int switchPin = 6;
int switchState = 0;
int previousSwitchState = 0;
int reply;
void setup() {
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);
  lcd.print("Hello, World!");
  lcd.setCursor(0, 1);
  lcd.print("la bola ");
}
void loop() {
  switchState = digitalRead(switchPin);
  if (switchState != prevSwitchState) {
    if (switchState == LOW) {
      reply = random(8);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("La bola dice:");
      lcd.setCursor(0, 1);
      switch (reply) {
        case 0:
          lcd.print("  Sí");
          break;
        case 1:
          lcd.print("  No");
          break;
        case 2:
          lcd.print("  Pregunta");
          break;
        case 3:
          lcd.print("  Definitivamente");
          break;
        case 4:
          lcd.print("  No lo creo");
          break;
        case 5:
          lcd.print("  Tal vez");
          break;
        case 6:
          lcd.print("  Seguro que sí");
          break;
        case 7:
          lcd.print("  Consulta más tarde");
          break;
        }
    }
  }
}
prevSwitchState = switchState;
}
