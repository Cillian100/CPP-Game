#include <SFML/Graphics.hpp>
#include "LevelTemplate.h"

class Level_3 : public LevelTemplate{
  sf::RenderWindow& window;
 public:
  Level_3(sf::RenderWindow& win);
  ~Level_3();
  int gameLoop();
 private:
};
