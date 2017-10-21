byte incomingByte = 0;

void setup() {
  Serial.begin(9600);
}

void printByteInfo(byte byteInfo){
  // What did we get?
  Serial.print("Received: ");
  Serial.print((char) byteInfo);
  Serial.print(" \t ASCII: ");
  Serial.println(byteInfo, DEC);
}

void loop() {
  // Send data only when you receive data:
  if(Serial.available() > 0) {
    // read the incoming data
    incomingByte = Serial.read();

    if(incomingByte != '\n') {
      printByteInfo(incomingByte);
    }
  }
}
