void speed_controller(int &speedL, int &speedR)
{ 
  
  int Distance =Distance_test();
  PCF8574Write(0xC0 | PCF8574Read());   //set Pin High
    byte value = PCF8574Read() | 0x3F;         //read Pin
    if((Distance < 5) || (value != 0xFF))
  {
    speedL=0;
    speedR=0;
  } else if(Distance<=20)
  {speedR=40;
   speedL=40;
    } else {
      speedR=80;
      speedL=80;
      
    }
 }

