String data;
byte ledPin = 10;
const String LED_ON_COMMAND = "LED ON";
const String LED_OFF_COMMAND = "LED OFF";
const String BLINK_COMMAND = "BLINK";

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void processByte(byte byteData) {
  if(byteData != 10) {
    data += (char) byteData;
  } else {
    processCommand();
    Serial.println(data);
    data = "";
  }
}

void processCommand() {
  if(data.equals(LED_ON_COMMAND)) {
    digitalWrite(ledPin, HIGH);
  }
  if(data.equals(LED_OFF_COMMAND)) {
    digitalWrite(ledPin, LOW);
  }
  if(data.equals(BLINK_COMMAND)){
    for(int i = 0 ; i < 5 ; i++) {
      digitalWrite(ledPin, HIGH);
      delay(100);
      digitalWrite(ledPin, LOW);
      delay(100);
    }
  }
}

void loop() {
  while(Serial.available()){
    byte received = Serial.read();
    processByte(received);
  }
}
