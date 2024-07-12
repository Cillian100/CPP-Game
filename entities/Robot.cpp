#include "Robot.h";

Robot::Robot(int inputX, int inputY, int inputWidth, int inputHeight){
  x=inputX;
  y=inputY;
  width=inputWidth;
  height=inputHeight;

  if(!texture.loadFromFile("Graphics/robot.png")){
    printf("couldn't load robot \n");
  }

  sprite.setTexture(texture);
  sprite.setTextureRect(sf::IntRect(0,0,70,100));
  sprite.setColor(sf::Color(255, 255, 255, 255));
  sprite.setPosition(0,0);
}

int Robot::getX(){
  return x;
}

int Robot::getY(){
  return y;
}

int Robot::getWidth(){
  return width;
}

int Robot::getHeight(){
  return height;
}

sf::Sprite Robot::getSprite(){
  return sprite;
}
