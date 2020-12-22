#include <Servo.h>

// Create a new servo object:
Servo servoPeq;
Servo servoPeq1;
Servo servoGra1;
Servo servoGra2;


// Create a variable to store the servo position:
int pos = 0;

void setup() {
  // Attach the Servo variable to a pin:
  servoPeq.attach(3);
  servoPeq1.attach(9);
  servoGra1.attach(10);
  servoGra2.attach(11); 
  Serial.begin(9600);
  
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) 
   {
      servoPeq.write(pos);
      Serial.println(pos);              
      delay(15);                       
   }
 
   //varia la posicion de 0 a 180, con esperas de 15ms
   for (pos = 180; pos >= 0; pos -= 1) 
   {
      servoPeq.write(pos);
      Serial.println(pos);               
      delay(15);                       
   }
}
