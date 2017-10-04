// digitalWrite(p, v): manda v voltaje al pin p. v puede usarse con HIGH (5v) o LOW (0v).
// digitalRead(p): Lee el voltaje del pin p
// delay(t): Espera t milisegundos

void setup() {
  // Inicio de la comunicacion serial
  Serial.begin(9600); // (?)
}

void loop() {
  unsigned int delay_time = 500;
  Serial.println("Hello, world!");
  delay(delay_time);
}
