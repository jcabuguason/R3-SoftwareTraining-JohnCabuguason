#include <math.h>
int motorPWM = 0;

int rightMotorBackward = 6;
int rightMotorForward = 9;
int leftMotorBackward = 10;
int leftMotorForward = 11;
void setup()
{  
  pinMode(A0,INPUT);
  pinMode(5, INPUT);
  pinMode(4, INPUT_PULLUP);
  pinMode(3, INPUT);
  pinMode(2, INPUT);
  
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
   
  Serial.begin(9600);
}

void loop()
{
  //reads the potentiometer input 
  int pot = analogRead(A0);
  
  //maps the motor to inputtable pwm value
  motorPWM = map(pot,1023,0,1,255);  
  
  //check values of motorPWM
  Serial.print(motorPWM);
  Serial.print("\n");

  //dip switch 1 == ON , Mode 1: Forward Motion
  if(digitalRead(5)== HIGH){
    analogWrite(rightMotorForward,motorPWM);
    analogWrite(leftMotorForward,motorPWM);
  }
  // dip switch 2 == ON, Mode 2: Reverse Motion
  else if(digitalRead(4)== HIGH){
    analogWrite(rightMotorBackward,motorPWM);
    analogWrite(leftMotorBackward,motorPWM);
  }
  //dip switch 3 == ON, Mode 3: Turn Left Motion
  else if(digitalRead(3)== HIGH){
    analogWrite(rightMotorForward,motorPWM);
    analogWrite(leftMotorBackward,motorPWM);
  }
  //dip switch 4 == ON, Mode 4: Right Turn Motion
  else if(digitalRead(2)== HIGH){
    analogWrite(rightMotorBackward,motorPWM);
    analogWrite(leftMotorForward,motorPWM);
  }
  //all dip switch == OFF , Mode 5: Motors at Rest
  else{
    digitalWrite(leftMotorForward,LOW);
    digitalWrite(leftMotorBackward,LOW);
    digitalWrite(rightMotorForward,LOW);
    digitalWrite(rightMotorBackward,LOW);
  }
}