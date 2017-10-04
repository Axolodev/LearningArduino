byte pushButtonInputPins[3] = {2, 3, 4};
byte outputToLedPin = 7;
byte pushedButtonsCounter;
byte amountOfButtons;

void setup() {
  Serial.begin(9600);
  pinMode(outputToLedPin, OUTPUT);
  amountOfButtons = 3;
  for(int i = 0 ; i < amountOfButtons ; i++ ){
    pinMode(pushButtonInputPins[i], INPUT);
  }
}

void loop() {
  digitalWrite(outputToLedPin, digitalRead(2) + digitalRead(3) + digitalRead(4) >= 2);
  delay(400);
}
