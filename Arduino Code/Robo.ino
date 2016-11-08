/* This code is Written by Rahul Bhatia
 * 
 */  

int LmotorUp = 10; //initialising Arduino port 10 be be called as LmotorUp
int LmotorDn = 11; //initialising Arduino port 11 be be called as LmotorDn
int RmotorUp = 8;  //initialising Arduino port 8 be be called as RmotorUp
int RmotorDn = 9;  //initialising Arduino port 9 be be called as RmotorDn
int left = 6;
int right = 12;




void setup()
{
  Serial.begin(9600);
  // Setting ports as OUTPUTS as they supply signal values to motor driver
  pinMode(LmotorUp,OUTPUT); 
  pinMode(LmotorDn,OUTPUT);
  pinMode(RmotorUp,OUTPUT);
  pinMode(RmotorDn,OUTPUT);
  pinMode(left,OUTPUT);
  pinMode(right,OUTPUT);
  // Begining statement because i can :P add your robot name in the print statement
  Serial.println("<Robot name> Welcomes you!"); 
  // A delay of 1 second for user 
  delay(1000);
} 
  

void loop()
{ 
  // Checking is Serial data available
  if(Serial.available()>0)
  {
    // Storing value of read data into variable assigned
    int input = Serial.read(); 
    switch(input)
    {
      // Calling respective functions if mathced with case label 
     case 'w' : MoveF(); 
     break;
     // Here is it important to use '' as that stores the ASCII value is the letter in the variable you can add CAPITAL letters 
     case 's' : MoveB(); 
     break;
     case 'a' : MoveL(); 
     break;
     case 'd' : MoveR();
     break;
     case 'x' : Stop();
     break;
     default : break;
    }
  } 
  delay(50);
}

void MoveF()
{
  // Telling user that the robot will move forward
  Serial.println("<Robot Name> Forward");
  
  // We are writing a Digital HIGH to the upper left pin of the motor driver for postive polarity of 5V
  digitalWrite(LmotorUp,HIGH); 
  // We are writing a Digital LOW to the lower left pin of the motor driver for negative polarity of 0V
  digitalWrite(LmotorDn,LOW);
  // We are writing a Digital HIGH to the upper right pin of the motor driver for postive polarity of 5V
  digitalWrite(RmotorUp,HIGH); 
  // We are writing a Digital HIGH to the lower right pin of the motor driver for negative polarity of 0V
  digitalWrite(RmotorDn,LOW);
  // For entering speed to the pins
  digitalWrite(left, 100);
  // We are writing a Digital LOW to the lower right pin of the motor driver
  digitalWrite(right, 100);
  
  // As a result the robot will move forward
}

void MoveB()
{
  // Telling user that the robot will move backward
  Serial.println("<Robot Name> Backward");
  
  // Reversing the Digital HIGH/LOW for all the pins of the moto driver exact opposite of the forward function MoveF
  digitalWrite(LmotorUp,LOW); 
  digitalWrite(LmotorDn,HIGH);
  digitalWrite(left, 100);
  digitalWrite(RmotorUp,LOW);
  digitalWrite(RmotorDn,HIGH);
  digitalWrite(right, 100);
  
}

void MoveL()
{
  // Telling user that the robot will move left
  Serial.println("<Robot Name> Left");
  // Completely stopping the left motor and allowing the right motor to move forward
  digitalWrite(LmotorUp,LOW); 
  digitalWrite(LmotorDn,LOW);
  // This will cause the robot to move left as the left motor will not move
  digitalWrite(right, 00);
  
  digitalWrite(RmotorUp,HIGH);
  digitalWrite(RmotorDn,LOW);
  digitalWrite(left, 100);
  
  // Result robot will move left as left motor is not moving
}

void MoveR()
{
  // Telling user that the robot will move right
  Serial.println("<Robot Name> Right");
  
  // Completely stopping the right motor and allowing the left motor to move forward
  digitalWrite(LmotorUp,HIGH);
  digitalWrite(LmotorDn,LOW);
  // This will cause the robot to move right
  digitalWrite(RmotorUp,LOW);
  digitalWrite(RmotorDn,LOW);
  digitalWrite(right, 100);
  digitalWrite(left, 00);
  
  // Result robot will move right as right motor is not moving
}

void Stop()
{
  // Telling user that the robot will move right
  Serial.println("<Robot Name> Stop");
  
  //Writing a digital LOW to all pins associated with movement of motor driver causes all motors to stop
  digitalWrite(LmotorUp,LOW);
  digitalWrite(LmotorDn,LOW);
  digitalWrite(RmotorUp,LOW);
  digitalWrite(RmotorDn,LOW);
  digitalWrite(right, 00);
  digitalWrite(left, 00);
  
  // Result robot will not move anywhere
}
