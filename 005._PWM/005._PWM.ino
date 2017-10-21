const byte ledPin = 10;
const byte delayTime = 5;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for(int i = 0 ; i < 255 ; i++) {
    analogWrite(ledPin, i);
    delay(delayTime);
  }

  for(int i = 255 ; i >= 0 ; i--) {
    analogWrite(ledPin, i);
    delay(delayTime);
  }
}
