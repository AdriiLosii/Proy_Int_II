#include <Servo.h>

//Declaramos la variable para controlar el servo.
Servo servoMotor;

void ajuste_inicial()
{
  //Desplazamos a la posicion 0º
  servoMotor.write(0);
  //Esperamos 1 segundo
  delay(1000);
}

void setup(){
  //Iniciamos el monitor serie para mostrar el resultado
  Serial.begin(9600);
  
  //Iniciamos el servo para que empiece a trabajar con el pin 9
  servoMotor.attach(9);
  ajuste_inicial();
}

void tres_angulos(){
  //Desplazamos a la posición 0º
  servoMotor.write(0);
  //Esperamos 3 segundos
  delay(3000);
  
  //Desplazamos a la posición 90º
  servoMotor.write(90);
  //Esperamos 4 segundo
  delay(4000);
  
  //Desplazamos a la posición 180º
  servoMotor.write(180);
  //Esperamos 5 segundo
  delay(5000);
}

void vigilancia()
{
  //Para el sentido positivo
  for (int i = 0; i <= 180; i++){
    //Desplazamos al ángulo correspondiente
    servoMotor.write(i);
    //Hacemos una pausa de 25ms
    delay(25);
  }
  
  //Para el sentido negativo
  for (int i = 179; i > 0; i--){
    //Desplazamos al ángulo correspondiente
    servoMotor.write(i);
    //Hacemos una pausa de 25 ms
    delay(25);
  }
}

void loop(){
 //tres_angulos();
  vigilancia();
}