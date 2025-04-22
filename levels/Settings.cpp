#include "Settings.h"

Settings::Settings(sf::RenderWindow& win) : SettingTemplate(win), window(win) {
  currentMenuItem=0;
  numberOfMenuItems=2;

  for(int a=0;a<numberOfMenuItems;a++){
    text[a].setFont(font);
    text[a].setCharacterSize(50);
    text[a].setStyle(sf::Text::Regular);
    text[a].setPosition(100, 100+(50*a));
  }

  if(fullScreenBool==true){
    text[0].setString("Fullscreen On");
  }else{
    text[0].setString("Fullscreen Off");
  }

  text[1].setString("Return");

  fullScreenBool=false;
  toggle=false;
}

int Settings::gameLoop(){
  templateUserInput();
  if(currentMenuItem==0 && enterKeyBoolean!=fullScreenBool){
    toggleFullScreen();
    enterKeyBoolean=fullScreenBool;
  }
  if(currentMenuItem==1 && enterKeyBoolean){
    return 0;
  }
  return render();
}

int Settings::render(){
  window.clear();
  templateRender();
  window.display();
  return 11;
}

void Settings::toggleFullScreen(){
  toggle=!toggle;
  if(toggle){
    window.create(sf::VideoMode(800, 600), "Platformer!", sf::Style::Fullscreen);
  }else{
    window.create(sf::VideoMode(800, 600), "Platformer!", sf::Style::Default);
  }
}