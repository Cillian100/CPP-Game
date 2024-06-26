#include "circle.h"
#include "square.h"

#pragma once

class Collision{
 public:
  bool circleInsideSquare(circle c, square s);

  bool squareInsideSquare(square player, square object);
};
