const int joyV = 4;     // Achse X zu Pin A4

int servoVal;           // variable für joystick's position

void setup() {
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  servoVal = analogRead(joyV);
  delay(250);
   Serial.println(analogRead(joyV));
}
