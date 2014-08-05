#include <Servo.h>
#include <EasyTransfer.h>
EasyTransfer ET;


Servo myservo1;

Servo ST1; 

struct RECEIVE_DATA_STRUCTURE{
  int servo1val;
};

RECEIVE_DATA_STRUCTURE txdata;

void setup(){
  Serial.begin(9600);
  // Serial.begin(115200);

  ET.begin(details(txdata), &Serial);
  // Servo
  ST1.attach(32, 900, 2100);
}

void loop(){
  if(ET.receiveData()){
    Serial.println(txdata.servo1val);
    ST1.write(txdata.servo1val);
  }
}
