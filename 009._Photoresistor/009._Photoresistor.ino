unsigned int biggestInput;
unsigned int smallestInput;
const byte ledPin = 5;

void setup() {
  Serial.begin(9600);
  biggestInput = 0;
  smallestInput = 2000;
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(A5);
  biggestInput = sensorValue > biggestInput ? sensorValue : biggestInput;
  smallestInput = sensorValue < smallestInput ? sensorValue : smallestInput;

  int ledOutput = map(sensorValue, smallestInput, biggestInput, 255, 0);

  analogWrite(ledPin, ledOutput);

  delay(50);
}
