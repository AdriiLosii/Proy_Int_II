const int sensorPin = 9;
long contador = 0;

void setup() {
    Serial.begin(9600); //Iniciar puerto serie.
    pinMode(sensorPin, INPUT); //Definir pin como entrada de datos.
}

void loop() {
    int value = 0;

    value = digitalRead(sensorPin); //Lectura digital del pin.

    if (value == LOW) {
        //Serial.println("Optointerruptor activado");
        Serial.print("Contador activado");
        contador = contador + 1;
        Serial.println(contador);
    }
    delay(10);
}