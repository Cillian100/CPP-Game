#pragma once

class square{
 public:
  square(int ex, int why, int wid, int hei);
  int getX();
  int getY();
  void setX(int ex);
  void setY(int why);
  
  int getHeight();
  int getWidth();
  
  int getX2();
  int getY2();
  
  float getVelocityX();
  float getVelocityY();
  void setVelocityX(float velocity);
  void setVelocityY(float velocity);
  
 private:
  int x;
  int y;
  int height;
  int width;
  float velocityX;
  float velocityY;
};
