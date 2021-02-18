int senal;
int i = 0;
int vector[10];

void setup() {
  Serial.begin(9600);

}

void loop() {
  senal = analogRead(A0);
  Serial.print(i);
  Serial.print(",");
  Serial.print(senal);
  Serial.println(";");
  i = i + 1;
  delay(3);

}
