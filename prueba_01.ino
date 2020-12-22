/* Servo motor with Arduino example code. Position and sweep. More info: https://www.makerguides.com/ */
// Include the servo library:
#include <Servo.h>
// LAS CONEXIONES NO SE REALIZAN A PINES ANALÓGICOS, SI NO A PWM (PINES DIGITALES CON EL SÍMBOLO "~").
// Create a new servo object:
Servo servoPeq;
Servo servoPeq1;
Servo servoGra1;
Servo servoGra2;

// Define the servo pin:
#define servoPinPeq 3 //Pequeño
#define servoPinPeq1 9
#define servoPinGra1 10
#define servoPinGra2 11

// Create a variable to store the servo position:
int angle = 0;

void setup() {
  // Attach the Servo variable to a pin:
  servoPeq.attach(servoPinPeq);
  servoPeq1.attach(servoPinPeq1);
  servoGra1.attach(servoPinGra1);
  servoGra2.attach(servoPinGra2); 
}

void loop() {
  // Tell the servo to go to a particular angle:
  servoPeq.write(0);
  //servoPeq1.write(0);
  //servoGra1.write(0);
  //servoGra2.write(0); 
    
  while(angle <= 180) {
    servoPeq.write(angle);
    //servoPeq1.write(angle);
    //servoGra1.write(angle);
    //servoGra2.write(angle);  
    angle++;
  }
  delay(3500);
  
  while(angle >= 0) {
    servoPeq.write(angle);
    //servoPeq1.write(angle);
    //servoGra1.write(angle);
    //servoGra2.write(angle);  
    angle--;
  }

  delay(3500);
  
}
