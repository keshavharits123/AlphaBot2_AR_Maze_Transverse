// PIN configuration from official website

#include <Wire.h>

#define PWMA   6           //Left Motor Speed pin (ENA)
#define AIN2   A0          //Motor-L forward (IN2).
#define AIN1   A1          //Motor-L backward (IN1)
#define PWMB   5           //Right Motor Speed pin (ENB)
#define BIN1   A2          //Motor-R forward (IN3)
#define BIN2   A3          //Motor-R backward (IN4)
#define ECHO   2
#define TRIG   3
#define Addr  0x20


int Distance = 0;
int counter ;

int speed=50;
int speedL=50;
int speedR=50;


void PCF8574Write(byte data);
byte PCF8574Read();
void set_setup();

void turn_left(int speed);

void turn_right(int speed);

void move_forward(int speedL, int speedR);

void move_backward(int speedL, int speedR);
    
void rotate(int num_rotation, int speed);

void stop();
 
int Distance_test();

void obstacle_detection(int &counter  );

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
 
set_setup(); 
 
}

void loop() {

/*for(int i=0; i<=4;i++)
{
move_forward(speed);
delay(2000);
turn_right(speed);


}
for(int i=0; i<=4;i++)
{
move_backward(speed);
delay(2000);
turn_left(speed);



}
rotate(4,speed);*/
Distance= Distance_test();
  
obstacle_detection( counter);
Serial.print(counter);

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void set_setup()
{
  Serial.begin(115200); 
  Wire.begin();
  pinMode(PWMA,OUTPUT);                     
  pinMode(AIN2,OUTPUT);      
  pinMode(AIN1,OUTPUT);
  pinMode(PWMB,OUTPUT);       
  pinMode(BIN1,OUTPUT);     
  pinMode(BIN2,OUTPUT); 
  pinMode(ECHO, INPUT);    // Define the ultrasonic echo input pin
  pinMode(TRIG, OUTPUT);   // Define the ultrasonic trigger input pin 
}
    
void turn_left(int speed)
{
  analogWrite(PWMA,speed);
  analogWrite(PWMB,speed);
  digitalWrite(AIN1,HIGH);
  digitalWrite(AIN2,LOW);
  digitalWrite(BIN1,LOW); 
  digitalWrite(BIN2,HIGH);
  delay(350); //tune for 90 deg turn
        stop();
} 
    
void turn_right(int speed)
{
  analogWrite(PWMA,speed);
  analogWrite(PWMB,speed);
  digitalWrite(AIN1,LOW);
  digitalWrite(AIN2,HIGH);
  digitalWrite(BIN1,HIGH); 
  digitalWrite(BIN2,LOW);  
  delay(350); //tune for 90 deg turn
        stop();
} 

void move_forward(int speedL, int speedR)
{
  analogWrite(PWMA,speedL);
  analogWrite(PWMB,speedR);
  digitalWrite(AIN1,LOW);
  digitalWrite(AIN2,HIGH);
  digitalWrite(BIN1,LOW);  
  digitalWrite(BIN2,HIGH); 
}


void move_backward(int speedL, int speedR)
{
  analogWrite(PWMA,speedL);
  analogWrite(PWMB,speedR);
  digitalWrite(AIN1,HIGH);
  digitalWrite(AIN2,LOW);
  digitalWrite(BIN1,HIGH);  
  digitalWrite(BIN2,LOW); 
}



void rotate(int num_rotation, int speed)
{
    for(int i =0; i<=num_rotation;i++)
    {
       for(int j =0; j<=2;j++)
       {
        turn_right(speed);
      
       }
        
    } 
    
}


void stop()
{
  analogWrite(PWMA,0);
  analogWrite(PWMB,0);
  digitalWrite(AIN1,LOW);
  digitalWrite(AIN2,LOW);
  digitalWrite(BIN2,LOW); 
  digitalWrite(BIN1,LOW);  
}

int Distance_test()         // Measure the distance 
{
  digitalWrite(TRIG, LOW);   // set trig pin low 2μs
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);  // set trig pin 10μs , at last 10us 
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);    // set trig pin low
  float Fdistance = pulseIn(ECHO, HIGH);  // Read echo pin high level time(us)
  Fdistance= Fdistance/58;       //Y m=（X s*344）/2
  // X s=（ 2*Y m）/344 ==》X s=0.0058*Y m ==》cm = us /58       
  return (int)Fdistance;
}  


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
  if(Wire.available()) {
    data = Wire.read();
  }
  return data;
}
void obstacle_detection(int &counter )
{

int Distance= Distance_test();
  
  PCF8574Write(0xC0 | PCF8574Read());   //set Pin High
  byte value = PCF8574Read() | 0x3F;         //read Pin
  if((Distance < 5) || (value != 0xFF))      //Ultrasonic range ranging 2cm to 400cm
  {
    counter++; 
    
     if(counter<2){
    turn_left(speed);
    //left();
    
    stop(); 
    }
    
    if(counter==2)
      { stop();
        delay(1000);
        
    turn_left(speed);
    turn_left(speed);
    stop();
   
    Distance= Distance_test();
    PCF8574Write(0xC0 | PCF8574Read());   //set Pin High
    byte value = PCF8574Read() | 0x3F;         //read Pin
    if((Distance < 5) || (value != 0xFF))
    {
      turn_right(speed);
     stop();
     delay(1000);
      counter=0;  
    }
    else{
    move_forward(speedL,speedR);
    counter=0;
    
   
    
    }
    
    }
   
   
  
  }
  else
  {
     move_forward(speedL,speedR); 
     counter=0;
  }
  
}
    
    
    
    
    
