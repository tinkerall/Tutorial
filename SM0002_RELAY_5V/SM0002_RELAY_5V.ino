/* Autor: Elena Chong
   Fecha: Septiembre 11, 2016
   Titulo: Ejemplo básico de cómo utilizar el "Relay-5V" SKU: SM0002
   Descripcion: Este programa te permitira utilizar el Relay como un switch para controlar la fuente de alimentacion para el componente de carga.

   Conexión del componente al Arduino Uno:
    S: pin 2
    +: 5V
    -: GND

   TINKERALL.COM
*/

// Definir
int s = 2;

void setup() {
  // Configuración
  pinMode(s, OUTPUT); // Configurar S como salida o OUTPUT
  Serial.begin(9600); // Configurar el puerto serial a 9600
}

void loop() {
  // Código principal donde ocurren en loop
  digitalWrite(s, HIGH); // envia señal alta al relay
  delay(1000);           // 1 segundo
  digitalWrite(s, LOW);  // envia señal baja al relay
  delay(1000);           // 1 segundo
  
}
