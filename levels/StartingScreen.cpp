#include "StartingScreen.h"

int StartingScreen::gameLoop(){
  userInput();
  return render();
}

void StartingScreen::userInput(){
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
    if(!keyPress){
      currentMenuItem--;
    }
    keyPress=true;
  }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
    if(!keyPress){
      currentMenuItem++;
    }
    keyPress=true;
  }else{
    keyPress=false;
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
    enterBool=true;
  }else{
    enterBool=false;
  }
  currentMenuItem=(currentMenuItem%6);
  if(currentMenuItem<0){
    currentMenuItem=currentMenuItem+6;
  }
}

int StartingScreen::render(){
  //view.reset(sf::FloatRect(0,0,800,600));
  window.setView(window.getDefaultView());
  window.clear();
  window.draw(backgroundSprite);
  window.draw(text);
  for(int a=0;a<6;a++){
    if(a==currentMenuItem){
      menuText[a].setFillColor(sf::Color::Red);
    }else{
      menuText[a].setFillColor(sf::Color::White);
    }
    window.draw(menuText[a]);
  }
  window.display();

  if(currentMenuItem==0 && enterBool){
    return 1;
  }else if(currentMenuItem==2 && enterBool){
    return 10;
  }else if(currentMenuItem==4 && enterBool){
    return 11;
  }else{
    return 0;
  }
}

StartingScreen::StartingScreen(sf::RenderWindow& win) : window(win) {
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

