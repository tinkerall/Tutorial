/* Autor: Elena Chong
   Fecha: Septiembre 11, 2016
   Titulo: Ejemplo básico de cómo utilizar el "Relay-5V" SKU: SM0002
   Descripcion: Este programa te permitira utilizar el Relay como un switch para controlar el componente de carga.

   Conexión del componente al Arduino Uno:
    S: pin 2
    +: 5V
    -: GND

   TINKERALL.COM
*/

// Definir
int relay = 2;

void setup() {
  // Configuración
  pinMode(relay, OUTPUT); // Configurar S como salida o OUTPUT
  Serial.begin(9600); // Configurar el puerto serial a 9600 por si queremos monitoriar
}

void loop() {
  // Código principal donde ocurren en loop
  digitalWrite(relay, HIGH); // envia señal alta al relay
  Serial.println("Relay accionado");
  delay(1000);           // 1 segundo
  digitalWrite(relay, LOW);  // envia señal baja al relay
  Serial.println("Relay no accionado");
  delay(1000);           // 1 segundo

}
