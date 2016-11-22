const int potpin = 0;
const int WAIT = 100;
void setup(){
  Serial.begin(9600);
  
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  
  pinMode(potpin, INPUT);
}

void loop(){
  int val;
  int dval;
  
  val = analogRead(potpin);
  dval = val/171;
  
  Serial.print("From POT: ");
  Serial.println(val);
  Serial.print("Decimal value conversion: ");
  Serial.println(dval);
  
  int bitval = dval & 1;
  digitalWrite(13, bitval);
  dval = dval >> 1;
  bitval = dval & 1;
  digitalWrite(12, bitval);
  dval = dval >> 1;
  bitval = dval & 1;
  digitalWrite(11, bitval);
  
  delay(WAIT);
}
