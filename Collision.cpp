#include <cstdio>
#include "Collision.h"

bool Collision::squarePlatform(square &player, square object){
  //  printf("jef %d %d\n", player.getX(), object.getX2());
  if( player.getX()<object.getX2() && player.getX2()>object.getX() && player.getVelocityY()>0  ){
    if(player.getY2() > object.getY()  ){
      player.setVelocityY(1);
      player.setY(object.getY()-player.getHeight());
      return true;
    }else if(player.getY2() + player.getVelocityY() > object.getY()){
      player.setVelocityY(object.getY() - player.getY2() + 1);
    }
  }
  return false;
}

bool Collision::oneWayPlatform(square &player, square object){

  if( player.getY2() < (object.getY()+13) ){
    if( player.getX() < object.getX2() && player.getX2() > object.getX() && player.getY()<object.getY2() && player.getY2()>object.getY() ){
      if(player.getVelocityY() > 0){
	player.setVelocityY(1);
	player.setY(object.getY()-player.getHeight());
	player.setJump(true);	
	return true;
      }
    }
  }
  
  player.setJump(false);
  return false;
}

bool Collision::squareOutsideSquare(square &player, square object){
  if(player.getX() < object.getX2() && player.getY2() > object.getY()){
    //    player.setX(object.getX2());
    //    printf("Collision \n");
  }else{
    //    printf("not \n");
  }
}

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

bool Collision::squareAcrossLine(square &player, int point, int point2){
  return false;
}

bool Collision::squareInsideSquare(square &player, square object){
  int playerX1=player.getX();
  int playerX2=player.getX2();
  int playerY1=player.getY();
  int playerY2=player.getY2();

  int objectX1=object.getX();
  int objectX2=object.getX2();
  int objectY1=object.getY();
  int objectY2=object.getY2();

  //  printf("hello %d %d %f \n", playerY2, objectY2, player.getVelocityY());

  if(playerY2 > objectY2){
    return true;
  }else{
    return false;
  }
}
