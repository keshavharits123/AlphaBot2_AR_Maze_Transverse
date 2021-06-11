// failed. we made this speed controller for driving robot straight.
/*void speed_controller()
{int speedL=75, speedR=75;
  //max_speed 50 for better control
  
  float Wall_distanceR= Wall_Distance_test1();
  float Wall_distanceL= Wall_Distance_test2();
  int Front_Distance = Distance_test();

float difference = Wall_distanceR-Wall_distanceL;   // If its positive decrease left speed and if negative decrease Right 
  PCF8574Write(0xC0 | PCF8574Read());   //set Pin High
  byte value = PCF8574Read() | 0x3F;         //read Pin

  if(difference!=0)
  {
      if ((Distance < 5) || (value != 0xFF))
  {
    speedL = 0;
    speedR = 0;
  
  } else {
    if(Wall_distanceL<2)
    {
      speedR=0;
      delay(100);
      setspeed( speedL, speedR);
      speedR=75;
      speedL=0;
      setspeed( speedL, speedR);
      delay(100);
      speedR=75;
      speedL=75;
      setspeed( speedL, speedR);
      
    }
    if(Wall_distanceR<2)
    {
      speedL=0;
      delay(200);
      setspeed( speedL, speedR);
      speedL=75;
      speedR=0;
      setspeed( speedL, speedR);
      delay(200);
       speedR=75;
      speedL=75;
      setspeed( speedL, speedR);
      
    }
    if(difference>0)
    {
      if(speedR>69)
      {
      speedR-=3;
      }
    }
    if(difference<0)
    {if(speedL>69)
    {
      speedL-=3;
    }
    }
  }
   
 
  }
   
setspeed( speedL, speedR);
}


void setspeed(int speedL, int speedR)
{
  analogWrite(PWMA, speedL);
  analogWrite(PWMB, speedR);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
}*/
