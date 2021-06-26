#include <Wire.h>

#define PWMA   6                    //Left Motor Speed pin (ENA)
#define AIN2   A0                   //Motor-L forward (IN2).
#define AIN1   A1                   //Motor-L backward (IN1)
#define PWMB   5                    //Right Motor Speed pin (ENB)
#define BIN1   A2                   //Motor-R forward (IN3)
#define BIN2   A3                   //Motor-R backward (IN4)
#define ECHO   2
#define TRIG   3
#define Addr  0x20
#define ECHO_2  8
#define TRIG_2  9
#define ECHO_3  10
#define TRIG_3  11



float LeftWall;
float RightWall;
int Distance = 0;
int counter ;
int speed = 50;
int speedL = 43;
int speedR = 46;

//////////////////////////////////////////////////
void PCF8574Write(byte data);

byte PCF8574Read();

void set_setup();

void turn_left(int speed);

void turn_right(int speed );

void move_forward(int speedL, int speedR);

void stop();

int Distance_test();

bool obstacle_detection();

void speed_controller();

void wallFollower(int speedL, int speedR, int speed);

int IR_reading();

float Right_Wall_test();

float Left_Wall_test();


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




void setup() {

}

void loop() {

  wallFollower( speedL, speedR,  speed);

 

}
