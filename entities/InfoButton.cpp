#include "InfoButton.h"

InfoButton::InfoButton(int inputX, int inputY, int inputWidth, int inputHeight){
  setX(inputX);
  setY(inputY);
  setHeight(inputHeight);
  setWidth(inputWidth);

  if(!textureUnPressed.loadFromFile("Graphics/InfoButtonUnPressed.png")){
    printf("Couldn't load file InfoButtonUnPressed.png \n");
  }

  if(!texturePressed.loadFromFile("Graphics/InfoButtonPressed.png")){
    printf("Couldn't load file InfoButtonPressed.png");
  }

  sprite.setTexture(textureUnPressed);
  sprite.setTextureRect(sf::IntRect(0, 0, inputWidth, inputHeight));
  sprite.setColor(sf::Color(255, 255, 255, 255));
  sprite.setPosition(inputX, inputY);

  if(!font.loadFromFile("Graphics/font.ttf")){
  }

  text.setFont(font);
  text.setCharacterSize(20);
  text.setStyle(sf::Text::Regular);
  text.setFillColor(sf::Color::White);
  text.setPosition(20, 20);
}

sf::Sprite InfoButton::getSprite(){
  return sprite;
}

string InfoButton::collision(Robot &robot){
  if(getX() < robot.getX2() && getX2() > robot.getX() && (getY() < robot.getY2() && getY2() > robot.getY()) ){
    sprite.setTexture(texturePressed);
    return messages[0];
  }else{
    sprite.setTexture(textureUnPressed);
  }

  return "";
}
