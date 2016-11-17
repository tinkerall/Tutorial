/* Autor: Elena Chong
   Fecha: 16 de noviembre de 2016
   Título: Ejemplo básico de cómo utilizar el sensor ultrasónico HC-SR04 SKU: SM0040
   Descripción: Este programa calcula la distancia en centímetro de un objeto frente al sensor.

   Conexión del sensor HC-SR04 al microcontrolador Uno:
    TRIG: pin 2
    VCC: 5V
    GND: GND
    ECHO: pin 4

   TINKERALL.COM
*/

//Definir
const int trigPin = 2;
const int echoPin = 4;
long duration;
int distance;

void setup() {
  // Configuración
  pinMode(trigPin, OUTPUT); // Definir trigPin como salida
  pinMode(echoPin, INPUT); // Definir echoPin como entrada
  Serial.begin(9600); // Activar comunicación serial
}
void loop() {
  // Código principal donde ocurren en loop

  // Obtener valores
  digitalWrite(trigPin, LOW);   // Mandar señal baja para limpiar la señal de cualquier residuo
  delayMicroseconds(4);         // por 4 micro segundos.
  digitalWrite(trigPin, HIGH);  // Mandar señal (pulso) alta en el trigPin
  delayMicroseconds(10);        // de 10 micro segundos.
  digitalWrite(trigPin, LOW);

  // Computación
  duration = pulseIn(echoPin, HIGH); // Escuchar el pulso de regreso (eco) y determinar el tiempo de viajen de ella en micro segundos.
  distance = duration * 0.034 / 2; // Interpretar el tiempo a distancia
  Serial.print("Distancia: ");   // Imprimir distancia en cm en la comunicación serial
  Serial.print(distance);
  Serial.println("cm");
}
