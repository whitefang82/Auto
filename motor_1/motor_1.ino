/*************************************************************
Motor Shield 1-Channel DC Motor Demo
by Randy Sarafan

For more information see:
http://www.instructables.com/id/Arduino-Motor-Shield-Tutorial/

*************************************************************/

int level;

void setup() {
  
  //Setup Channel A
  pinMode(13, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(8, OUTPUT); //Initiates Brake Channel A pin
  pinMode(11, OUTPUT); //Initiates Motor Channel A pin
  pinMode(7, OUTPUT); //Initiates Brake Channel A pin
  pinMode(10, OUTPUT); //Initiates Motor Channel A pin
  pinMode(6, OUTPUT); //Initiates Brake Channel A pin
  
}

void loop(){
  
  level=30;
  
  digitalWrite(13, HIGH); //Establishes forward direction of Channel A
  digitalWrite(9, LOW);   //Disengage the Brake for Channel A
  analogWrite(32, level);   //Spins the motor on Channel A at full speed
  
  digitalWrite(12, HIGH); //Establishes forward direction of Channel A
  digitalWrite(8, LOW);   //Disengage the Brake for Channel A
  analogWrite(34, level);   //Spins the motor on Channel A at full speed
  
  digitalWrite(11, HIGH); //Establishes forward direction of Channel A
  digitalWrite(7, LOW);   //Disengage the Brake for Channel A
  analogWrite(36, level);   //Spins the motor on Channel A at full speed
  
  digitalWrite(10, HIGH); //Establishes forward direction of Channel A
  digitalWrite(6, LOW);   //Disengage the Brake for Channel A
  analogWrite(38, level);   //Spins the motor on Channel A at full speed
  
}

