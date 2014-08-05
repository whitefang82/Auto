#include <EasyTransfer.h>
EasyTransfer ET;

const int potpin1 = A0;

struct SEND_DATA_STRUCTURE{
int servo1val;
};

SEND_DATA_STRUCTURE txdata;

void setup(){
  Serial.begin(9600);
  //  Serial.begin(115200);
  ET.begin(details(txdata), &Serial);
}

void loop(){

  int val1 = analogRead(potpin1)+1000;
  Serial.println(val1);
  txdata.servo1val = val1;

  ET.sendData();
}
