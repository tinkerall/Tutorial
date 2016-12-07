/* Autor: Elena Chong
   Fecha: Septiembre 10, 2016
   Titulo: Ejemplo básico de cómo utilizar el "Joystick de 2-Ejes con Botón" SKU: SM0001
   Descripcion: Este programa te permitira leer los valores de las los pines analogas del VRx y VRy y el pin digital del buton.
   VELOCIDAD Y BRILLO Y RESET
   
   Conexión del componente al Arduino Uno:
   GND --- GND
   +5V --- 5V
   VRx --- A0
   VRy --- A1
   SW  --- 2

   TINKERALL.COM
*/

// Definir
int horizontal_x = A0;
int vertical_y = A1;
int buton_z = 2;
int x, y, z;

void setup() {
  // Configuración
  pinMode(horizontal_x, INPUT); // Configurar VRx como entrada o input
  pinMode(vertical_y, INPUT); // Configurar VRy como entrada o input
  pinMode(buton_z, INPUT_PULLUP); // Configurar el buton con la resistencia pullup interna del arduino
  Serial.begin(9600); // Configurar el puerto serial a 9600
}

void loop() {
  // Código principal donde ocurren en loop
  x = analogRead(horizontal_x); // Leer pin analoga horizontal (valor 0 a 1023)
  y = analogRead(vertical_y);   // Leer pin analoga vertical (valor 0 a 1023)
  z = digitalRead(buton_z); // Leer pin digital del buton (valor 0 o 1)
  Serial.print("x= ");
  Serial.print(x, DEC); // Imprimir en el monitor serial
  Serial.print(", ");
  Serial.print("y= ");
  Serial.print(y, DEC);
  Serial.print(", ");
  Serial.print("z= ");

  Serial.println(z, DEC);
  delay(100);
}
