

Poznań University of Technology

Faculty of Control, Robotics

and Electrical Engineering

Term Design

Maze Transverse Robot

Project Report

Keshav Sharma, 142862

Jakub Szukała, 135906

Zishi Liu, 135019

Instructor:

Jan Wietrzykowski, MSc

Jan.Wietrzykowski@put.poznan.pl

18-06-2021





Maze Transverse Robot

Poznań University of Technology, ,

2/[7](#br7)

Contents

[1](#br3)[ ](#br3)[Introduction](#br3)[ ](#br3). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

[2](#br3)[ ](#br3)[Speciﬁcation](#br3)[ ](#br3). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

[3](#br4)[ ](#br4)[Schematic](#br4)[ ](#br4)[for](#br4)[ ](#br4)[Additional](#br4)[ ](#br4)[Sensors](#br4)[ ](#br4). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

3

3

4

[4](#br4)[ ](#br4)[Implementation](#br4)[ ](#br4). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

[4.1](#br4)[ ](#br4)[Hardware](#br4)[ ](#br4). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

[4.2](#br5)[ ](#br5)[Algorithm](#br5)[ ](#br5). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

4

4

5

[5](#br7)[ ](#br7)[Results](#br7)[ ](#br7). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

[6](#br7)[ ](#br7)[Conclusion](#br7)[ ](#br7). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

[7](#br7)[ ](#br7)[Summary](#br7)[ ](#br7). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

7

7

7





Maze Transverse Robot

Poznań University of Technology, ,

3/[7](#br7)

Introduction

The aim of this porject is to build a robot that will transverse a maze as fast as possible using the

AlphaBot-2ar platform.

Fig. 1. AlphaBot-2ar

Project Outline:



Platform: [AlphaBot-2ar(Fig.](#br3)[1](#br3))

Controller: Arduino-uno.

Things to remember:

– We have to do this project without using ﬂoor line follower.

– After ﬁnishing our robot, we need to test it on two diﬀerent types of maze.

Maze:Required two mazes one is simple and one is complex. Each maze with 18[cm]×18[cm]

bloc[ks(Fig.](#br3)[2](#br3)).

Fig. 2. Given designs for Mazes

Specification

In term of hardware speciﬁcations we are using on board motors of Alphabot to drive and front IR and

Ultra sound sensors for detecting obstacles in the front of the bot. Other on board sensors are useless for

us because they specially designed for following line on the ﬂoor and we do not need that functionality.

We added total three additional sensors on our bot. In terms of software, as we have Arduino uno in

our bot, so we are using Arduino Ide to program our bot. For our testing purposes we made a simple

maze and one complex maze for testing from cardboard.





Maze Transverse Robot

Poznań University of Technology, ,

4/[7](#br7)

Schematic for Additional Sensors

In the Fig.[3](#br4), we have our schematic for additional sensors. We are using two SR04 ultrasound sensors

and one ST1081 IR distance sensor.

Fig. 3. Schematic for additional sensors

We are using pin 4 to catch output from our IR sensor, pin 8,9 for echo and trig of ﬁrst ultrasound sensor

and pin 10,11 for echo and trig of second ultrasound sensor respectively. All the additional sensors are

connected with 5V power supply from Arduino board.

Implementation

4.1 Hardware

Alphabot-2ar is desigend for transverse the maze by following the black line on the ﬂoor, but our project

is to build a robot that will traverse a maze as fast as possible without using black line on the ﬂoor and

for make this happen, we had to add some additionally sensors. We added two ultrasound sensors for

taking distance from side walls(Left and Right wall) and one IR distance sensor for following right side

wall.





Maze Transverse Robot

Poznań University of Technology, ,

5/[7](#br7)

Fig. 4. AlphaBot with Additional IR Sensor Attached(Mid phase)

As we can see in the ﬁg.[4](#br5), we attached IR distance sensor at the right side ending of the bot. It gives

information about the right side wall, it follows the right side wall all the time and whenever there is

no wall it informs the bot.

Fig. 5. AlphaBot with Additional Ultra Sound and IR Sensors Attached(Final phase)

We attached these two ultra sound sensors(ﬁg.[5](#br5)) for giving us information about the side walls, Left

and Right walls. Their primary function is to help the bot in driving straight but we are also using

these sensors in our maze transverse algorithm.

4.2 Algorithm

We had to write an algorithm that will control the robot to solve a maze. For this we are using a wall

following algorithm but with some changes to make it more reliable and more eﬃcient. Basically we are

using a hybrid wall following algorithm, which is combined with left turn algorithm.

Below, there is code for our algorithm.

Listing 1. code for our algorithm(wallFollower,ino)

\01. // Our main alogrithm to transverse the maze

\02. void wallFollower(int speedL , int speedR , int speed)

\03. { LeftWall = Left\_Wall\_test ();





Maze Transverse Robot

Poznań University of Technology, ,

6/[7](#br7)

\04.

\05.

\06.

\07.

\08.

\09.

\10.

\11.

\12.

\13.

\14.

\15.

\16.

\17.

\18.

\19.

\20.

\21.

\22.

\23.

\24.

\25.

\26.

\27.

\28.

\29.

\30.

\31.

\32.

\33.

\34.

\35.

\36.

\37.

\38.

\39.

\40.

\41.

\42.

\43.

\44.

\45.

\46.

\47.

\48.

\49.

\50.

\51.

\52.

\53.

\54.

\55.

\56.

RightWall = Right\_Wall\_test ();

int IR\_value = IR\_reading ();

bool obstacle = obstacle\_detection ();

if (obstacle || IR\_value == 1)

{

if (obstacle && IR\_value == 0 && RightWall < 10 && LeftWall > 10)

{

turn\_left(speed);

}

if (obstacle && IR\_value == 0 && RightWall < 10 && LeftWall < 10)

{

while (RightWall < 10 && LeftWall < 10)

{

LeftWall = Left\_Wall\_test ();

RightWall = Right\_Wall\_test ();

move\_backward(speedL , speedR);

}

if (LeftWall > 10)

{ delay (150);

turn\_left(speed);

delay (150);

move\_forward( speedL , speedR);

delay (1000);

while (IR\_value == 1 && !obstacle)

{

IR\_value = IR\_reading ();

obstacle = obstacle\_detection ();

move\_forward(speedL , speedR);

}

}

}

if (IR\_value == 1 )

{

turn\_right(speed);

obstacle = obstacle\_detection ();

while (( IR\_value == 1 ) && !obstacle)

{

IR\_value = IR\_reading ();

obstacle = obstacle\_detection ();

move\_forward(speedL , speedR);

}

}

else {

move\_forward(speedL , speedR);

}

}

else {

move\_forward(speedL , speedR);

}

}

Other ﬁles such as movement controller.ino, speedController.ino, main.ino etc, can be found [github](https://github.com/keshavharits123/AlphaBot2_AR_Maze_Transverse.git)

Our bot ﬁrst start driving in straight line while following right wall using additional IR sensor,and

looking for the side walls and obstacles in the front. If our bot detect some obstacle in the front or our

IR sensor did not ﬁnd any wall on the right, it will trigger the ﬁrst "if statement" and then check for

the following conditions:-





Maze Transverse Robot

Poznań University of Technology, ,

7/[7](#br7)


First Condition:

If there is an obstacle in front of the robot and there is no right wall it will turn left.

Second Condition:

If there are walls on the both side and an obstacle in the front it will drive backward and follow

the left wall until there is no wall on the left, after detecting left wall, it will take a left turn and

for sometime it will move forward until there is no obstacles in the front.

Third Condition:

While driving straight if there is no obstacle in the front and no wall on the right side, bot will

take a right turn and move forward until there is no obstacles in the front.

Results

When we tested our bot on the simple maze, it transverse the maze successfully but when we tested in

the complex maze, it transverse the half of the maze but unable to dodge the side walls. We had to

help the bot by hand to reach the end of the complex maze.

Test Results are available on our wiki page.

Conclusion

Our robot did not able to transverse complex maze perfectly but if we gave some help such as little

push, it can transverse the maze and reach to the end. If our bot drive in straight line it can transverse

the maze on its own.

Summary

This project helps us to develop many new skills like team work, coping with diﬀerent kind of problems

and also it taught us a lesson that working on a real life project are way more diﬀerent than simulated

one. There are so many factors that we need to take care while working on a real life project rather

than a simulated one. In simulated one we can easily achieve our goal but in real life, it is lot harder

than looks.

