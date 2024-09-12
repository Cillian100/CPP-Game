#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "SettingTemplate.h"
using namespace std;
#pragma once

class ViewLevels : public SettingTemplate{
  sf::RenderWindow& window;

 public:
  int gameLoop();
  int render();
  ViewLevels(sf::RenderWindow& win);
 private:
  sf::Sprite levelIconSprite[10];
  sf::Texture levelIconTexture[10];

};
