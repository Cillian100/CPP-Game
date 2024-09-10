#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
using namespace std;
#pragma once

class ViewLevels{
  sf::RenderWindow& window;

 public:
  int gameLoop();
  void userInput();
  int render();
  ViewLevels(sf::RenderWindow& win);
 private:
  sf::Event event;
  sf::Font font;
  sf::Sprite backgroundSprite;
  sf::Texture backgroundTexture;
  sf::Sprite levelIconSprite[10];
  sf::Texture levelIconTexture[10];
  sf::Text text[10];

  int currentMenuItem;
  int numberOfMenuItems=2;
  bool enterBool;
  bool keyPress;
  bool waitASec=true;
};
