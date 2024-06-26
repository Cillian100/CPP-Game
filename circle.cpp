#include "circle.h"

circle::circle(int ex, int why, int rad){
  x=ex;
  y=why;
  radius=rad;
}

int circle::getCentreX(){
  return (x + (radius));
}

int circle::getCentreY(){
  return (y + (radius));
}

int circle::getX(){
  return x;
}

int circle::getY(){
  return y;
}



int circle::getRadius(){
  return radius;
}

void circle::setX(int ex){
  x=ex;
}

void circle::setY(int why){
  y=why;
}
