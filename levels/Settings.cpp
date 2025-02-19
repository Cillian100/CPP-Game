#include "Settings.h"

Settings::Settings(sf::RenderWindow& win) : SettingTemplate(win),
					       window(win) {
  currentMenuItem=0;
  numberOfMenuItems=1;

  for(int a=0;a<numberOfMenuItems;a++){
    text[a].setFont(font);
    text[a].setCharacterSize(50);
    text[a].setStyle(sf::Text::Regular);
    text[a].setPosition(100, 100);
  }

  if(fullScreenBool==true){
    text[0].setString("Fullscreen On");
  }else{
    text[0].setString("Fullscreen Off");
  }
}

int Settings::gameLoop(){
  templateUserInput();
  return render();
}

int Settings::render(){
  window.clear();
  templateRender();
  window.display();
  return 11;
}
