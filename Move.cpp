#include "square.h"
#include "Move.h"

void Move::platformUpAndDown(square &platform, int top, int bottom, bool speed){
  platform.setY(platform.getY() - 0.2);
  
}
