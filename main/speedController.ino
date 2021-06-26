//This is working but we were unable to combine this with our wall follower algorithm.

void speed_controller()
{float LeftWall= Left_Wall_test();
  float RightWall= Right_Wall_test();
    int differenceR;
   int differenceL;
 move_forward(speedL, speedR);
  if(RightWall<10|| LeftWall<10)
{
  if (differenceR > -5 && (differenceR > 0 || differenceR < 0))
    {

      speedL = speedR + (differenceR);;
      speedL = speedL - (differenceR);

    }
    if (differenceL > -5 && (differenceL > 0 || differenceL < 0))
    {

      speedL = speedL + (differenceL);
      speedR = speedR - (differenceL);

    }

}
 move_forward( speedL, speedR);
}
