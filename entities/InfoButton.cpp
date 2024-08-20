#include "InfoButton.h"

InfoButton::InfoButton(int inputX, int inputY, int inputWidth, int inputHeight, int inputMessageIndex)
  :Square(inputX, inputY, inputWidth, inputHeight)
{
  messageIndex=inputMessageIndex;

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
    printf("Couldn't load fonts!\n");
  }

  text.setFont(font);
  text.setCharacterSize(30);
  text.setStyle(sf::Text::Regular);
  text.setFillColor(sf::Color::White);
  text.setPosition(20, 20);
}

sf::Sprite InfoButton::getSprite(){
  return sprite;
}

sf::Text InfoButton::getText(int offset){
  text.setPosition(20+offset, 20);
  return text;
}

void InfoButton::collision(Robot &robot){
  if(getX() < robot.getX2() && getX2() > robot.getX() && (getY() < robot.getY2() && getY2() > robot.getY()) ){
    sprite.setTexture(texturePressed);
    text.setString(messages[messageIndex]);
  }else{
    sprite.setTexture(textureUnPressed);
    text.setString("");
  }
}
