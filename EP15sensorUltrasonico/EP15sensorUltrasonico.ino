/*
   Autor: Elena Chong
   Fecha: Enero 24, 2017
   Descripción: Sensor ultrasónico para medir distancia de un objeto frente a ella.
*/

//Definir
const int trigPin = 2;
const int ecoPin = 4;
long duracion;
int distancia;
void setup() {
  // Configuración
  pinMode(trigPin, OUTPUT); // Definir trigPin como salida
  pinMode(ecoPin, INPUT); // Definir ecoPin como entrada
  Serial.begin(9600); // Activar comunicación serial
}
void loop() {
  // Código principal donde ocurren en loop
  // Obtener valores
  digitalWrite(trigPin, LOW); // Mandar señal baja para limpiar la señal de cualquier residuo
  delayMicroseconds(4); // por 4 micro segundos.
  digitalWrite(trigPin, HIGH); // Mandar señal (pulso) alta en el trigPin
  delayMicroseconds(10); // de 10 micro segundos.
  digitalWrite(trigPin, LOW);// mandar señal baja
  // Computación
  duracion = pulseIn(ecoPin, HIGH); // Escuchar el pulso de regreso (eco) y determinar el tiempo de viaje de ella en micro segundos.
  distancia = duracion * 0.034 / 2; // Interpretar el tiempo a distancia
  Serial.print("Distancia: "); // Imprimir distancia en cm en la comunicación serial
  Serial.print(distancia);
  Serial.println("cm");
}

