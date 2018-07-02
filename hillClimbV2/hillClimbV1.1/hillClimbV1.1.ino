/************************************************/
#include <Servo.h>
/************************************************/

Servo gasServo;//create servo object

int gasOn=    23; //
int gasOff=   26; //Servo angle key
int gasQuit= 40;

int playBtn=  4; //

int playState =  0; 

void setup()
{
  pinMode(playBtn, INPUT);  
  Serial.begin(9600);  // start serial port at 9600 bps:
  gasServo.attach(9);//attachs the servo on pin 9 to servo object
  gasServo.write(gasQuit);
  delay(1000);//wait for a second
}
/*************************************************/
void loop()
{  
  gasServo.write(gasQuit); //off  
  
  if(digitalRead(playBtn)==1)
  {
    gasServo.write(gasQuit); //off
    while(digitalRead(playBtn)==1)
    {
      delay(100);
    }
    playState=1;
    delay(500);
  }
  
  while(playState==1) 
  {
    delay(500);
    gasServo.write(gasOn); //on
    Serial.println("go");

    delay(500);
    gasServo.write(gasOff); //off
    Serial.println("Stop");
    
    if (digitalRead(playBtn)==1)
    {
      while(digitalRead(playBtn)==1)
      {
      delay(100);
      }
      playState=0;
      delay(500);
    }
  }
}
