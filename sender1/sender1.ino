#include <EasyTransfer.h>
EasyTransfer ET;

const int joyV = A5;     // Achse X zu Pin A4

struct SEND_DATA_STRUCTURE{
int servoValx;
};

SEND_DATA_STRUCTURE txdata;

void setup(){
  Serial.begin(9600);
  //  Serial.begin(115200);
  ET.begin(details(txdata), &Serial);
}

void loop(){
  outputJoystick();  
  int servoVal = analogRead(joyV);  // lesen den wert
  txdata.servoValx = servoVal;
  ET.sendData();
}

void outputJoystick(){

    Serial.print(analogRead(joyV));
    Serial.println ("----------------");
}
