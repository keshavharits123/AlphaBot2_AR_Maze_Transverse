// Our main alogrithm to transverse the maze
void wallFollower(int speedL, int speedR, int speed)
{ LeftWall = Left_Wall_test();
  RightWall = Right_Wall_test();
  int IR_value = IR_reading();
  bool obstacle = obstacle_detection();
  if (obstacle || IR_value == 1)
  {
    if (obstacle && IR_value == 0 && RightWall < 10 && LeftWall > 10)
    {
      turn_left(speed);
    }
    if (obstacle && IR_value == 0 && RightWall < 10 && LeftWall < 10)
    {
      while (RightWall < 10 && LeftWall < 10)
      {
        LeftWall = Left_Wall_test();
        RightWall = Right_Wall_test();
        move_backward(speedL,  speedR);
      }
      if (LeftWall > 10)
      { delay(150);
        turn_left(speed);
        delay(150);
        move_forward( speedL,  speedR);
        delay(1000);

        while (IR_value == 1 && !obstacle)
        {
          IR_value = IR_reading();
          obstacle = obstacle_detection();
          move_forward(speedL, speedR);
        }
      }
    }
    if (IR_value == 1 )
    {
      turn_right(speed);

      obstacle = obstacle_detection();

      while ((IR_value == 1 ) && !obstacle)
      {
        IR_value = IR_reading();
        obstacle = obstacle_detection();
        move_forward(speedL, speedR);
      }
    }
    else {
      move_forward(speedL, speedR);
    }
  }
  else {
    move_forward(speedL, speedR);
  }
}
