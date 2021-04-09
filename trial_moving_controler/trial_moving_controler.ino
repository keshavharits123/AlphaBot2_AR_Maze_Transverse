// PIN configuration from official website



#define PWM_L   6           //Left Motor Speed pin (ENA)
#define LM_F   A0          //Motor-L forward (IN2).
#define LM_B   A1          //Motor-L backward (IN1)
#define PWM_R  5           //Right Motor Speed pin (ENB)
#define RM_F   A2          //Motor-R forward (IN3)
#define RM_B   A3          //Motor-R backward (IN4)


int speed=50;
void set_setup();

void turn_left(int speed);

void turn_right(int speed);

void move_forward(int speed);

void move_backward(int speed);
    
void rotate(int num_rotation, int speed);

void stop();

  
void setup() {
 
set_setup(); 
 
}

void loop() {

for(int i=0; i<=4;i++)
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
rotate(4,speed);

}

void set_setup()
{
  pinMode(PWM_L,OUTPUT);                     
  pinMode(LM_F,OUTPUT);      
  pinMode(LM_B,OUTPUT);
  pinMode(PWM_R,OUTPUT);       
  pinMode(RM_F,OUTPUT);     
  pinMode(RM_B,OUTPUT); 
}
    
void turn_left(int speed)
{
  analogWrite(PWM_L,speed);
  analogWrite(PWM_R,speed);
  digitalWrite(LM_B,HIGH);
  digitalWrite(LM_F,LOW);
  digitalWrite(RM_F,LOW); 
  digitalWrite(RM_B,HIGH);
  delay(300); //tune for 90 deg turn
        stop();
} 
    
void turn_right(int speed)
{
  analogWrite(PWM_L,speed);
  analogWrite(PWM_R,speed);
  digitalWrite(LM_B,LOW);
  digitalWrite(LM_F,HIGH);
  digitalWrite(RM_F,HIGH); 
  digitalWrite(RM_B,LOW);  
  delay(300); //tune for 90 deg turn
        stop();
} 

void move_forward(int speed)
{
  analogWrite(PWM_L,speed);
  analogWrite(PWM_R,speed);
  digitalWrite(LM_B,LOW);
  digitalWrite(LM_F,HIGH);
  digitalWrite(RM_F,LOW);  
  digitalWrite(RM_B,HIGH); 
}


void move_backward(int speed)
{
  analogWrite(PWM_L,speed);
  analogWrite(PWM_R,speed);
  digitalWrite(LM_B,HIGH);
  digitalWrite(LM_F,LOW);
  digitalWrite(RM_F,HIGH);  
  digitalWrite(RM_B,LOW); 
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
  analogWrite(PWM_L,0);
  analogWrite(PWM_R,0);
  digitalWrite(LM_B,LOW);
  digitalWrite(LM_F,LOW);
  digitalWrite(RM_B,LOW); 
  digitalWrite(RM_F,LOW);  
}
