#include "Square.h"

Square::Square(int inputX, int inputY, int inputWidth, int inputHeight){
  setX(inputX);
  setY(inputY);
  setWidth(inputWidth);
  setHeight(inputHeight);
}

int Square::getHeight(){
  return height;
}

int Square::getWidth(){
  return width;
}

int Square::getX(){
  return x;
}

int Square::getX2(){
  return x+width;
}

int Square::getY(){
  return y;
}

int Square::getY2(){
  return y+height;
}

void Square::setHeight(int input){
  height=input;
}

void Square::setWidth(int input){
  width=input;
}

void Square::setX(int input){
  x=input;
}

void Square::setX2(int input){
  x=input-width;
}

void Square::setY(int input){
  y=input;
}

void Square::setY2(int input){
  y=input-height;
}
