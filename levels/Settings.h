#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "SettingTemplate.h"
using namespace std;
#pragma once

class Settings : public SettingTemplate{
  sf::RenderWindow& window;

 public:
  int gameLoop();
  int render();
  Settings(sf::RenderWindow& win);
 private:
  bool fullScreenBool=false;
};
