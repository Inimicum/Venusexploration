#include <Servo.h>
Servo USservo;                          //Initiate Ultra Sound Servo as USservo.
int angle = 0;                          //Initiate angle integer. Range 0-180 from Right to Left.
int USservoPin = 11;                    //Ultra Sound Servo is connected to pin 11 by default
int options = 0;                        //Used for selecting commands 1-3
void setup()                            // put your setup code here, to run once:

{ Serial.begin(9600);
  USservo.attach(USservoPin);             
  USservo.write(90);                      //One time recalibration to center
  Serial.print("Ultra Sound Servo Online. \n");
}

int Scout() {                         //Function gradually turning the neck from right to left
  Serial.print("\n");
  Serial.print("Scouting...");
  
  USservo.write(0);
  delay(500);
  USservo.write(30);
  delay(500);
  USservo.write(60);
  delay(500);
  USservo.write(90);
  delay(500);
  USservo.write(120);
  delay(500);
  USservo.write(180);                 //Scouting back might be redundant. To be discussed...
  delay(500);
  USservo.write(120);
  delay(000);
  USservo.write(90);
  delay(000);
  USservo.write(60);
  delay(000);
  USservo.write(30);
  delay(000);
  USservo.write(0);
 
  Serial.print("Scouting Complete.");
  return 0;
}

int ManualCtrl() {                       //Function for manually inserting angles
    Serial.print("Test");
    Serial.print("\n");
    if (Serial.available() > 0)  {
    angle = Serial.read();                  //Check for input between 0-180 for degrees, 90 being the center
    
    Serial.print("Insert angle between 0 and 180: ");
    USservo.write(angle);                   //input through terminal
    Serial.print(angle);
    Serial.print("\n");
    Serial.print("Angle set.");  
  }
  return 0;
}

void loop() {

  Serial.print("Choose command:\n");
  Serial.print("1) Scout\n");
  Serial.print("2) Manual\n");
  Serial.print("3) Exit\n");
  
  while(Serial.available() == 0) {}
  options = Serial.read();  
  Serial.write(options);                    //Insert choice of option in terminal.
  switch (options) {
     case '1': Scout();
     break;
     case '2': ManualCtrl();
     break;
     case '3': Serial.end();
     break;
     }
  Serial.print("\n");
}


