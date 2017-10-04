const byte triggerPin = 3;
const byte echoPin = 2;
const byte ledOutputPin = 5;
const int amountOfDistances = 10;

int currentIter;
float lastAverage;
float averageDistance;
float lastDistances[amountOfDistances];
float distance;
float acumDistances;
float acceptedError;
unsigned long iterationsSinceLastSignal;

void setup() {
  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(ledOutputPin, OUTPUT); // Sets the echoPin as an Input
  for(int i = 0 ; i < amountOfDistances ; i++){
    lastDistances[i] = 0;
  }
  currentIter = 0;
  acceptedError = 0.1;
  iterationsSinceLastSignal = 0;
}

void clear() {
  // Clear trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
}

int getDistance() {
  // Read echo, get travel time
  long duration = pulseIn(echoPin, HIGH);

  // Calculate distance
  return duration * 0.034 / 2;
}

void sendUltrasonicSignal() {
  // Send signal for 10 micro seconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
}

void updateDistancesArray() {
  lastDistances[currentIter] = distance;
  currentIter = (currentIter + 1) % amountOfDistances;
}

void calcAverage() {
  acumDistances = 0;

  for(int i = 0 ; i < amountOfDistances ; i++) {
    acumDistances += lastDistances[i];
  }
  lastAverage = averageDistance;
  averageDistance = acumDistances / amountOfDistances;
}

bool shouldSendUserSignal() {
  return abs(averageDistance - lastAverage) > max(averageDistance, lastAverage) * acceptedError &&
      iterationsSinceLastSignal > amountOfDistances;
}

void printAverageData() {
  Serial.print("Last average: ");
  Serial.print(lastAverage);
  Serial.print(" Average: ");
  Serial.println(averageDistance);
}

void sendUserSignal() {
  Serial.println("Signal");
  digitalWrite(ledOutputPin, HIGH);
  delay(1000);
  digitalWrite(ledOutputPin, LOW);
  iterationsSinceLastSignal = 0;
}

void loop() {
  clear();

  sendUltrasonicSignal();

  distance = getDistance();

  updateDistancesArray();

  calcAverage();

  if(shouldSendUserSignal()) {
    sendUserSignal();
  }

  // printAverageData();

  iterationsSinceLastSignal++;
  delay(50);
}
