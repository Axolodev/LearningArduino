byte buttonInputPin = 6;
bool buttonWasRecentlyPressed;

void setup() {
  Serial.begin(9600);
  pinMode(buttonInputPin, INPUT);
  buttonWasRecentlyPressed = false;
}

void loop() {
  if(!buttonWasRecentlyPressed && digitalRead(buttonInputPin)) {
    Serial.println("Pressed!");
    buttonWasRecentlyPressed = true;
  }
  if(!digitalRead(buttonInputPin)) {
    buttonWasRecentlyPressed = false;
  }
  delay(100);
}
