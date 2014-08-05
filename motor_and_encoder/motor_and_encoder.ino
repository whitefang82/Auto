 const byte pinA = 2; // encoder pin A to Arduino pin 2, Interrupt Pin
 const byte pinB = 3; // encoder pin B to Arduino pin 3

 byte state = 0; // Anfangwert von  Pin A & B

 int speed; // speed ist intergers

 /*array von 4 state, je nach Veränderung von Pin A & B, in Binary 
 erste Nummer gehört zu entweder Pin A & 2. Nummer gehört zu Pin B oder umgekehrt */
 String bits[] = {"00","01","10","11"};

 /* wenn 
 Mögliche Bewegung 
 1 für Uhrzeigersinn
 -1 für Gegenuhrzeigersinn
 0 für Error - keybounce */
 int bump[] = {0,0,-1,1}; 

 void setup(){
    speed = 0; // Anfangwert = die GEschwindigkeit der Motoren
    /* Set-up für Serial Monitor, um den wert zu kontrollieren */
    Serial.begin(115200); // beachten monitor baud rate has das gleiche
    Serial.println("Encoder Ready"); // Im Serial Monitor 
    Serial.print("level = ");
    Serial.println(level); // 
    pinMode(pinA,INPUT); // Pin A & B von encoder sind input Typ
    pinMode(pinB,INPUT);
    /* Writing to an Input pin turns on an internal pull up resistor */
    digitalWrite(pinA,HIGH);
    digitalWrite(pinB,HIGH); 
    /* Set up to call our knob function any time pinA rises */
    attachInterrupt(0,knobTurned,RISING); // wenn pin A HIGH ist, verwendet knobTurned()
    
    pinMode(22, OUTPUT); //Direction motor FL
    pinMode(23, OUTPUT); //Hand-brake motor FL 
    pinMode(24, OUTPUT); //Dir motor FL
    pinMode(25, OUTPUT); //Hand-brake motor FR
    pinMode(26, OUTPUT); //Dir motor FL
    pinMode(27, OUTPUT); //Hand-brake motor BL
    pinMode(28, OUTPUT); //Dir motor FL
    pinMode(29, OUTPUT); //Hand-brake motor BR
 }

 void loop(){
 if (speed > 0) {
  forward;
 }
 else {
 backward;
 }

 void knobTurned(){
 /* AH HA! the knob was turned */
    state = 0; // reset this value each time
    state = state + digitalRead(pinA); // add the state of Pin A
    state <<= 1; // shift the bit over one spot
   state = state + digitalRead(pinB); // add the state of Pin B 
   /* now we have a two bit binary number that holds the state of both pins 
   00 - something is wrong we must have got here with a key bounce 
   01 - sames as above - first bit should never be 0 
   10 - knob was turned backwards 
   11 - knob was turned forwards */
  /* We can pull a value out of our truth table and add it to the current level */
   level = level + bump[state]; /* Let's see what happened */
   Serial.print(bits[state] + "   "); // show us the two bits
   Serial.print(bump[state],DEC); // show us the direction of the turn
   Serial.print("   ");
   Serial.println(level); // show us the new value
}
 void forward(){
 /* Richtung vorwärt */
  digitalWrite(22, HIGH); 
  digitalWrite(24, HIGH); 
  digitalWrite(26, HIGH); 
  digitalWrite(28, HIGH);
  
 /*Gesschwindigkeit = speed */
  analogWrite(13, speed);   
  analogWrite(12, speed);  
  analogWrite(11, speed);  
  analogWrite(10, speed);
 }
 
 void backward(){
 
 
 /* Richtung rückwärt */
  digitalWrite(22, LOW); 
  digitalWrite(24, LOW); 
  digitalWrite(26, LOW); 
  digitalWrite(28, LOW); 
   /* Da arduino weiss, dass motor rückwärt spinnen müssen
 , aber speed muss possiv Zahl sein. Deshalb ist * (-1) nötig */ 
  int backwardSpeed = speed * (-1);
  
 /*Gesschwindigkeit = backwardSpeed */
  analogWrite(13, backwardSpeed);   
  analogWrite(12, backwardSpeed);  
  analogWrite(11, backwardSpeed);  
  analogWrite(10, backwardSpeed);
  
 }
