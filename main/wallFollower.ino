void wallFollower(int speed)
{
  int IR_value=IR_reading();
   // Serial.print ("Sensor: ");
  //Serial.println (IR_value); //print the sensor output
  bool obstacle = obstacle_detection();
  if(obstacle || IR_value ==1)
  {
    
  if(obstacle && IR_value ==0)
  { 
    turn_left(speed);
    stop(); 
  }
  if(IR_value == 1)
  {
    turn_right(speed);
    
    obstacle = obstacle_detection();
    while(IR_value ==1 && !obstacle) {
       
    IR_value=IR_reading();
    obstacle = obstacle_detection();
      move_forward(speedL,speedR); 
     
    }
     
  }
  else {
    move_forward(speedL,speedR);
  }
  }
  else{
    move_forward(speedL,speedR);
  }
}
