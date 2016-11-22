const int P = 13;
const int A = 10000000;
const int B = 10;

void setup()  {
  pinMode (P, OUTPUT);
}

void loop()  {
  digitalWrite (P, HIGH);
  delay(A);
  digitalWrite(P, LOW);
  delay(B);
}



