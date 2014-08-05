int val;
int new_val;

void setup()
{
// start serial port at 19200 bps
Serial.begin(19200);
}

void loop()
{
// read analog input
val = analogRead(0);

// remap values
new_val = map(val, 0, 1023, 253, 0); 

Serial.write(val);     //SYNC char
Serial.print(new_val);
delay(150);
}
