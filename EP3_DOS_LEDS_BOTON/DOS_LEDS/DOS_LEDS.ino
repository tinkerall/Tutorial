const int ledIzq = 4;
const int ledDer = 2;
const int boton = 7;

int estado = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledIzq, OUTPUT);
  pinMode(ledDer, OUTPUT);
  pinMode(boton, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
//  digitalWrite(ledIzq, HIGH);
//  digitalWrite(ledDer, LOW);
//  delay(500);
//  digitalWrite(ledIzq, LOW);
//  digitalWrite(ledDer, HIGH);
//  delay(500);

  estado = digitalRead(boton);

  if(estado == HIGH) {
    digitalWrite(ledIzq, HIGH);
    digitalWrite(ledDer, HIGH);
  }
  else{
    digitalWrite(ledIzq, LOW);
    digitalWrite(ledDer, LOW);
  }


}
