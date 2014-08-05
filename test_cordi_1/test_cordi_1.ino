void setup() {
  Serial.begin(19200);
}

void loop() {
  
  if (Serial.available()) {
    Serial.println(Serial.read());
    delay(100);
    }
}
