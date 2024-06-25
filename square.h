#pragma once

class square{
 public:
  square(int ex, int why, int len, int wid);
  int getX();
  int getY();
  int getLength();
  int getWidth();
  
 private:
  int x;
  int y;
  int length;
  int width;
};
