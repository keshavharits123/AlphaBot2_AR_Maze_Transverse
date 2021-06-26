int Distance_test()         // Measure the distance
{
  digitalWrite(TRIG, LOW);   // set trig pin low 2μs
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);  // set trig pin 10μs , at last 10us
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);    // set trig pin low
  float Fdistance = pulseIn(ECHO, HIGH);  // Read echo pin high level time(us)
  Fdistance = Fdistance / 58;    //Y m=（X s*344）/2
  // X s=（ 2*Y m）/344 ==》X s=0.0058*Y m ==》cm = us /58
  return (int)Fdistance;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PCF8574Write(byte data)
{
  Wire.beginTransmission(Addr);
  Wire.write(data);
  Wire.endTransmission();
}

byte PCF8574Read()
{
  int data = -1;
  Wire.requestFrom(Addr, 1);
  if (Wire.available()) {
    data = Wire.read();
  }
  return data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool obstacle_detection()
{

  int Distance = Distance_test();

  PCF8574Write(0xC0 | PCF8574Read());   //set Pin High
  byte value = PCF8574Read() | 0x3F;         //read Pin
  if ((Distance < 3) || (value != 0xFF))     //Ultrasonic range ranging 2cm to 400cm

  {
    return true;
  } else
    return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Additional IR sensor shows some fluctuation when obejct detected. For solving this we are taking average to get more accurate data.
int IR_reading()
{
  float avg_IR = 0;
  float IR_value = 0;
  int final_value;
  for (int i = 0; i <= 200; i++) {
    IR_value = IR_value + digitalRead(4);

  }
  avg_IR = IR_value / 200.0;
  if (avg_IR == 0.0)
  {
    final_value = 0;
  }
  else
  {
    final_value = 1;
  }
  return (final_value);
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

float Left_Wall_test()         // Measure the distance
{
  digitalWrite(TRIG_3, LOW);   // set trig pin low 2μs
  delayMicroseconds(2);
  digitalWrite(TRIG_3, HIGH);  // set trig pin 10μs , at last 10us
  delayMicroseconds(10);
  digitalWrite(TRIG_3, LOW);    // set trig pin low
  float Fdistance = pulseIn(ECHO_3, HIGH);  // Read echo pin high level time(us)
  Fdistance = Fdistance / 58;    //Y m=（X s*344）/2
  // X s=（ 2*Y m）/344 ==》X s=0.0058*Y m ==》cm = us /58
  if(Fdistance<=2 )
  {
    Fdistance=0;
  }
  return Fdistance;
}


float Right_Wall_test()         // Measure the distance
{
  digitalWrite(TRIG_2, LOW);   // set trig pin low 2μs
  delayMicroseconds(2);
  digitalWrite(TRIG_2, HIGH);  // set trig pin 10μs , at last 10us
  delayMicroseconds(10);
  digitalWrite(TRIG_2, LOW);    // set trig pin low
  float Fdistance = pulseIn(ECHO_2, HIGH);  // Read echo pin high level time(us)
  Fdistance = Fdistance / 58;    //Y m=（X s*344）/2
  // X s=（ 2*Y m）/344 ==》X s=0.0058*Y m ==》cm = us /58
   if(Fdistance<=2 )
  {
    Fdistance=0;
  }
  return Fdistance;
}
