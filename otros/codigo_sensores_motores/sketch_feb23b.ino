int ENA = 7;
int IN1 = 8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;
int ENB = 12;
const int EchoD = A1;
const int TriggerD = A0;
const int EchoT = A5;
const int TriggerT = A4;

void setup(){
  Serial.begin(9600);

  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);

  pinMode (TriggerT, OUTPUT);
  pinMode (EchoT, INPUT);
  digitalWrite (TriggerT, LOW);

  pinMode (TriggerD, OUTPUT);
  pinMode (EchoD, INPUT);
  digitalWrite (TriggerD, LOW);
}

int detecta_sensor_trasero() {
   long t;
   long d_trasero;
   digitalWrite(TriggerT,LOW);
   delayMicroseconds(5);
   digitalWrite(TriggerT,HIGH);
   delayMicroseconds(15);
   digitalWrite(TriggerT,LOW);
   t=pulseIn(EchoT,HIGH);
   d_trasero=t*0.01657;
   return (d_trasero);
}

int detecta_sensor_delantero() {
   long t;
   long d_delantero;
   digitalWrite(TriggerD,LOW);
   delayMicroseconds(5);
   digitalWrite(TriggerD,HIGH);
   delayMicroseconds(15);
   digitalWrite(TriggerD,LOW);
   t=pulseIn(EchoD,HIGH);
   d_delantero=t*0.01657;
   return (d_delantero);
}

void adelante (int vel){

  //Ruedas izquierdas
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW); //Direccion
  analogWrite(ENA, vel); //Velocidad

  //Ruedas derechas
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW); //Direccion
  analogWrite(ENB, vel); //Velocidad
}

void atras (int vel){

  //Ruedas izquierdas
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH); //Direccion
  analogWrite(ENA, vel); //Velocidad

  //Ruedas derechas
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH); //Direccion
  analogWrite(ENB, vel); //Velocidad
}

void giro_derecha (int vel){

  //Ruedas izquierdas (hacia atras)
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW); //Direccion
  analogWrite(ENA, vel); //Velocidad

  //Ruedas derechas (hacia adelante)
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH); //Direccion
  analogWrite(ENB, vel); //Velocidad
}

void giro_izquierda (int vel){

  //Ruedas izquierdas (hacia adelante)
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH); //Direccion
  analogWrite(ENA, vel); //Velocidad

  //Ruedas derechas (hacia atras)
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW); //Direccion
  analogWrite(ENB, vel); //Velocidad
}

void loop(){

  delay(5000);
  
  //Mostramos en la consola los datos.
  Serial.print("Distancia delantera: ");
  Serial.println(detecta_sensor_delantero());
   Serial.print("Distancia trasera: ");
  Serial.println(detecta_sensor_trasero());
  
  adelante(80);
  
  /*if (detecta_sensor_trasero() < 50 and detecta_sensor_delantero() < 50){
      adelante(0);
      atras(0);
      giro_derecha(0);
      giro_izquierda(0);
    }*/
    //else {
        if (detecta_sensor_trasero() < detecta_sensor_delantero() and detecta_sensor_delantero() > 50){
          adelante(80);
        }
        else if (detecta_sensor_trasero() > detecta_sensor_delantero() and detecta_sensor_trasero() > 50){
          atras(80);
        }
        else{
          adelante(0);
          atras(80);
          delay(1000);
          giro_derecha(120);
          delay(2000);
          adelante(80);
        }
      
      //Habría que contemplar la posibilidad de que la distancia trasera y delantera coincidieran,
      //ya que el robot ahora mismo lo que hará será ir hacia adelante y hacia atrás hasta llegar al medio.
    //}
}