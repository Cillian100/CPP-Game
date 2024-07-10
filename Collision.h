#include "circle.h"
#include "square.h"
#include "line.h"

#pragma once

class Collision{
 public:
  bool squarePlatform(square &player, square platform);

  bool oneWayPlatform(square &player, square platform);
  
  bool circleInsideSquare(circle c, square s);

  bool squareInsideSquare(square &player, square object);

  bool squareOutsideSquare(square &player, square object);

  bool squareAcrossLine(square &player, int point, int point2);
};
