/* Autor: Elena Chong
   Fecha: 31/enero/2018
   Título: Ejemplo básico de cómo utilizar el "Sensor PIR" SKU: SM0041
   Descripción: Este programa lee el sensor de movimiento pir y determina si hay movimiento. Si este detecta movimiento, entonces encendera el LED

   Conexión del PIR al Arduino Uno:
    OUT: pin 2
    VCC: 5V
    GND: GND
   Conexión del LED al Arduino Uno:
    - al GND
    + al resistor 220Ohm
    resistor al pin D13

   TINKERALL.COM
*/

// Definir
const int PIR = 2;  // pin 2 va a la señal del sensor de movimiento
const int LED = 13;
int pir_lectura = 0;

void setup() {
  // Configuración
  pinMode(LED, OUTPUT); // Configurar LED como salida o OUTPUT
  pinMode(PIR, INPUT);  // Configurar pir como entrada o INPUT
  Serial.begin(9600); // Configurar el puerto serial a 9600 por si queremos monitoriar
}

void loop() {
  // Código principal donde ocurren en loop

  // Encender LED si hay movimiento
  pir_lectura = digitalRead(PIR); //leer el pin del sensor de movimiento PIR
  if (pir_lectura == HIGH) {
    digitalWrite(LED, HIGH); // prende LED
    Serial.println("Movimiento detectado");
  }
  else {
    digitalWrite(LED, LOW); // apagar LED
    Serial.println("No hay movimiento");
  }
}

