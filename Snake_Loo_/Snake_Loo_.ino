/*
  Snake[Loo].ino
  Marisa Loo
 
 Example file using the The Meggy Jr Simplified Library (MJSL)
  from the Meggy Jr RGB library for Arduino
   
 Blink a damned LED.
   
   
 
 Version 1.25 - 12/2/2008
 Copyright (c) 2008 Windell H. Oskay.  All right reserved.
 http://www.evilmadscientist.com/
 
 This library is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this library.  If not, see <http://www.gnu.org/licenses/>.
     
 */

 
 
 
 

/*
 * Adapted from "Blink,"  The basic Arduino example.  
 * http://www.arduino.cc/en/Tutorial/Blink
 */

#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

int x;
int y;
int xapple = random(8);
int yapple = random(8);
boolean gotApple = false; 
int direction = 0;
int applesEaten = 0;
int marker = 2;

struct Point
{
  int x;
  int y;
};

Point s1 = {3, 4};
Point s2 = {2, 4};

Point snakeArray[64] = {s1, s2};

void setup()
{
 MeggyJrSimpleSetup();
 x = 3;
 y = 4; 
}

void loop() 
{
  drawHead();
  spawnApple();
  drawBody();
  die();
  eatApple();
  DisplaySlate();
  delay(150);
  ClearSlate();
  updateSnake();
  moveSnake();
}

void drawBody()
{
  for (int i = 1; i < marker; i++)
  {
    DrawPx(snakeArray[i].x, snakeArray[i].y, Red);
  }
}

void drawHead()
{
  DrawPx(snakeArray[0].x, snakeArray[0].y, Blue);
}

void updateSnake()
{
  for (int i = marker - 1; i > 0; i--)
  {
    snakeArray[i] = snakeArray[i - 1];
  }
  
  if (direction == 180)
  {
    if (snakeArray[0].x > 0)
    {
      snakeArray[0].x--;
    }
    else
    {
      snakeArray[0].x = 7;
    }
  }
  if (direction == 0)
  {
    if (snakeArray[0].x < 7)
    {
      snakeArray[0].x++;
    }
    else
    {
      snakeArray[0].x = 0;
    }
  }
  if (direction == 90)
  {
    if (snakeArray[0].y < 7)
    {
      snakeArray[0].y++;
    }
    else
    {
      snakeArray[0].y = 0;
    }
  }
  if (direction == 270)
  {
    if (snakeArray[0].y > 0)
    {
      snakeArray[0].y--;
    }
    else
    {
       snakeArray[0].y = 7;
    }
  } 
}

void moveSnake()
{
  CheckButtonsPress();
  if (Button_Left)
  {
    direction = 180;
  }
  
  if (Button_Right)
  {
    direction = 0;
  }
  
  if (Button_Up)
  {
    direction = 90;
  }
  
  if (Button_Down)
  {
    direction = 270;
  }
  
}

void spawnApple()
{
  DrawPx(xapple, yapple, Green);
}

void eatApple()
{
  if (xapple == snakeArray[0].x)
  {
    if (yapple == snakeArray[0].y)
    {
      gotApple = true;
      Tone_Start(ToneA3, 50);
      applesEaten++;
      marker++;
    }
  }
  else
  {
    gotApple = false;
  }
  if (gotApple == true)
  {
   xapple = random(8);
   yapple = random(8); 
  }
}

void die()
{
  if (ReadPx(snakeArray[0].x, snakeArray[0].y) == Red)
  {
    ClearSlate();
    marker = 2;
    snakeArray[0].x = 3;
    snakeArray[0].y = 4;
    snakeArray[1].x = 2;
    snakeArray[1].y = 4;
    DisplaySlate();
    Tone_Start(ToneG4, 800);
    delay(1000);
  }
}
