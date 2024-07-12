#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
using namespace std;
#pragma once

class StartingScreen{
  sf::RenderWindow& window;
  
 public:
  int gameLoop();
  void userInput();
  int render();
  StartingScreen(sf::RenderWindow& win);
 private:
  sf::Event event;
  sf::Font font;
  sf::Sprite backgroundSprite;  
  sf::Texture backgroundTexture;
  sf::Text text;
  sf::Text menuText[6];

  string timeLoop = "Time Loop";
  string menu[6]={"Start Game", "Continue Playing", "View Levels", "View Saves", "Settings", "Exit"};

  int currentMenuItem=0;

  bool enterBool;
  bool keyPress;
};
