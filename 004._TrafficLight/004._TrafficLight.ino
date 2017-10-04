byte redLightLed = 5;
byte yellowLightLed = 6;
byte greenLightLed = 7;

void setup() {
  Serial.begin(9600);
  pinMode(redLightLed, OUTPUT);
  pinMode(yellowLightLed, OUTPUT);
  pinMode(greenLightLed, OUTPUT);
}

void loop() {
  digitalWrite(greenLightLed, HIGH);
  delay(3000);

  for(int i = 0 ; i < 5 ; i++) {
    digitalWrite(greenLightLed, LOW);
    delay(200);
    digitalWrite(greenLightLed, HIGH);
    delay(200);
  }
  digitalWrite(greenLightLed, LOW);

  digitalWrite(yellowLightLed, HIGH);
  delay(1000);
  digitalWrite(yellowLightLed, LOW);

  digitalWrite(redLightLed, HIGH);
  delay(2000);
  digitalWrite(redLightLed, LOW);
}
