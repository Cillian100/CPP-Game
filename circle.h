#pragma once

class circle{
 public:
  circle(int ex, int why, int rad);
  int getX();
  int getY();
  int getRadius();
  void setX(int ex);
  void setY(int why);

 private:
  int x;
  int y;
  int radius;
};
