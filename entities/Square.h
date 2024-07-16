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

  void setHeight();
  void setWidth();
  void setX2();
  void setX();
  void setY();  
  void setY2();
  
 private:
  int x;
  int y;
  int height;
  int width;
};
