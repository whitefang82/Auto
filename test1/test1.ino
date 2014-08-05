float posix;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() >= 21) {
    if (Serial.read() == 0x7E) {
      for (int i=1; i<19;i++) {
        
      
      byte discardByte = Serial.read();}
    }  
    int analogMSB = Serial.read();
    int analogLSB = Serial.read();
    int analogReading = analogLSB + ( analogMSB * 256);
    Serial.print(analogReading);
  }
}
