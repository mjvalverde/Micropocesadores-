
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"

MPU6050 mpu(0x68); // Puede ser 0x68 o 0x69
 
int x, y, z;  //variable donde se almacena los datos del acelerometro en todas las direcciones

long sensor = 0; //variable donde se sumaran las datos resividos


void setup() {
  
   Serial.begin(9600);    //se configura la velocidad del puerto serial en 9600 baudios para el acelerometro y el modulo bluetooth
   Wire.begin();
   mpu.initialize();
}
 
void loop() {

mpu.getAcceleration(&x, &y, &z);   // se leen los datos y se alacenan en las variables
sensor = pow(x,2) + pow(y,2) + pow(z,2); //Se suman los datos de las variables elevados al cuadrado

sensor = pow(sensor,0.5); //se eleva la raiz cuadrada de la suma de los valores leidos al cuadrado
  Serial.print("#");
  Serial.println(sensor/30);
//  delay(200);   //tiempo de sincronizacion
 }
