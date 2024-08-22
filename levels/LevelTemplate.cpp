#include "LevelTemplate.h"

LevelTemplate::LevelTemplate(sf::RenderWindow& win)
  :window(win)
{
 if(!gameOverTexture.loadFromFile("Graphics/GameOverScreen.png")){
    printf("Couldn't load game over screen");
  }
  gameOverSprite.setTexture(gameOverTexture);
  gameOverSprite.setTextureRect(sf::IntRect(0,0,800,600));
  gameOverSprite.setColor(sf::Color(255,255,255,150));
  gameOverSprite.setPosition(0,0);

  clock.restart();

  if(!font.loadFromFile("Graphics/font.ttf")){
    printf("Couldn't load font.ttf");
  }
  text.setFont(font);
  text.setCharacterSize(90);
  text.setStyle(sf::Text::Regular);
  text.setFillColor(sf::Color::White);

  pairKey=make_pair(6969696969, 'g');
  vecOfPairs.push_back(pairKey);
}

int LevelTemplate::gameLoop(){
  render();
}

int LevelTemplate::render(){
  window.clear();
  window.draw(backgroundSprite);

  for(int a=0;a<blockNumber;a++){
    for(int b=0;b<block[b].getNumOfSprites();b++){
      window.draw(block[b].getSprite2(a));
    }
  }
  
  window.display();
}
