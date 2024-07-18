#include <SFML/Graphics.hpp>
#include "Square.h"
#include "Robot.h"
#include <string>
using namespace std;
#pragma once

class InfoButton : public Square{
 public:
  sf::Sprite getSprite();
  sf::Text getText();
  void setSprite();
  void collision(Robot &robot);
  InfoButton(int inputX, int inputY, int inputWidth, int inputHeight, int inputMessageIndex);
 private:
  sf::Font font;
  sf::Text text;
  sf::Texture textureUnPressed;
  sf::Texture texturePressed;
  sf::Sprite sprite;

  int messageIndex;

  string messages[2]={
    "Use the A and D keys to move Left and Right",
    "Use W to Jump, try to not fall onto the spikes!"
  };
};
