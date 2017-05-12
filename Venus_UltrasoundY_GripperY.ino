/* INITIALIZATION */
#include <Servo.h>
Servo USservo;
Servo GripperServo;

int USservoPin = 11; 
const int pingPin = 9;
int gripperservopin = 10;
int Options = 0; 
int USangle = 0; 
/* END INITIALIZATION */

/* GRIPPER FUNCTIONS */
void gripper_open()
{GripperServo.attach(gripperservopin);
GripperServo.write(115);}

void gripper_close()
{ GripperServo.attach(gripperservopin);
  GripperServo.write(0);}
/* END GRIPPER FUNCTIONS */

/* ULTRA SOUND FUNCTIONS */  
int ultrasound_pos_read(int USangle){
  long duration, USdistance;
  USservo.attach(USservoPin);

  USservo.write(USangle); //Angle 0-180 from R-L
  
  Serial.print("Ultrasound Angle");
  Serial.println(USangle);
  
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  
  USdistance = duration / 58 ; // distance = v_sound*duration/2

  Serial.print("Obstacle distance: ");
  Serial.println(USdistance);
  return(USdistance);}
/* END ULTRA SOUND FUNCTIONS */


 void setup(){
  Serial.begin(9600);
  Serial.println("Hello");
  
  }
 void loop(){
//    ultrasound_pos_read(180);
//  gripper_open();
//  delay(750);
//  ultrasound_pos_read(0);
//  gripper_close();
//  delay(750);
}
