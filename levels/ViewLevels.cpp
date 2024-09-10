#include "ViewLevels.h"

int ViewLevels::gameLoop(){
  userInput();
  return render();
}

void ViewLevels::userInput(){
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
    if(!keyPress){
      currentMenuItem++;      
    }
    keyPress=true;
  }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
    if(!keyPress){
      currentMenuItem--;      
    }
    keyPress=true;
  }else{
    keyPress=false;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
    if(waitASec==false){
      enterBool=true;
    }
  }else{
    waitASec=false;
    enterBool=false;
  }
  currentMenuItem=currentMenuItem%numberOfMenuItems;
  return;
}

int ViewLevels::render(){
  window.clear();
  window.draw(backgroundSprite);
  for(int a=0;a<numberOfMenuItems;a++){
    if(currentMenuItem==a){
      text[a].setFillColor(sf::Color::Red);
    }else{
      text[a].setFillColor(sf::Color::White);
    }
    window.draw(text[a]);
  }
  for(int a=0;a<numberOfMenuItems;a++){
    window.draw(levelIconSprite[a]);
  }
  window.display();
  if(enterBool==true){
    return currentMenuItem+1;
  }else{
    return 10;
  }
}

ViewLevels::ViewLevels(sf::RenderWindow& win) : window(win){
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

  for(int a=0;a<numberOfMenuItems;a++){
    if(!levelIconTexture[a].loadFromFile("Graphics/level_" + to_string(a+1) + "_icon.png")){
      //      printf("Couldn't load level " + to_string(a) + " icon");
    }
    levelIconSprite[a].setTexture(levelIconTexture[a]);
    levelIconSprite[a].setTextureRect(sf::IntRect(0,0,100,75));
    levelIconSprite[a].setColor(sf::Color(255,255,255,255));
    levelIconSprite[a].setPosition(105+(a*150), 75);
  }
  
  for(int a=0;a<numberOfMenuItems;a++){
    text[a].setFont(font);
    text[a].setCharacterSize(50);
    text[a].setStyle(sf::Text::Regular);
    text[a].setPosition(100+(a*150), 150);    
    text[a].setString("level " + to_string(a));
  }

}
