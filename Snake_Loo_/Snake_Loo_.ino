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

void setup()
{
 MeggyJrSimpleSetup();
 x = 3;
 y = 4;
}

void loop() 
{
  snake();
  spawnApple();
  moveSnake();
  eatApple();
  DisplaySlate();
  delay(100);
  ClearSlate();
}

void snake()
{
  DrawPx(x, y, Red);
}

void moveSnake()
{
  CheckButtonsPress();
  if (Button_Left)
  {
    if (x > 0)
    {
      x--;
    }
    else
    {
      x = 7;
    }
  }
  if (Button_Right)
  {
    if (x < 7)
    {
      x++;
    }
    else
    {
      x = 0;
    }
  }
  if (Button_Up)
  {
    if (y < 7)
    {
      y++;
    }
    else
    {
      y = 0;
    }
  }
  if (Button_Down)
  {
    if (y > 0)
    {
      y--;
    }
    else
    {
      y = 7;
    }
  }
}

void spawnApple()
{
  DrawPx(xapple, yapple, Green);
}

void eatApple()
{
  if (xapple == x)
  {
    if (yapple == y)
    {
      gotApple = true;
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
