/*
Descripción: Este programa nos permite ver la diferencia entre una resistencia pull-up y una resistencia pull-down. 
Fecha: 20 de diciembre de 2016
Autor: Elena Chong

Episodio 5, Serie de tutoriales para Arduino Básico
Tinkerall.com
*/




// Los constantes no cambian!
const int botonPin = 7;     // pin del botón con pull down
const int ledPin =  2;      // pin del LED con pull down

const int boton2Pin = 8;    // pin del botón con pull up
const int led2Pin = 4;      // pin del LED con pull up

// el valor de la variable puede cambiar!
int botonEstado = 0;         // variable para leer el estado del botón (0 ó 1)
int boton2Estado =0;

void setup() {
  // iniciamos los LED como SALIDAS
  pinMode(ledPin, OUTPUT);  
  pinMode(led2Pin, OUTPUT);  
  // iniciamos los botones como ENTRADAS
  pinMode(botonPin, INPUT);   
  pinMode(boton2Pin, INPUT);
  Serial.begin(9600);  // iniciamos el monitor serial con velocidad de 9600 baudrate.
}

void loop(){
  // leer estado de los botones:
  botonEstado = digitalRead(botonPin);
  boton2Estado = digitalRead(boton2Pin);

  // imprimir estado del botón en nuestro monitor serial.
  Serial.println(botonEstado); 
  Serial.println(boton2Estado); 

  // Si el estado del botón es alta o 1, prende el LED correspondiente. Sino, el LED se mantendrá apagado.
  if (botonEstado == HIGH) {     
    // turn LED on:    
    digitalWrite(ledPin, HIGH);  
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW); 
  }

  if (boton2Estado == HIGH) {     
    // turn LED on:    
    digitalWrite(led2Pin, HIGH);  
  } 
  else {
    // turn LED off:
    digitalWrite(led2Pin, LOW); 
  }




}

