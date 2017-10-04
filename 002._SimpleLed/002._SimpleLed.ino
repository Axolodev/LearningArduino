unsigned int ledPin = 10;
unsigned int delayTime = 1000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

int getDelayTime(){
  return random (300, 1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(ledPin, HIGH);
  delay(getDelayTime());
  
  digitalWrite(ledPin, LOW);
  delay(getDelayTime());  
}
