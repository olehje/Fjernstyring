#include <UCMotor.h>
UC_DCMotor leftMotor1(3, MOTOR34_64KHZ);
UC_DCMotor rightMotor1(4, MOTOR34_64KHZ);
UC_DCMotor leftMotor2(1, MOTOR34_64KHZ);
UC_DCMotor rightMotor2(2, MOTOR34_64KHZ);

#include "IRLibAll.h"
IRrecvPCI myReceiver(2);
IRdecode myDecoder;  

#include <Ultrasonic.h>
Ultrasonic ultrasonic(A2, A3);

bool moving_forward = false;

void setup() {
  Serial.begin(9600);
  
  myReceiver.enableIRIn(); // Start the receiver
}
 
void loop() {
  int  dist = ultrasonic.distanceRead();

  if (dist < 40 && moving_forward == true){
     right();
     delay(1200);
     brake();
  }

  if (myReceiver.getResults()) {
    myDecoder.decode();         
    unsigned long value = myDecoder.value;
    myReceiver.enableIRIn();      //Restart receiver

    Serial.print("0x"); Serial.println(value ,HEX);

    switch(value){
      
      //Sony remote
      
      case 0x10 :
      Serial.println("1"); 
      break;
      
      case 0x810:
      Serial.println("2");
      forward();
      break;
      
      case 0x410:
      Serial.println("3");
      break;
      
      case 0xC10:
      Serial.println("4");
      left();
      break;
      
      case 0x210:
      Serial.println("5");
      brake();
      break ;  
      
      case 0xA10:
      Serial.println("6");
      right();
      break ;        
      
      case 0x610:
      Serial.println("7");
      break;
      
      case 0xE10:
      Serial.println("8");
      back();
      break ;  
      
      case 0x110:
      Serial.println("9");
      break ;            
/////////////////////////////////////// Robotcar remote

      case 0xFFA25D:
      Serial.println("1"); 
      forward();
      break;
      case 0xFF629D:
      Serial.println("2");
      forward();
      break;
      case 0xFFE21D:
      Serial.println("3");
      break;
      case 0xFF22DD:
      Serial.println("4");
      left();
      break;
      case 0xFF02FD:
      Serial.println("5");
      brake();
      break ;  
      case 0xFFC23D:
      Serial.println("6");
      right();
      break ;               
      case 0xFFE01F:
      Serial.println("7");
      break ;  
      case 0xFFA857:
      Serial.println("8");
      back();
      break ;  
      case 0xFF906F:
      Serial.println("9");
      break ;  
      case 0xFF6897:
      Serial.println("*");
      break ;  
      case 0xFF9867:
      Serial.println("0");
      break ;
      case 0xFFB04F:
      Serial.println("#");
      break ;
      case 0xFF18E7:
      Serial.println("up");
      break ;
      case 0xFF10EF:
      Serial.println("left");
      break ;
      case 0xFF38C7:
      Serial.println("OK");
      break ;
      case 0xFF5AA5:
      Serial.println("right");
      break ;
      case 0xFF4AB5:
      Serial.println("down");
      break ;          
/////////////////////////////////////////// BTV remote
      case 0x1202:
      forward();
      break ;           
      
      case 0x1A04:
      left();
      break ;           
      
      case 0x1205:
      brake();
      break ;           
      
      case 0x1A06:
      right();          
      break ;           
      
      case 0x1208:
      back();          
      break ; 
    }
  }
}

void right(){
  leftMotor1.run(0x04); rightMotor1.run(0x04);
  leftMotor2.run(0x04); rightMotor2.run(0x04);
  leftMotor1.setSpeed(200); rightMotor1.setSpeed(200);
  leftMotor2.setSpeed(200); rightMotor2.setSpeed(200);

  moving_forward = false;
}
  
void left(){
  leftMotor1.run(0x03); rightMotor1.run(0x03);
  leftMotor2.run(0x03); rightMotor2.run(0x03);
  leftMotor1.setSpeed(200); rightMotor1.setSpeed(200);
  leftMotor2.setSpeed(200); rightMotor2.setSpeed(200);

  moving_forward = false;
}

void forward(){
  leftMotor1.run(0x01); rightMotor1.run(0x01);
  leftMotor2.run(0x01); rightMotor2.run(0x01);
  leftMotor1.setSpeed(200); rightMotor1.setSpeed(200);
  leftMotor2.setSpeed(200); rightMotor2.setSpeed(200);

  moving_forward = true;
}

void brake(){
  leftMotor1.run(0x01); rightMotor1.run(0x01);
  leftMotor2.run(0x01); rightMotor2.run(0x01);
  leftMotor1.setSpeed(0); rightMotor1.setSpeed(0);
  leftMotor2.setSpeed(0); rightMotor2.setSpeed(0);    

  moving_forward = false;
}

void back(){
  leftMotor1.run(0x02); rightMotor1.run(0x02);
  leftMotor2.run(0x02); rightMotor2.run(0x02);
  leftMotor1.setSpeed(200); rightMotor1.setSpeed(200);
  leftMotor2.setSpeed(200); rightMotor2.setSpeed(200); 

  moving_forward = false;
}
