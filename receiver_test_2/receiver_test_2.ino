// RECIEVER
byte incomingByte,pot;

void setup() {

// start serial port at 19200 bps
Serial.begin(19200);

pinMode (5, OUTPUT);  // set led pin 5 to output
delay(1000);
}

void loop() {

 if (Serial.available()) {   // is there any information available on serial port ?
incomingByte = Serial.read(); // assign bytes to the variable ‘incomingByte’
Serial.println(int(incomingByte));
delay(1000);


}
analogWrite (5, incomingByte); //pwm led according to pot values
}
