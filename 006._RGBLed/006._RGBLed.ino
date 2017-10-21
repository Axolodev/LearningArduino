const byte redLedPin = 5;
const byte greenLedPin = 6;
const byte blueLedPin = 9;
const byte delayTime = 2;

void setup() {
  Serial.begin(9600);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  analogWrite(redLedPin, 255);
}

void loop() {

  for(int i = 0 ; i < 255 ; i++) {
    analogWrite(blueLedPin, i);
    delay(delayTime);
  }

  for(int i = 255 ; i >= 0 ; i--) {
    analogWrite(redLedPin, i);
    delay(delayTime);
  }

  for(int i = 0 ; i < 255 ; i++) {
    analogWrite(greenLedPin, i);
    delay(delayTime);
  }

  for(int i = 255 ; i >= 0 ; i--) {
    analogWrite(blueLedPin, i);
    delay(delayTime);
  }

  for(int i = 0 ; i < 255 ; i++) {
    analogWrite(redLedPin, i);
    delay(delayTime);
  }

  for(int i = 255 ; i >= 0 ; i--) {
    analogWrite(greenLedPin, i);
    delay(delayTime);
  }
}
