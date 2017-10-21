const byte triggerPin = 3;
const byte echoPin = 2;

long duration, distance;

void setup() {
  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);

  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  distance = duration / 58.82;

  Serial.print(distance);
  Serial.println(" cm");
  delay(50);
}
