#include "StartingScreen.h"

void StartingScreen::gameLoop(){
  userInput();
  render();
}

void StartingScreen::userInput(){
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
    printf("jef \n");
  }
}

void StartingScreen::render(){
  window.clear();
  window.draw(backgroundSprite);
  window.draw(text);
  for(int a=0;a<6;a++){
    window.draw(menuText[a]);
  }
  window.display();
}

StartingScreen::StartingScreen(sf::RenderWindow& win) : window(win) 
{
  if(!backgroundTexture.loadFromFile("Graphics/StartingScreen.png")){
    printf("Couldn't load starting screen background\n");
  }
  backgroundSprite.setTexture(backgroundTexture);
  backgroundSprite.setTextureRect(sf::IntRect(0,0,800,600));
  backgroundSprite.setColor(sf::Color(255,255,255,255));
  backgroundSprite.setPosition(0,0);

  if(!font.loadFromFile("Graphics/font.ttf")){
    printf("Couldn't load starting screen font\n");
  }
  text.setFont(font);
  text.setCharacterSize(100);
  text.setStyle(sf::Text::Regular);
  text.setPosition(70, 70);
  text.setString(timeLoop);

  for(int a=0;a<6;a++){
    menuText[a].setFont(font);
    menuText[a].setCharacterSize(50);
    menuText[a].setStyle(sf::Text::Regular);
    menuText[a].setPosition(100, 160+(50*a));
    menuText[a].setString(menu[a]);
  }
  cout << "wocky slosh " << endl;
}

