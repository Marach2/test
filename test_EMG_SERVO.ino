#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

//Constantes
int VALOR_LIMITE = 400;
int TIEMPO_DELANTE = 30;

//Declaración servos
Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);
unsigned int pos0 = 172;
unsigned int pos180 = 565;

//Declaracion variables EMG
int senal;
int i = 0;
int vector[10];

//Declaracion de variable contador
int contador = 0;


void setup() {
  Serial.print("inicio SETUP");
  Serial.begin(9600);
  servos.setPWMFreq(60); //Frecuencia de 60Hz
  Serial.print("config OK");
}

void setServo(uint8_t n_servo, int angulo) {
  int duty;
  duty=map(angulo,0,180,pos0, pos180);
  servos.setPWM(n_servo, 0, duty);
}

void loop() {
  
  senal = analogRead(A0);
  Serial.println(senal);
  /*Serial.print(",");
  Serial.print(senal);
  Serial.println(";");*/
  //i = i + 1;
  
  if(senal > VALOR_LIMITE) {
    setServo(0,180);
    setServo(1, 180);
    contador = 0;
  } else {
    if (contador > TIEMPO_DELANTE)
    setServo(0,0);
    setServo(1, 0);
  }
  contador++;
  delay(3);
}
