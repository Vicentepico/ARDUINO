int switchState = 0; // Variable to hold the state of a switch

void setup() {
    pinMode(3, OUTPUT); // Set pin 3 as an output
    pinMode(4, OUTPUT);  // Set pin 4 as an input
    pinMode(5, OUTPUT);  // Set pin 5 as an input
    pinMode(2, INPUT);  // Set pin 2 as an input
}

void loop() {
    switchState = digitalRead(2); // Read the state of the switch connected to pin 2

    if (switchState == LOW) {
        digitalWrite(3, HIGH); // Activate the output on pin 3
        digitalWrite(4, LOW);  // Activate the output on pin 4
        digitalWrite(5, LOW);  // Activate the output on pin 5
    } else {
        digitalWrite(3, LOW);  // Deactivate the output on pin 3
        digitalWrite(4, LOW); // Deactivate the output on pin 4
        digitalWrite(5, HIGH); // Deactivate the output on pin 5

        delay(250); // Delay for 250 milliseconds

        digitalWrite(4, HIGH); // Activate the output on pin 4
        digitalWrite(5, LOW);  // Deactivate the output on pin 5   
        delay(250); // Delay for 250 milliseconds
    }
}