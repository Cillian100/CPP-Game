#pragma once

class square{
 public:
  square(int ex, int why, int len, int wid);
  int getX();
  int getY();
  void setX(int ex);
  void setY(int why);
  
  int getLength();
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
  int length;
  int width;
  float velocityX;
  float velocityY;
};
