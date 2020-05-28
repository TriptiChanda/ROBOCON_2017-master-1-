#include <Cytron_PS2Shield.h>
#include <SoftwareSerial.h>

Cytron_PS2Shield ps2(0,1);

int dirR1 = 33;
int dirR2 = 31;
int dirL1 = 35;
int dirL2 = 37;

int dirF1 = 27;
int dirF2 = 29;
int dirB1 = 23;
int dirB2 = 25;

int pwmR = 6;
int pwmL = 7;
int pwmF = 5;
int pwmB = 4;

int flagcr = 0;

void setup() 
{
  Serial.begin(9600);
  ps2.begin(9600);
  pinMode(dirR1 , OUTPUT);
  pinMode(dirR2 , OUTPUT);
  pinMode(dirL2 , OUTPUT);
  pinMode(dirL1 , OUTPUT);
  pinMode(dirF1,OUTPUT);
  pinMode(dirF2,OUTPUT);
  pinMode(dirB1,OUTPUT);
  pinMode(dirB2,OUTPUT);
  pinMode(pwmR,OUTPUT);
  pinMode(pwmL,OUTPUT);
  pinMode(pwmB,OUTPUT);
  pinMode(pwmF,OUTPUT);  
 
 
}

void loop()
{
//  Serial.println(ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS));
  // STOP
  //Cross
//  if(ps2.readButton(PS2_CROSS)== 0) //stop pressed
//  flagcr = 1;
//  if((ps2.readButton(PS2_CROSS) == 1 && flagcr == 1)) //stop
if ((ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS) > 120) && (ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS) < 132))
  {
    digitalWrite(dirR1 , HIGH);
    digitalWrite(dirR2 , HIGH);
    digitalWrite(dirL1 , HIGH);
    digitalWrite(dirL2 , HIGH);
    analogWrite(pwmR , 0);
    analogWrite(pwmL , 0);
    Serial.println("Stop");
    Serial.println("Cross");

    digitalWrite(dirF1 , HIGH);
    digitalWrite(dirF2 , HIGH);
    digitalWrite(dirB1 , HIGH);
    digitalWrite(dirB2 , HIGH);
    analogWrite(pwmF , 0);
//    analogWrite(pwmB , 0);    

    flagcr = 0;
  }

//    //CLOCKWISE
//    // Right Right Up
//
 if ((ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS) > 0) && (ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS) < 120))
  {
    digitalWrite(dirR1 , LOW);
    digitalWrite(dirR2 , HIGH);
    digitalWrite(dirL1 , HIGH);
    digitalWrite(dirL2 , LOW);
    digitalWrite(dirF1 , HIGH);
    digitalWrite(dirF2 , LOW);
    digitalWrite(dirB1 , LOW);
    digitalWrite(dirB2 , HIGH);
    analogWrite(pwmR , 100);
    analogWrite(pwmL , 100);
    analogWrite(pwmF , 100);
    analogWrite(pwmB , 100);
    Serial.println("CLOCKWISE");
    Serial.println("Right Up");
  }
//
//  //ANTICLOCKWISE
//  //Right Right Down
//
  if ((ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS) > 132) && (ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS) < 255))
  {
    digitalWrite(dirR1 , HIGH);
    digitalWrite(dirR2 , LOW);
    digitalWrite(dirL1 , LOW);
    digitalWrite(dirL2 , HIGH);
    digitalWrite(dirF1 , HIGH);
    digitalWrite(dirF2 , LOW);
    digitalWrite(dirB1 , HIGH);
    digitalWrite(dirB2 , LOW);
    analogWrite(pwmR , 100);
    analogWrite(pwmL , 100);
    analogWrite(pwmF , 100);
    analogWrite(pwmB , 100);
    Serial.println("ANTICLOCKWISE");
    Serial.println("Right Down");
  }
