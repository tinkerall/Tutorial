/* Autor: Elena Chong
   Fecha: 1/11/2017
   Titulo: 8 LED PWM para el Episodio 8 de la serie de tutoriales para Arduino Basico de Tinkerall.
   Descripcion: Prender 8 leds con parpadeo para identificar pin digitales con y sin PWM.
   TINKERALL.COM
*/
int potPin = A0;    // pin de entrada para el potenciometro
int ledPin = 0;     // variable para almacenar pin presente
int ledPinAnterior = 0; // variable para almacenar pin anterior
int brillo = 0;     // variable para incrementar el brillo del led
int valorPot = 0;  // variable del valor del potenciometro
int intervalo = 5;    // variable con intervalo para cambiar intensidad del brillo del led

void setup() {
  // declarar pines 2 a 9 de los LEDs como salidas usando for loop
  for(ledPin = 2; ledPin <= 9; ledPin++){
    pinMode(ledPin, OUTPUT);
  }

  // declarar pin del potenciometro como entrada
  pinMode(potPin, INPUT);
  // iniciar el monitor serial con velocidad de 9600
  Serial.begin(9600);
}

void loop() {
  // leer valor del potenciometro
  valorPot = analogRead(potPin);  
  // imprimir el valor en el monitor serial
  Serial.print("Valor: ");
  Serial.println(valorPot);
  
  ledPin = map(analogRead(potPin), 0, 1023, 2, 9); // convertir los valores del potenciometro linealmente al pin correspondiente.
  
  // condicion IF, asegura que solo un led este prendido a la vez
  if(ledPin != ledPinAnterior){
    digitalWrite(ledPinAnterior, LOW);
  }
  analogWrite(ledPin, brillo); // mandando señal analoga al led presente 
  
  brillo = brillo + intervalo; // la variable brillo se actualiza en cada ciclo para que incremente en intervalo de 5.
  if(brillo == 0 || brillo == 255){ // si brillo igual a 0 ó 255, entonces
    intervalo = -intervalo;
  }
  delay(3);

  // actualizar led presente y led anterior por si rotamos el potenciometro en este ciclo.
  ledPinAnterior = ledPin; 
}



