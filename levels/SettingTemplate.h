#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "../enums/GameLevel.h"
using namespace std;
#pragma once

class SettingTemplate{
 public:
  sf::RenderWindow& window;
  
  SettingTemplate(sf::RenderWindow& win);
  void templateRender();
  void templateUserInput();

  sf::Sprite backgroundSprite;
  sf::Texture backgroundTexture;
  
  sf::View view;
  sf::Text text[10];
  sf::Font font;
  sf::Event event;
		       
  int currentMenuItem;
  int numberOfMenuItems;
  bool enterBool;
  bool keyPress;
  bool waitASec=true;
  bool exitBool=false;
  bool enterKeyBoolean=false;

 private:
};