//
//  //LEFT
//  //Right left
//
//   if ((ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) >= 0) && (ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) <= 120) && (ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS) >= 120) && (ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS) <= 132))
//   {
//    digitalWrite(dirR1 , HIGH);
//    digitalWrite(dirR2 , LOW);
//    digitalWrite(dirL1 , HIGH);
//    digitalWrite(dirL2 , LOW);
//    analogWrite(pwmR , 255);
//    analogWrite(pwmL , 175);
//    Serial.println("FULL LEFT");
//    Serial.println("Right Left");
//
//    digitalWrite(dirF1 , HIGH);
//    digitalWrite(dirF2 , HIGH);
//    digitalWrite(dirB1 , HIGH);
//    digitalWrite(dirB2 , HIGH);
//  }
//
//  //LEFT 3
//  //Left Left Up
//   if ((ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) >= 0) && (ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) <= 120) && (ps2.readButton(PS2_JOYSTICK_LEFT_X_AXIS) >= 0) && (ps2.readButton(PS2_JOYSTICK_LEFT_X_AXIS) <= 120))
//    {
//    digitalWrite(dirR1 , HIGH);
//    digitalWrite(dirR2 , LOW);
//    digitalWrite(dirL1 , HIGH);
//    digitalWrite(dirL2 , LOW);
//    analogWrite(pwmR , 175);
//    analogWrite(pwmL , 175);
//    Serial.println("LEFT 3");
//    Serial.println("Left Left Up");
//
//    digitalWrite(dirF1 , HIGH);
//    digitalWrite(dirF2 , HIGH);
//    digitalWrite(dirB1 , HIGH);
//    digitalWrite(dirB2 , HIGH);
//  }
//
//  //LEFT 2
//  //Left Left
//  if ((ps2.readButton(PS2_JOYSTICK_LEFT_X_AXIS) >= 0) && (ps2.readButton(PS2_JOYSTICK_LEFT_X_AXIS) <= 120) && (ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) >= 120) && (ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) <= 132))
//  {
//    digitalWrite(dirR1 , HIGH);
//    digitalWrite(dirR2 , LOW);
//    digitalWrite(dirL1 , HIGH);
//    digitalWrite(dirL2 , LOW);
//    analogWrite(pwmR , 100);
//    analogWrite(pwmL , 100);
//    Serial.println("LEFT 2");
//    Serial.println("Left Left");
//
//    digitalWrite(dirF1 , HIGH);
//    digitalWrite(dirF2 , HIGH);
//    digitalWrite(dirB1 , HIGH);
//    digitalWrite(dirB2 , HIGH);
//  }
//
//  //LEFT 1
//  //Left Left Down
//  if ((ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) >= 132) && (ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) <= 255) && (ps2.readButton(PS2_JOYSTICK_LEFT_X_AXIS) >= 0) && (ps2.readButton(PS2_JOYSTICK_LEFT_X_AXIS) <= 120))
//  {
//    digitalWrite(dirR1 , HIGH);
//    digitalWrite(dirR2 , LOW);
//    digitalWrite(dirL1 , HIGH);
//    digitalWrite(dirL2 , LOW);
//    analogWrite(pwmR , 75);
//    analogWrite(pwmL , 75);
//    Serial.println("LEFT 1");
//    Serial.println("Left Left Down");
//
//    digitalWrite(dirF1 , HIGH);
//    digitalWrite(dirF2 , HIGH);
//    digitalWrite(dirB1 , HIGH);
//    digitalWrite(dirB2 , HIGH);    
//  } //END OF LEFT
//
//  // RIGHT
//  //Right Right
//  if ((ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) >= 132) && (ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) <= 255) && (ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS) >= 120) && (ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS) <= 132))
//  {
//    digitalWrite(dirR2 , HIGH);
//    digitalWrite(dirR1 , LOW);
//    digitalWrite(dirL2 , HIGH);
//    digitalWrite(dirL1 , LOW);
//    analogWrite(pwmR , 200);
//    analogWrite(pwmL , 200);
//    Serial.println("RIGHT FULL");
//    Serial.println("Right Right");
//
//    digitalWrite(dirF1 , HIGH);
//    digitalWrite(dirF2 , HIGH);
//    digitalWrite(dirB1 , HIGH);
//    digitalWrite(dirB2 , HIGH);    
//  }
//
//  //RIGHT 3
//  //Left Right Up
//  if ((ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) >= 0) && (ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) <= 120) && (ps2.readButton(PS2_JOYSTICK_LEFT_X_AXIS) >= 132) && (ps2.readButton(PS2_JOYSTICK_LEFT_X_AXIS) <= 255))
//  {
//    digitalWrite(dirR2 , HIGH);
//    digitalWrite(dirR1 , LOW);
//    digitalWrite(dirL2 , HIGH);
//    digitalWrite(dirL1 , LOW);
//    analogWrite(pwmR , 175);
//    analogWrite(pwmL , 175);
//    Serial.println("RIGHT 3");
//    Serial.println("Left Right Up");
//
//    digitalWrite(dirF1 , HIGH);
//    digitalWrite(dirF2 , HIGH);
//    digitalWrite(dirB1 , HIGH);
//    digitalWrite(dirB2 , HIGH);    
//  }
//
//  //RIGHT 2
//  //Left Right
//  if ((ps2.readButton(PS2_JOYSTICK_LEFT_X_AXIS) >= 132) && (ps2.readButton(PS2_JOYSTICK_LEFT_X_AXIS) <= 255) && (ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) >= 120) && (ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) <= 132))
//  {
//    digitalWrite(dirR2 , HIGH);
//    digitalWrite(dirR1 , LOW);
//    digitalWrite(dirL2 , HIGH);
//    digitalWrite(dirL1 , LOW);
//    analogWrite(pwmR , 100);
//    analogWrite(pwmL , 100);
//    Serial.println("RIGHT 2");
//    Serial.println("Left Right");
//
//    digitalWrite(dirF1 , HIGH);
//    digitalWrite(dirF2 , HIGH);
//    digitalWrite(dirB1 , HIGH);
//    digitalWrite(dirB2 , HIGH);    
//  }
//
//  //RIGHT 1
//  //Left Right Down
//  if ((ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) >= 132) && (ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) <= 255) && (ps2.readButton(PS2_JOYSTICK_LEFT_X_AXIS) >= 132) && (ps2.readButton(PS2_JOYSTICK_LEFT_X_AXIS) <= 255))
//  {
//    digitalWrite(dirR2 , HIGH);
//    digitalWrite(dirR1 , LOW);
//    digitalWrite(dirL2 , HIGH);
//    digitalWrite(dirL1 , LOW);
//    analogWrite(pwmR , 100);
//    analogWrite(pwmL , 100);
//    Serial.println("RIGHT 1");
//    Serial.println("Left Right Down");
//
//    digitalWrite(dirF1 , HIGH);
//    digitalWrite(dirF2 , HIGH);
//    digitalWrite(dirB1 , HIGH);
//    digitalWrite(dirB2 , HIGH);    
//  }//END OF RIGHT
//  
////DIFFERENTIAL RIGHT
////while right,forward
////Right Left Up
//  if ((ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS) >= 0) && (ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS) <= 120) && (ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) >= 0) && (ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) <= 120))
//  {
//    digitalWrite(dirR1 , LOW);
//    digitalWrite(dirR2 , HIGH);
//    digitalWrite(dirL1 , LOW);
//    digitalWrite(dirL2 , HIGH);
//    analogWrite(pwmR , 250);
//    analogWrite(pwmL , 250); 
//    Serial.println("Right forward 30");
//    Serial.println("Right Left Up");
//
//    digitalWrite(dirF1 , HIGH);
//    digitalWrite(dirF2, HIGH);
//    digitalWrite(dirB1 , HIGH);
//    digitalWrite(dirB2 , HIGH);    
//  }
//
//  
// //while right,backward
// //Right Left Down 
//  if ((ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS) >= 132) && (ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS) <= 255) && (ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) >= 0) && (ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) <= 120))
//  {
//    digitalWrite(dirR1 , LOW);
//    digitalWrite(dirR2 , HIGH);
//    digitalWrite(dirL1 , LOW);
//    digitalWrite(dirL2 , HIGH);
//    analogWrite(pwmR , 250);
//    analogWrite(pwmL , 250); 
//    Serial.println("Right backward 30");
//    Serial.println("Right Left Down");
//
//    digitalWrite(dirF1 , HIGH);
//    digitalWrite(dirF2 , HIGH);
//    digitalWrite(dirB1 , HIGH);
//    digitalWrite(dirB2 , HIGH);
//  }//END OF RIGHT DIFFERENTIAL
// 
// //LEFT DIFFERENTIAL
// //while left,forward
// //Left Up
//  if ((ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) >= 0) && (ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) <= 120) && (ps2.readButton(PS2_JOYSTICK_LEFT_X_AXIS) >= 120) && (ps2.readButton(PS2_JOYSTICK_LEFT_X_AXIS) <= 132))
//  {
//    digitalWrite(dirR1 , HIGH);
//    digitalWrite(dirR2 , LOW);
//    digitalWrite(dirL1 , HIGH);
//    digitalWrite(dirL2 , LOW);
//    analogWrite(pwmR , 200);
//    analogWrite(pwmL , 200); 
//    Serial.println("Left forward 30");
//    Serial.println("Left Up");
//
//    digitalWrite(dirF1 , HIGH);
//    digitalWrite(dirF2 , HIGH);
//    digitalWrite(dirB1 , HIGH);
//    digitalWrite(dirB2 , HIGH);    
//  }
//
//  
//  //while left, backward
//  //Left Down
//  if ((ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) >= 132) && (ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS) <= 255) && (ps2.readButton(PS2_JOYSTICK_LEFT_X_AXIS) >= 120) && (ps2.readButton(PS2_JOYSTICK_LEFT_X_AXIS) <= 132))
//  {
//    digitalWrite(dirR1 , HIGH);
//    digitalWrite(dirR2 , LOW);
//    digitalWrite(dirL1 , HIGH);
//    digitalWrite(dirL2 , LOW);
//    analogWrite(pwmR , 200);
//    analogWrite(pwmL , 250); 
//    Serial.println("Left backward 30");
//    Serial.println("Left Down");
//
//    digitalWrite(dirF1 , HIGH);
//    digitalWrite(dirF2 , HIGH);
//    digitalWrite(dirB1 , HIGH);
//    digitalWrite(dirB2 , HIGH);    
//  }//END OF LEFT DIFFERENTIAL
//
//  //FORWARD
//  //Right Up
//  if ((ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS) >= 0)  && (ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS) <= 120) && (ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) >= 120) && (ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) <= 132))
//  {
//    digitalWrite(dirR1 , HIGH);
//    digitalWrite(dirR2 , HIGH);
//    digitalWrite(dirL1 , HIGH);
//    digitalWrite(dirL2 , HIGH);
//    digitalWrite(dirF1 , HIGH);
//    digitalWrite(dirF2 , LOW);
//    digitalWrite(dirB1 , HIGH);
//    digitalWrite(dirB2 , LOW);
//    analogWrite(pwmR , 0);
//    analogWrite(pwmL , 0);
//    analogWrite(pwmF , 200);
//    analogWrite(pwmB , 200);
//    Serial.println("NEW FWD");
//    Serial.println("Right Up");
//
//    }
//  //BACKWARD
//  //Right Down
//  if ((ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS) >= 132)  && (ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS) <= 255) && (ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) >= 120) && (ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS) <= 132))
//  {
//    digitalWrite(dirR1 , HIGH);
//    digitalWrite(dirR2 , HIGH);
//    digitalWrite(dirL1 , HIGH);
//    digitalWrite(dirL2 , HIGH);
//    digitalWrite(dirF1 , LOW);
//    digitalWrite(dirF2 , HIGH);
//    digitalWrite(dirB1 , LOW);
//    digitalWrite(dirB2 , HIGH);
//    analogWrite(pwmR , 0);
//    analogWrite(pwmL , 0);
//    analogWrite(pwmF , 200);
//    analogWrite(pwmB , 200);
//    Serial.println("NEW BACK");
//    Serial.println("Right Down");
//   }
}

