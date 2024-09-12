#include <SFML/Graphics.hpp>
#include "../entities/Robot.h"
#include "../entities/Block.h"
#include "../entities/Border.h"
#include "../entities/EndPoint.h"
#include <iostream>
#include <string>
#include <vector>
#pragma once
using namespace std;

class LevelTemplate{
  sf::RenderWindow& window;
 public:
  LevelTemplate(sf::RenderWindow& win);
  int templateLoop();
  void templateRender();
  void templateScrolling();
  int gameWin();
  int blockNumber=0;

  sf::Clock clock;
  sf::Texture backgroundTexture;
  sf::Texture gameOverTexture;
  sf::Sprite backgroundSprite;
  sf::Sprite gameOverSprite;
  sf::Font font;
  sf::Text text;
  sf::View view;
  vector<pair<int, char>> vecOfPairs;
  pair<int, char> pairKey;
  long int ticks=0;
  int robotX;
  int robotY;
  string youWon1="You completed level ";
  string youWon2="\nPress space to continue";
  int currentLevel;

  Robot robot;
  Block block[7]={
    Block(0,0,0,0,0,0),
    Block(0,0,0,0,0,0),
    Block(0,0,0,0,0,0),
    Block(0,0,0,0,0,0),
    Block(0,0,0,0,0,0),
    Block(0,0,0,0,0,0),
    Block(0,0,0,0,0,0)
  };
  Border border;
  EndPoint endPoint;

 private:
};
