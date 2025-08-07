void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.write("r");
  delay(3000);
  Serial.write("l");
  delay(3000);
}