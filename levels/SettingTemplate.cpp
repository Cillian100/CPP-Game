#include "SettingTemplate.h"


SettingTemplate::SettingTemplate(sf::RenderWindow& win) : window(win){
  if(!font.loadFromFile("Graphics/font.ttf")){
    printf("Couldn't load starting screen font\n");
  }

  if(!backgroundTexture.loadFromFile("Graphics/StartingScreen.png")){
    printf("Couldn't load starting screen background\n");
  }
  backgroundSprite.setTexture(backgroundTexture);
  backgroundSprite.setTextureRect(sf::IntRect(0,0,800,600));
  backgroundSprite.setColor(sf::Color(255,255,255,255));
  backgroundSprite.setPosition(0,0);

  enterBool=false;
}

void SettingTemplate::templateRender(){
  window.draw(backgroundSprite);
 
  for(int a=0;a<numberOfMenuItems;a++){
    if(currentMenuItem==a){
      text[a].setFillColor(sf::Color::Red);
    }else{
      text[a].setFillColor(sf::Color::White);
    }
    window.draw(text[a]);
  }
  
}

void SettingTemplate::templateUserInput(){
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || 
      sf::Keyboard::isKeyPressed(sf::Keyboard::D) || 
      sf::Keyboard::isKeyPressed(sf::Keyboard::S) || 
      sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
    if(!keyPress){
      currentMenuItem++;
    }
    keyPress=true;
  }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || 
      sf::Keyboard::isKeyPressed(sf::Keyboard::A) || 
      sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
      sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
    if(!keyPress){
      currentMenuItem--;
    }
    keyPress=true;
  }else{
    keyPress=false;
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
    if(!waitASec){
      enterBool=true;
      enterKeyBoolean=!enterKeyBoolean;
    }
    waitASec=true;
  }else{
    waitASec=false;
    enterBool=false;
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
    exitBool=true;
  }else{
    exitBool=false;
  }
  
  currentMenuItem=currentMenuItem%numberOfMenuItems;
  if(currentMenuItem<0){
    currentMenuItem=numberOfMenuItems-1;
  }

  return;
}
