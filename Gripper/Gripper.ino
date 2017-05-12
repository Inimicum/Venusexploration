#include <Servo.h>
Servo GripperServo;
int gripperservopin = 10;
int Options = 0; 
 
int angle = 0;   // servo position in degrees 

// at 115 degrees the gripper is at it's most open

 
void setup() 
{  Serial.begin(9600);
  GripperServo.attach(gripperservopin);             
  GripperServo.write(0);             //One time recalibration to center
  Serial.print("Gripper Servo Check...");
} 

void gripper_open()
{ 
GripperServo.write(115);
}

void gripper_close()
{
GripperServo.write(0);
}



void loop() {
  Serial.print("Choose command:\n");
  
  Serial.print("1) Open\n");
  Serial.print("2) Close\n");
  Serial.print("3) Exit\n");
  while(Serial.available() == 0)  {}
  Options = Serial.read();
  Serial.write(Options);                    //Insert choice of option in terminal.
  switch (Options) {
     case '1': gripper_open();
     break;
     case '2': gripper_close();
     break;
     case '3': Serial.end();
     break;
  }
}

