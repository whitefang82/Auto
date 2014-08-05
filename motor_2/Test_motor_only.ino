int level;

void setup() {
  
  pinMode(22, OUTPUT); //Dir motor FL
  pinMode(23, OUTPUT); //Hand-brake motor FL 
  pinMode(24, OUTPUT); //Dir motor FL
  pinMode(25, OUTPUT); //Hand-brake motor FR
  pinMode(26, OUTPUT); //Dir motor FL
  pinMode(27, OUTPUT); //Hand-brake motor BL
  pinMode(28, OUTPUT); //Dir motor FL
  pinMode(29, OUTPUT); //Hand-brake motor BR
  
}

void loop(){
  
  level=30; // Gewindigkeit
  /*Dir HIGH: nach vorne
        LOW : nach hinter
    Brake HIGH: ON
          LOW : OFF*/
  digitalWrite(22, HIGH); 
  digitalWrite(23, LOW);   
  analogWrite(13, level);   
  
  digitalWrite(24, HIGH); 
  digitalWrite(25, LOW);   
  analogWrite(12, level);  
  
  digitalWrite(26, HIGH); 
  digitalWrite(27, LOW);   
  analogWrite(11, level);  
  
  digitalWrite(28, HIGH); 
  digitalWrite(29, LOW);   
  analogWrite(10, level);  
  
}

