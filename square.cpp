#include "square.h"

square::square(int ex, int why, int len, int wid){
  x=ex;
  y=why;
  length=len;
  width=wid;
}

int square::getX(){
  return x;
}

int square::getY(){
  return y;
}

int square::getLength(){
  return length;
}

int square::getWidth(){
  return width;
}
