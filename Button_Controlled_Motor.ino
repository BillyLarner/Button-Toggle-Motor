int relayPin = 9; // the number of the relay pin
int buttonPin = 12; // the number of the button pin
int buttonState = HIGH; // record button state, and initial the state to high
int relayState = LOW; // Record relay state, and initial the state to low
int lastButtonState = HIGH; // Record the button state of last detection
long lastChangeTime = 0; // Record the time the button was pressed

void setup() {
 pinMode(buttonPin, INPUT); // Sets button pin to an input
 pinMode(relayPin, OUTPUT); // Sets relay pin to an output
 digitalWrite(relayPin, relayState); // Set the initial state of relay to low
 Serial.begin(9600); // Initialize serial port,and set baud rate to 9600
}

void loop() {
 int nowButtonState = digitalRead(buttonPin); // Read current state of button pin
 // If button pin state has changed, record the time it was changed
 if (nowButtonState != lastButtonState) {
  lastChangeTime = millis();
 }
 if (millis() - lastChangeTime > 10) {
  if (buttonState != nowButtonState) { // Confirm button has been pressed
  buttonState = nowButtonState;
    if (buttonState == LOW) { // when pressed the button is set to low
    relayState = !relayState; // invert the value of relay state
    digitalWrite(relayPin, relayState); // Update relay state
    Serial.println("Button is Pressed!");
  }
  else { // button is currently high and not pressed
  Serial.println("Button is Released!");
      }
    }
 }
 lastButtonState = nowButtonState; // Save the state of last button press
}
