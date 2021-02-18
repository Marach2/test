#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);

/*CONEXIONES:
 * ARDUINO -------- DRIVER
 * ------------------------
 * 3.3V    -------- Vcc    
 * 5V      -------- V+
 * GND     -------- GND
 * A4      -------- SDA
 * A5      -------- SCL
 * 
 * 
 */
int senal;
unsigned int pos0=172; // ancho de pulso en cuentas para pocicion 0°
unsigned int pos180=565; // ancho de pulso en cuentas para la pocicion 180°

void setup() {
  Serial.begin(9600);
  servos.begin();  
  servos.setPWMFreq(60); //Frecuecia PWM de 60Hz o T=16,66ms
}

void setServo(uint8_t n_servo, int angulo) {
  int duty;
  duty=map(angulo,0,180,pos0, pos180);
  servos.setPWM(n_servo, 0, duty);  
}

void loop() {
    senal = analogRead(A0);
    Serial.println(senal);

    if(senal > 350){
    
    setServo(0,0);
    setServo(1,0);
    delay(1000);
    setServo(0,180);
    setServo(1,180);
    }
    delay(3);
    
}
