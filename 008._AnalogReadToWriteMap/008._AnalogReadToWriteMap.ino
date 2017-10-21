// map(value, fromLow, fromHigh, toLow, toHigh)

int ledPin = 5;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(A5);
  Serial.println(sensorValue);
  int mappedValue = map(sensorValue, 0, 1023, 0, 255);

  analogWrite(ledPin, mappedValue);

  delay(100);
}
