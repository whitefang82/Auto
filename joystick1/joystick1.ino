#include <Servo.h>      //hinzufügen den library servo

const int joyV = 4;     // Achse X zu Pin A4

int servoVal;           // variable für joystick's position

Servo servo1, servo2, servo3, servo4; //4 servos werden verbinden

void setup() {
  // Servo  
  servo1.attach(33, 900, 2100);  // servo FL
  servo2.attach(35, 900, 2100);  // servo FR
  servo3.attach(37, 900, 2100);  // servo BL
  servo4.attach(39, 900, 2100);  // servo BR
  // Serial
  Serial.begin(9600);
}

void loop(){
    servoVal = analogRead(joyV);  // lesen den wert
    /*Der Wert geht von 0 bis 1023 -> von Links nach rechts
    beim 1. Versuch liegt der Mittelwert zwischen 750-812*/
    if (servoVal <420)                  // nach Links
    {
      servo1.writeMicroseconds(2018);
      servo2.writeMicroseconds(1718);
      servo3.writeMicroseconds(1045);
      servo4.writeMicroseconds(1372);
    }
    if (servoVal >420 & servoVal <620)    // standby - geradeaus
    {
      servo1.writeMicroseconds(1595);
      servo2.writeMicroseconds(1535);
      servo3.writeMicroseconds(1440);
      servo4.writeMicroseconds(1550);
    }
    if (servoVal >620)                     // nach rechts
    {
      servo1.writeMicroseconds(1430);
      servo2.writeMicroseconds(1105);
      servo3.writeMicroseconds(1611);
      servo4.writeMicroseconds(1970);
    }
}


