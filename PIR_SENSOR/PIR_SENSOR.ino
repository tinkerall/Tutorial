/* Autor: Elena Chong
   Fecha: 15 de noviembre de 2016
   Titulo: Ejemplo básico de cómo utilizar el "Sensor PIR" SKU: SM0002
   Descripcion: Este programa te permitira prender una LED al persibir movimiento.

   Conexión del PIR al Arduino Uno:
    OUT: pin 2
    VCC: 5V
    GND: GND
   Conexión del LED al Arduino Uno:
    - al GND
    + al resistor 220Ohm

   TINKERALL.COM
*/

// Definir
int pir = 2;  // pin 2 va a la señal del sensor de movimiento
int led = 13;
int pir_lectura;
int pir_estado = LOW; // iniciar estado del pir como no detección

void setup() {
  // Configuración
  pinMode(led, OUTPUT); // Configurar led como salida o OUTPUT
  pinMode(pir, INPUT);  // Configurar pir como entrada o INPUT
  Serial.begin(9600); // Configurar el puerto serial a 9600 por si queremos monitoriar
}

void loop() {
  // Código principal donde ocurren en loop

  // Encender LED si hay movimiento
  pir_lectura = digitalRead(pir);
  if (pir_lectura == HIGH) {
    digitalWrite(led, HIGH); // prende LED
    if (pir_estado == LOW) {
      Serial.println("Movimiento detectado");
      pir_estado = HIGH;
    }
  }
  else {
    digitalWrite(led, LOW); // apagar LED
    if (pir_estado == HIGH) {
      Serial.println("No hay movimiento");
    }
    pir_estado = LOW;
  }
}
