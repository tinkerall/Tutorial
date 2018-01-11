/* Tinkerall.com
    Episodio 13: Melodia con Buzzer Pasivo.
    Descripción: Crear tonos de diversas frecuencias con el buzzer pasivo
    Autor: Elena Chong
    Fecha: 10 de enero del 2018

Conexión
Buzzer -------- Arduino Uno
Terminal + = PIN 8
Terminal - = GND

Agregar resistencia de 100 Ohm si suena alto, incrementar resistencia si aún suena alto.
Quitar resistencia si no suena bajo.
Nota: En el video no usé resistencia.
*/


//Declaración de las variables
int pBuzzer = 8; // pin del buzzer pasivo 
int cuarto = 1000 / 4; // tiempo de 1/4 de la nota
int octavo = 1000 / 8; // tiempo de 1/8 de la nota
double pausa = 1.30; // pausar el 30% de la nota

// La frecuencia min que puede producir el Arduino Uno es 31Hz.
// La frecuencia max que puede producir el Arduino Uno es 65,525Hz.
int NOTA_C4 = 262; // Frecuencia de la nota C4 es 262Hz
int NOTA_A4 = 440; // Frecuencia de la nota A4 es 440Hz
int NOTA_E5 = 659; // Frecuencia de la nota E5 es 659Hz

void setup() {
  // put your setup code here, to run once:
  pinMode(pBuzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  tone(pBuzzer, NOTA_C4, cuarto); //un cuarto de la nota C4.
  delay(cuarto*pausa); // silenciar por una duración de la nota previa + 30% de la duración de esa nota
  tone(pBuzzer, NOTA_A4, octavo); //un cuarto de la nota A4.
  delay(octavo*pausa); // silenciar por una duración de la nota previa + 30% de la duración de esa nota
  tone(pBuzzer, NOTA_E5, cuarto); //un cuarto de la nota E5.
  delay(cuarto*pausa); // silenciar por una duración de la nota previa + 30% de la duración de esa nota
}
