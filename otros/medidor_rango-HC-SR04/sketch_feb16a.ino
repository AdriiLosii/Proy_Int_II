const int Echo=6;
const int Trigger=7;
int distancia;

void setup() {
  Serial.begin(9600);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  digitalWrite(Trigger, LOW);
}

int detecta_sensor(){
  long tiempo;
  long distancia;

  digitalWrite(Trigger, LOW);
  delayMicroseconds(5);
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(15);
  digitalWrite(Trigger, LOW);

  tiempo=pulseIn(Echo, HIGH);
  distancia=tiempo/0.01657;
  
  return distancia;
}


void loop() {

  distancia=detecta_sensor();
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println("cm");

  delay(100);
}