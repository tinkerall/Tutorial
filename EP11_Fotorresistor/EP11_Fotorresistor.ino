/* Tinkerall.com
    Episodio 11: Programar un sensor de luz o fotorresistor con el Arduino UNO.
    Descripción: Mapear la lectura del fotorresistor a un valor de 0 a 255 para utilizarlo para encender un LED con PWM.
    Autor: Elena Chong
    Fecha: 26 de abril del 2017
*/


const int FOTOPIN = A0;
int valorSensor = 0;
const int LED = 3;
int valorMapeado = 0;

void setup() {
  pinMode(FOTOPIN, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  valorSensor = analogRead(FOTOPIN);
  valorMapeado = map(valorSensor, 770, 240, 0, 255);
  analogWrite(LED, valorMapeado);

  Serial.print("Valor del Sensor: ");
  Serial.println(valorSensor);
  Serial.print("Valor del Sensor Mapeado: ");
  Serial.println(valorMapeado);

}
