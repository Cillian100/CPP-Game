#include <SFML/Graphics.hpp>
#pragma once

class Square{
 public:
  int getHeight();
  int getWidth();
  int getX();  
  int getX2();
  int getY();  
  int getY2();

  void setHeight(int input);
  void setWidth(int input);
  void setX2(int input);
  void setX(int input);
  void setY(int input);  
  void setY2(int input);
  void setStuff(int inputX, int inputY, int inputWidth, int inputHeight);

  Square(int inputX, int inputY, int inputWidth, int inputHeight);
  
 private:
  int x;
  int y;
  int height;
  int width;
};
