byte pushButtonInputPin = 2;
byte outputToLedPin = 5;
bool buttonPressed = false;

void setup() {
  Serial.begin(9600);
  pinMode(outputToLedPin, OUTPUT);
  pinMode(pushButtonInputPin, INPUT);
}

void loop() {
  /*
  buttonPressed = digitalRead(pushButtonInputPin);

  if(buttonPressed) {
    digitalWrite(outputToLedPin, HIGH);
  } else {
    digitalWrite(outputToLedPin, LOW);
  }*/

  digitalWrite(outputToLedPin, digitalRead(pushButtonInputPin));
}
