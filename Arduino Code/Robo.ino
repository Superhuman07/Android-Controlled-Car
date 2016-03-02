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
  pinMode(LmotorUp,OUTPUT);//Setting ports as OUTPUTS as they 
  pinMode(LmotorDn,OUTPUT);//supply signal values to motor driver
  pinMode(RmotorUp,OUTPUT);
  pinMode(RmotorDn,OUTPUT);
  pinMode(left,OUTPUT);
  pinMode(right,OUTPUT);
  Serial.println("<Robot name> Welcomes you"); //begining statement because i can :P
  delay(1000);
} 
  

void loop()
{
  if(Serial.available()>0)//Checking is Serial data available
  {
    int input = Serial.read(); //Storing value of read data into variable assigned
    switch(input)
    {
     case 'w' : MoveF(); //Calling respective functions if mathced with case label 
     break;
     case 's' : MoveB(); // here is it important to use '' as that stores the ASCII value is the letter in the variable
     break;
     case 'a' : MoveL(); // and hence we can use the int keyword
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
  Serial.println("<Robot Name> Forward");
  
  
  digitalWrite(LmotorUp,HIGH); //As said in video we are writing a Digital HIGH to the upper left pin of the motor driver
  digitalWrite(LmotorDn,LOW);//As said in video we are writing a Digital LOW to the lower left pin of the motor driver
  digitalWrite(RmotorUp,HIGH); //As said in video we are writing a Digital HIGH to the upper right pin of the motor driver
  digitalWrite(RmotorDn,LOW);
  digitalWrite(left, 100);
  digitalWrite(right, 100);//As said in video we are writing a Digital LOW to the lower right pin of the motor driver
  
  // As a result the robot will move forward
}

void MoveB()
{
  Serial.println("<Robot Name> Backward");
  digitalWrite(LmotorUp,LOW); //Reverse logic of above
  digitalWrite(LmotorDn,HIGH);
  digitalWrite(left, 100);
  digitalWrite(RmotorUp,LOW);
  digitalWrite(RmotorDn,HIGH);
  digitalWrite(right, 100);
  
}

void MoveL()
{
  Serial.println("<Robot Name> Left");
  digitalWrite(LmotorUp,LOW); //we are completely stopping the left motor and allowing the right motor to move forward
  digitalWrite(LmotorDn,LOW);
  digitalWrite(right, 00);//this will cause the robot to move left
  digitalWrite(RmotorUp,HIGH);
  digitalWrite(RmotorDn,LOW);
  digitalWrite(left, 100);
}

void MoveR()
{
  Serial.println("<Robot Name> Right");
  digitalWrite(LmotorUp,HIGH);//we are completely stopping the right motor and allowing the left motor to move forward
  digitalWrite(LmotorDn,LOW);//this will cause the robot to move right
  digitalWrite(RmotorUp,LOW);
  digitalWrite(RmotorDn,LOW);
  digitalWrite(right, 100);
  digitalWrite(left, 00);
}

void Stop()
{
  Serial.println("<Robot Name> Stop");
  digitalWrite(LmotorUp,LOW);//Writing a digital LOW to all pins associated with movement of motor driver causes all motors to stop
  digitalWrite(LmotorDn,LOW);
  digitalWrite(RmotorUp,LOW);
  digitalWrite(RmotorDn,LOW);
  digitalWrite(right, 00);
  digitalWrite(left, 00);
}
