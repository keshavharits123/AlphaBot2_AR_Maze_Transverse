////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void turn_left(int speed)
{
  analogWrite(PWMA, speed);
  analogWrite(PWMB, speed);
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  delay(350); //tune for 90 deg turn
  stop();
}




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void turn_right(int speed)
{
  analogWrite(PWMA, speed);
  analogWrite(PWMB, speed);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  delay(350); //tune for 90 deg turn
  stop();
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void move_forward(int speedL, int speedR)
{
  analogWrite(PWMA, speedL);
  analogWrite(PWMB, speedR);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void move_backward(int speedL, int speedR)
{
  analogWrite(PWMA, speedL);
  analogWrite(PWMB, speedR);
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void rotate(int num_rotation, int speed)
{
  for (int i = 0; i <= num_rotation; i++)
  {
    for (int j = 0; j <= 2; j++)
    {
      turn_right(speed);

    }

  }
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void stop()
{
  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN2, LOW);
  digitalWrite(BIN1, LOW);

}
