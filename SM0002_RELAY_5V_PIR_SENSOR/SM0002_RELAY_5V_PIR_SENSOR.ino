/* Autor: Elena Chong
   Fecha: Septiembre 11, 2016
   Titulo: Ejemplo básico de cómo utilizar el "Relay-5V" SKU: SM0002
   Descripcion: Este programa te permitira encender una lampara de si persive movimiento.

   Conexión del componente al Arduino Uno:
    S: pin 2
    +: 5V
    -: GND

   TINKERALL.COM
*/

// Definir
int relay = 2;    // pin 2 va la señal del relay
int mov = 3;  // pin 3 va a la señal del sensor de movimiento
int mov_lectura;

void setup() {
  // Configuración
  pinMode(relay, OUTPUT); // Configurar S como salida o OUTPUT
  pinMode(mov, INPUT);
  Serial.begin(9600); // Configurar el puerto serial a 9600 por si queremos monitoriar
}

void loop() {
  // Código principal donde ocurren en loop

  // Encender y apagar lámpara cada 1000ms
  //  digitalWrite(relay, HIGH); // envia señal alta al relay
  //  Serial.println("Relay accionado");
  //  delay(1000);           // 1 segundo
  //  digitalWrite(relay, LOW);  // envia señal baja al relay
  //  Serial.println("Relay no accionado");
  //  delay(1000);           // 1 segundo

  // Encender lámpara si hay movimiento
  mov_lectura = digitalRead(mov);
  if (mov_lectura == HIGH) {
    Serial.println("Movimiento detectado");
    digitalWrite(relay, HIGH);
  }
  else {
    Serial.println("No hay movimiento");
    digitalWrite(relay, LOW);

  }
}
