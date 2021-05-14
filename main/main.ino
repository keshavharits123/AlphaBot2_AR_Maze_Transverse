
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
#define MAX_RANG      (520)//the max measurement vaule of the module is 520cm(a little bit longer than  effective max range)
#define ADC_SOLUTION      (1023.0)//ADC accuracy of Arduino UNO is 10bit

#define beep_on  PCF8574Write(0xDF & PCF8574Read())
#define beep_off PCF8574Write(0x20 | PCF8574Read())


int Distance = 0;
int counter ;
float wallDistance;

int speed=50;
int speedL=60;
int speedR=60;


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

bool obstacle_detection();

void speed_controller(int &speedL, int &speedR);

float wallDistanceTest();

void wallFollower(bool obstacle,int speed);
int IR_reading();

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
//speed_controller(speedL,speedR);
  

wallFollower(speed);

wallDistance =wallDistanceTest();
Serial.print(wallDistance,0);
 Serial.println("cm");
//after finishing
/*beep_on;
rotate(10,speed);
beep_off;
delay(1000);*/

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    
    
   
   
  

//////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

      
 
    
    
    
