#include <SFML/Graphics.hpp>
#include "Block.h"
#include <string>
#include <vector>
#pragma once
using namespace std;

class LevelTemplate{
  sf::RenderWindow& window;
 public:
  LevelTemplate(sf::RenderWindow& win);
  int gameLoop();
  int render();
  int blockNumber;

  sf::Clock clock;
  sf::Texture backgroundTexture;
  sf::Texture gameOverTexture;
  sf::Sprite backgroundSprite;
  sf::Sprite gameOverSprite;
  sf::Font font;
  sf::Text text;
  vector<pair<int, char>> vecOfPairs;
  pair<int, char> pairKey;

 private:
};
