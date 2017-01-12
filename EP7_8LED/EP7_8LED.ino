/* Autor: Elena Chong
   Fecha: 1/11/2017
   Titulo: Codigo del Episodio 7 de la serie de tutoriales para Arduino Basico de Tinkerall.
   Descripcion: Controlar 8 led con potenciometro.
   TINKERALL.COM
*/
int led2Pin = 2;      // definir pin de LED
int led3Pin = 3;      // definir pin de LED
int led4Pin = 4;      // definir pin de LED
int led5Pin = 5;      // definir pin de LED
int led6Pin = 6;      // definir pin de LED
int led7Pin = 7;      // definir pin de LED
int led8Pin = 8;      // definir pin de LED
int led9Pin = 9;      // definir pin de LED

int potPin = A0;    // pin de entrada para el potenciometro

int valorPot = 0;  // variable del valor del potenciometro

void setup() {
  // declarar pin de LED como salida
  pinMode(led2Pin, OUTPUT);  
  pinMode(led3Pin, OUTPUT);  
  pinMode(led4Pin, OUTPUT);  
  pinMode(led5Pin, OUTPUT);  
  pinMode(led6Pin, OUTPUT);  
  pinMode(led7Pin, OUTPUT);  
  pinMode(led8Pin, OUTPUT);  
  pinMode(led9Pin, OUTPUT);  

  // declarar pin del potenciometro como entrada
  pinMode(potPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  valorPot = analogRead(potPin);  
  Serial.print("Valor: ");
  Serial.println(valorPot);
  brillo();

}

void brillo() {

  if(valorPot >= 5 && valorPot <=125){
    digitalWrite(led2Pin, HIGH);
    digitalWrite(led3Pin, LOW);
    digitalWrite(led4Pin, LOW);  
    digitalWrite(led5Pin, LOW);  
    digitalWrite(led6Pin, LOW);  
    digitalWrite(led7Pin, LOW);  
    digitalWrite(led8Pin, LOW);  
    digitalWrite(led9Pin, LOW); 
  }
  else if(valorPot >= 126 && valorPot <=250){
    digitalWrite(led3Pin, HIGH);
    digitalWrite(led2Pin, LOW); 
    digitalWrite(led4Pin, LOW);  
    digitalWrite(led5Pin, LOW);  
    digitalWrite(led6Pin, LOW);  
    digitalWrite(led7Pin, LOW);  
    digitalWrite(led8Pin, LOW);  
    digitalWrite(led9Pin, LOW); 
  }
  else if(valorPot >= 251 && valorPot <=375){
    digitalWrite(led4Pin, HIGH); 
    digitalWrite(led2Pin, LOW);  
    digitalWrite(led3Pin, LOW);  
    digitalWrite(led5Pin, LOW);  
    digitalWrite(led6Pin, LOW);  
    digitalWrite(led7Pin, LOW);  
    digitalWrite(led8Pin, LOW);  
    digitalWrite(led9Pin, LOW);    
  }
  else if(valorPot >= 376 && valorPot <=500){
    digitalWrite(led5Pin, HIGH);   
    digitalWrite(led2Pin, LOW);  
    digitalWrite(led3Pin, LOW);  
    digitalWrite(led4Pin, LOW);  
    digitalWrite(led6Pin, LOW);  
    digitalWrite(led7Pin, LOW);  
    digitalWrite(led8Pin, LOW);  
    digitalWrite(led9Pin, LOW);  
  }
  else if(valorPot >= 501 && valorPot <=625){
    digitalWrite(led6Pin, HIGH);   
    digitalWrite(led2Pin, LOW);  
    digitalWrite(led3Pin, LOW);  
    digitalWrite(led4Pin, LOW);  
    digitalWrite(led5Pin, LOW);  
    digitalWrite(led7Pin, LOW);  
    digitalWrite(led8Pin, LOW);  
    digitalWrite(led9Pin, LOW);  
  }
  else if(valorPot >= 626 && valorPot <=750){
    digitalWrite(led7Pin, HIGH);    
    digitalWrite(led2Pin, LOW);  
    digitalWrite(led3Pin, LOW);  
    digitalWrite(led4Pin, LOW);  
    digitalWrite(led5Pin, LOW);  
    digitalWrite(led6Pin, LOW);  
    digitalWrite(led8Pin, LOW);  
    digitalWrite(led9Pin, LOW); 
  }
  else if(valorPot >= 750 && valorPot <=875){
    digitalWrite(led8Pin, HIGH);    
    digitalWrite(led2Pin, LOW);  
    digitalWrite(led3Pin, LOW);  
    digitalWrite(led4Pin, LOW);  
    digitalWrite(led5Pin, LOW);  
    digitalWrite(led6Pin, LOW);  
    digitalWrite(led7Pin, LOW);  
    digitalWrite(led9Pin, LOW); 
  }
  else if(valorPot >= 876 && valorPot <=1023){
    digitalWrite(led9Pin, HIGH); 
    digitalWrite(led2Pin, LOW);  
    digitalWrite(led3Pin, LOW);  
    digitalWrite(led4Pin, LOW);  
    digitalWrite(led5Pin, LOW);  
    digitalWrite(led6Pin, LOW);  
    digitalWrite(led7Pin, LOW);  
    digitalWrite(led8Pin, LOW);  
  } 

  else{
    digitalWrite(led2Pin, LOW);  
    digitalWrite(led3Pin, LOW);  
    digitalWrite(led4Pin, LOW);  
    digitalWrite(led5Pin, LOW);  
    digitalWrite(led6Pin, LOW);  
    digitalWrite(led7Pin, LOW);  
    digitalWrite(led8Pin, LOW);  
    digitalWrite(led9Pin, LOW);  
  }
}





