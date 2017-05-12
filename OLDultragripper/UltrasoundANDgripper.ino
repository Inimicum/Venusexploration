#include <Servo.h>
Servo USservo;
Servo GripperServo;
  int USservoPin = 11; 
const int pingPin = 9;
int gripperservopin = 10;
int Options = 0; 
 
int angle = 0; 

void gripper_open()
{ 
GripperServo.write(115);
}

void gripper_close()
{
GripperServo.write(0);
}

  
int ultrasound_value(){
   long duration, cm;

  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  cm = duration / 58 ;
  return(cm);
  }

  void ultrasound_position(int x){
    USservo.attach(USservoPin);  
    USservo.write(x); //Angle 0-180 from R-L
    
    }
  
void setup() {
      Serial.begin(9600);
      ultrasound_position(180);
      delay(2000);
      GripperServo.attach(gripperservopin);             
      GripperServo.write(0);   
      Serial.println(ultrasound_value());
    }

void loop() {
  gripper_open();
  delay(2000);
  gripper_close();
  delay(2000);

}
