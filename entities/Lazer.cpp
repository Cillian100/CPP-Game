#import "Lazer.h"

Lazer::Lazer(int inputX, int inputY, int inputWidth, int inputHeight, int inputNumberOfSprites, int inputDirectionOfSprites, int inButtonX, int inButtonY) :
  Square(inputX, inputY, inputWidth, inputHeight)
{
  numberOfSprites=inputNumberOfSprites;
  directionOfSprites=inputDirectionOfSprites;
  buttonX=inButtonX;
  buttonY=inButtonY;
  
  if(!textureUno.loadFromFile("Graphics/lazerEnd.png")){
    printf("Couldn't load from Graphics/lazerEnd.png");
  }
  if(!textureDos.loadFromFile("Graphics/lazerLazer.png")){
    printf("Couldn't load from Graphics/lazerLazer.png");
  }
  if(!textureButtonPressed.loadFromFile("Graphics/LazerButtonPressed.png")){
    printf("Couldn't load from Graphics/LazerButtonPressed.png");
  }
  if(!textureButtonUnPressed.loadFromFile("Graphics/LazerButtonUnPressed.png")){
    printf("Couldn't load from Graphics/LazerButtonUnPressed.png");
  }
  spriteButton.setTexture(textureButtonUnPressed);
  spriteButton.setTextureRect(sf::IntRect(0,0,80,10));
  spriteButton.setColor(sf::Color(255, 255, 255, 255));
  spriteButton.setPosition(buttonX, buttonY);
  
  for(int a=0;a<2;a++){
    spriteUno[a].setTexture(textureUno);
    spriteUno[a].setTextureRect(sf::IntRect(0, 0, 20, 100));
    spriteUno[a].setColor(sf::Color(255, 255, 255, 255));
  }

  if(directionOfSprites==1){
    spriteUno[0].setPosition(inputX, inputY);
    spriteUno[1].setPosition(inputX+inputWidth, inputY+inputHeight);
    spriteUno[1].setRotation(180);
  }else{
    spriteUno[0].setPosition(inputX+inputWidth, inputY);
    spriteUno[0].setRotation(90);
    spriteUno[1].setPosition(inputX, inputY+inputHeight);
    spriteUno[1].setRotation(270);
  }

  for(int a=0;a<numberOfSprites;a++){
    spriteDos[a].setTexture(textureDos);
    spriteDos[a].setTextureRect(sf::IntRect(0, 0, 100, 20));
    spriteDos[a].setColor(sf::Color(255, 255, 255, 255));
    if(directionOfSprites==1){
      spriteDos[a].setPosition(inputX+(a*100), inputY+40);
    }else{
      spriteDos[a].setRotation(90);
      spriteDos[a].setPosition(inputX+60, inputY+(a*100));
    }
  }
}

sf::Sprite Lazer::getSpriteUno(int apple){
  return spriteUno[apple];
}

sf::Sprite Lazer::getSpriteDos(int apple){
  return spriteDos[apple];
}

sf::Sprite Lazer::getButtonSprite(){
  return spriteButton;
}

int Lazer::getNumberOfSprites(){
  return numberOfSprites;
}

int Lazer::getButtonX(){
  return buttonX;
}

int Lazer::getButtonX2(){
  return buttonX+80;
}

int Lazer::getButtonY(){
  return buttonY;
}

int Lazer::getButtonY2(){
  return buttonY+10;
}

void Lazer::lazerCollision(Robot &robot){
}

void Lazer::buttonCollision(Robot &robot){
  if(getButtonX() < robot.getX2() && getButtonX2() > robot.getX() && getButtonY() < robot.getY2() && getButtonY2() > robot.getY()){
    spriteButton.setTexture(textureButtonPressed);
    for(int a=0;a<numberOfSprites;a++){
      spriteDos[a].setColor(sf::Color(0, 0, 0, 0));

    }
    printf("collusion \n");
  }else{
    spriteButton.setTexture(textureButtonUnPressed);
    for(int a=0;a<numberOfSprites;a++){
      spriteDos[a].setColor(sf::Color(255, 255, 255, 255));      
    }
    printf("not collision \n");
  }

}
