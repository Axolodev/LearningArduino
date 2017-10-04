const byte buttonInputPin = 7;
const byte triggerPin = 3;
const byte echoPin = 2;

bool buttonWasRecentlyPressed;
long duration;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(buttonInputPin, INPUT);
  pinMode(triggerPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  buttonWasRecentlyPressed = false;
}

void loop() {
  if(!buttonWasRecentlyPressed && digitalRead(buttonInputPin)) {
    buttonWasRecentlyPressed = true;

    // Clear trigger
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);

    // Send signal for 10 micro seconds
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    // Read echo, get travel time
    duration = pulseIn(echoPin, HIGH);

    // Calculate distance
    distance = duration * 0.034 / 2;

    Serial.print("Distance: ");
    Serial.println(distance);
  }
  if(!digitalRead(buttonInputPin)) {
    buttonWasRecentlyPressed = false;
  }
}
