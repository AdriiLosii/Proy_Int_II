int ENA = 7;
int IN1 = 8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;
int ENB = 12;

void setup(){

  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
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

  adelante(0);
  atras(0);
  giro_derecha(0);
  giro_izquierda(0);

  /*
  adelante(120);
  delay(2000);
  adelante(0);
  delay(500);
  atras(120);
  delay(2000);
  atras(0);
  delay(500);
  giro_derecha(120);
  delay(2000);
  giro_derecha(0);
  delay(500);
  giro_izquierda(120);
  delay(2000);
  giro_izquierda(0);
  delay(500);
  */
}