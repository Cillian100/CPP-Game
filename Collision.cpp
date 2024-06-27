#include <cstdio>
#include "Collision.h"
// #include "square.h"
// #include "circle.h"

bool Collision::circleInsideSquare(circle c, square s){
  int squareX1=s.getX();
  int squareY1=s.getY();
  int squareX2=s.getX()+s.getWidth();
  int squareY2=s.getY()+s.getHeight();
    
  int circleX=c.getCentreX();
  int circleY=c.getCentreY();
  int circleRadius=c.getRadius();

  if(squareX1<circleX-circleRadius
     && squareX2>(circleX+circleRadius)
     && squareY1<(circleY-circleRadius)
     && squareY2>(circleY+circleRadius)
     ){
    return true;
  }else{
    return false;
  }
}

bool Collision::squareInsideSquare(square player, square object){
  int playerX1=player.getX();
  int playerX2=player.getX2();
  int playerY1=player.getY();
  int playerY2=player.getY2();

  int objectX1=object.getX();
  int objectX2=object.getX2();
  int objectY1=object.getY();
  int objectY2=object.getY2();

  printf("hello %d %d \n", playerY2, objectY2);

  if(playerY2 > objectY2){
    return true;
  }else{
    return false;
  }
}
