#include<Servo.h>
#include<EasyTransfer.h>
Servo servo1, servo2, servo3, servo4; //4 servos werden verbinden
int servoValx;
EasyTransfer ET;

struct RECEIVE_DATA_STRUCTURE{
  int servoValx;
};

RECEIVE_DATA_STRUCTURE txdata;

void setup(){
  Serial.begin(9600);
  // Serial.begin(115200);

  ET.begin(details(txdata), &Serial);
  // Servo
  servo1.attach(33, 900, 2100);  // servo FL
  servo2.attach(35, 900, 2100);  // servo FR
  servo3.attach(37, 900, 2100);  // servo BL
  servo4.attach(39, 900, 2100);  // servo BR
}

void loop(){
  
  if(ET.receiveData()){
    Serial.print(servoValx);
    if (servoValx <450)                  // nach Links
    {
      servo1.writeMicroseconds(2018);
      servo2.writeMicroseconds(1718);
      servo3.writeMicroseconds(1045);
      servo4.writeMicroseconds(1372);
    }
    if (servoValx >420 & servoValx <620)    // standby - geradeaus
    {
      servo1.writeMicroseconds(1595);
      servo2.writeMicroseconds(1535);
      servo3.writeMicroseconds(1440);
      servo4.writeMicroseconds(1550);
    }
    if (servoValx >850)                     // nach rechts
    {
      servo1.writeMicroseconds(1430);
      servo2.writeMicroseconds(1105);
      servo3.writeMicroseconds(1611);
      servo4.writeMicroseconds(1970);
    }
  }
}
