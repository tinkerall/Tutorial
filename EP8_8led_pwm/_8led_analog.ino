int potPin = A0;    // pin de entrada para el potenciometro
int ledPin = 0;
int ledPinAnterior = 0;
int brillo = 0;
int valorPot = 0;  // variable del valor del potenciometro
int apagar = 5;

void setup() {
  // declarar pines 2 a 9 de LED como salidas
  for(ledPin = 2; ledPin <= 9; ledPin++){
    pinMode(ledPin, OUTPUT);
  }

  // declarar pin del potenciometro como entrada
  pinMode(potPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  valorPot = analogRead(potPin);  
  Serial.print("Valor: ");
  Serial.println(valorPot);
  ledPin = map(analogRead(potPin), 0, 1023, 2, 9); // convertir los valores del potenciometro linealmente al pin correspondiente.
  
  if(ledPin != ledPinAnterior){
    digitalWrite(ledPinAnterior, LOW);
  }
  analogWrite(ledPin, brillo);
  
  brillo = brillo + apagar;
  if(brillo == 0 || brillo == 255){
    apagar = -apagar;
  }
  delay(3);

  ledPinAnterior = ledPin;
}

void brilloFuncion() {
  

}






