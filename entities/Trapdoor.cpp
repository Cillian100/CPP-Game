#import "Trapdoor.h"

Trapdoor::Trapdoor(int inputX, int inputY, int inputWidth, int inputHeight, int inputButtonX, int inputButtonY) :
  Square(inputX, inputY, inputWidth, inputHeight)
{
  buttonX=inputButtonX;
  buttonY=inputButtonY;

  if(!textureTrapdoor.loadFromFile("Graphics/Trapdoor.png")){
    printf("Couldn't load from Graphics/Trapdoor.png");
  }
  if(!textureTrapdoorButtonUnPressed.loadFromFile("Graphics/TrapdoorButtonUnPressed")){
    printf("Couldn't load from Graphics/TrapdoorButtonUnPressed.png");    
  }
  if(!textureTrapdoorButtonPressed.loadFromFile("Graphics/TrapdoorButtonPressed")){
    printf("Couldn't load from Graphics/TrapdoorButtonPressed.png");    
  }
  
  spriteTrapdoorButton.setTexture(textureTrapdoorButtonUnPressed);
  spriteTrapdoorButton.setTextureRect(sf::IntRect(0,0,80,100));
  spriteTrapdoorButton.setColor(sf::Color(255, 255, 255, 255));
  spriteTrapdoorButton.setPosition(buttonX, buttonY);
  buttonPressed=false;

  spriteTrapdoorUno.setTexture(textureTrapdoor);
  spriteTrapdoorUno.setTextureRect(sf::IntRect(0,0,27,100));
  spriteTrapdoorUno.setColor(sf::Color(255, 255, 255, 255));
  spriteTrapdoorUno.setPosition(inputX, inputY);

  spriteTrapdoorDos.setTexture(textureTrapdoor);
  spriteTrapdoorDos.setTextureRect(sf::IntRect(0,0,27,100));
  spriteTrapdoorDos.setColor(sf::Color(255, 255, 255, 255));
  spriteTrapdoorDos.setPosition(inputX, inputY+100);
}

sf::Sprite Trapdoor::getSpriteTrapdoorUno(){
  return spriteTrapdoorUno;
}

sf::Sprite Trapdoor::getSpriteTrapdoorDos(){
  return spriteTrapdoorDos;
}

sf::Sprite Trapdoor::getSpriteTrapdoorButton(){
  return spriteTrapdoorButton;
}

void Trapdoor::trapdoorCollision(Robot &robot){
}

// void Trapdoor::buttonCollision(Robot &robot){
//   spriteButtton.setTexture(spriteTrapdoorButtonUnPressed);
//   buttonPressed=false;

//   if(getButtonX() < robot.getX() && getButtonX2() > robot.getX() && getButtonY() < robot.getY2() && getButtonY2() > robot.getY() ){
//     buttonPressed=true;
//     spriteTrapdoorButton.setTexture(textureTrapdoorButtonPressed);
//     printf("poop > : D");
//   }
// }
