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
 0 für Error - keybounce 
 00 - 0
 01 - 0
 10 - -1
 11 - 1 */
 int bump[] = {0,0,-1,1}; 

 void setup(){
    speed = 0; // Anfangwert = die Geschwindigkeit der Motoren
    /* Set-up für Serial Monitor, um den wert zu kontrollieren */
    Serial.begin(115200); // beachten monitor baud rate has das gleiche
    Serial.println("Encoder Ready"); // Im Serial Monitor 
    Serial.print("level = ");
    Serial.println(level); // 
    pinMode(pinA,INPUT); // Pin A & B von encoder sind input Typ
    pinMode(pinB,INPUT);
    digitalWrite(pinA,HIGH);
    digitalWrite(pinB,HIGH); 
    
    attachInterrupt(0,knopfTurned,RISING); // wenn pin A HIGH ist, wird knopfTurned() ausgelöst
    
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
}

 void knopfTurned(){
    state = 0; // diesen Wert zurücksetzen
    state = state + digitalRead(pinA); // state von Pin A addieren
    state <<= 1; // state von pin A auf einer Seite verschieben
   state = state + digitalRead(pinB); // state von  Pin B hinzufügen
   
   /* Dieser 2 states binden zur 1 binary nummer, es gibt 4 Möglichkeiten 
   00 - Key bounce
   01 - Key bounce - knopfTurned wird ausgelöst, wenn pin A RISING/ HIGH ist,
       d.h, es darf nicht 0 sein
   10 - knopf ist rückwärt gedrht 
   11 - knob ist vorwärt gedreht */
   
  /*  bits array == bump array
         00      --    0
         01      --    0
         10      --   -1
         11      --    1  */
   level = level + bump[state] * 2; //(*2) wenn knopf gedreht ist, addiert/subtrahiert der aktuelle Wert 2, statt 1
   Serial.print(bits[state] + "   "); // bits im Monitor zeigen
   Serial.print(bump[state],DEC); // bump oder Richtung im Decimal im Monitor zeigen
   Serial.print("   ");
   Serial.println(level); // neuen Wert zwigen
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
