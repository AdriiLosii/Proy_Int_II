const int sensorPin = 9;
int valor;
int val_analogico;

void setup() {
    pinMode(sensorPin, INPUT);
    pinMode(A1, INPUT);
    Serial.begin(9600);
}

void loop() {
    valor = digitalRead(sensorPin);

    val_analogico = analogRead(A1);
    Serial.print(val_analogico);
    Serial.print(" ");
    Serial.println(valor);
}