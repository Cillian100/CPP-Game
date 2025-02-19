#include "ViewLevels.h"

ViewLevels::ViewLevels(sf::RenderWindow& win)
  :    SettingTemplate(win),
       window(win)
{
  numberOfMenuItems=3;  

  for(int a=0;a<numberOfMenuItems;a++){
    if(!levelIconTexture[a].loadFromFile("Graphics/level_" + to_string(a+1) + "_icon.png")){
      printf("Couldn't load level %d icon", to_string(a+1));
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

int ViewLevels::gameLoop(){
  templateUserInput();
  if(exitBool==true){
    exitBool=false;
    return 0;
  }
  return render();
}

int ViewLevels::render(){
  window.clear();
  templateRender();
  for(int a=0;a<numberOfMenuItems;a++){
    window.draw(levelIconSprite[a]);
  }

  window.display();
  if(enterBool==true){
    enterBool=false;
    return currentMenuItem+1;
  }else{
    return 10;
  }
}

