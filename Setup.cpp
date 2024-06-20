#include <SFML/Graphics.hpp>
#include <iostream>

class Circle{
public:
  Circle(int ex, int why, int rad){
    x=ex;
    y=why;
    radius=rad;
  }

  int getX(){
    return x;
  }
  int getY(){
    return y;
  }
  int getRadius(){
    return radius;
  }
  void setX(int ex){
    x=ex;
  }
  void setY(int why){
    y=why;
  }
  
private:
  int x;
  int y;
  int radius;
};

class Square{
public:
  Square(int ex, int why, int rad, int wid){
    x=ex;
    y=why;
    radius=rad;
    width=wid;
  }

  int getX(){
    return x;
  }
  int getY(){
    return y;
  }
  int getRadius(){
    return radius;
  }
  int getWidth(){
    return width;
  }

private:
  int x;
  int y;
  int radius;
  int width;
};
  
class Game{
public:
  Game()
    : window(sf::VideoMode(800, 600), "Platformer!"),
      circle(100, 100, 100),
      mouse(0, 0, 100),
      square(0, 0, 800, 600){
    shape.setRadius(circle.getRadius());
    shape.setPosition(circle.getX(), circle.getY());
    shape.setFillColor(sf::Color::Green);

    cursor.setRadius(mouse.getRadius());
    cursor.setPosition(mouse.getX(), mouse.getY());
    cursor.setFillColor(sf::Color::Blue);

    box.setSize(sf::Vector2f(800,600));
    box.setPosition(square.getX(), square.getY());
    box.setFillColor(sf::Color::Red);

    window.setMouseCursorVisible(false);
    window.setFramerateLimit(60);
    
  }

  void gameLoop() {
    sf::Time t1 = sf::milliseconds(10);
    sf::Clock clock;
    
    while (window.isOpen()) {
      float currentTime = clock.restart().asSeconds();
      float fps = 1.0f/(currentTime);
      
      std::cout<<"fps "<< fps << std::endl;
       
      while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
          window.close();
        }
      }
      
      mouseFunction();
      calculate();
      render();
      collision();
    }
  }

private:
  void mouseFunction(){
    sf::Vector2i position = sf::Mouse::getPosition(window);
    std::cout << position.x << " " << position.y << std::endl;
    mouse.setX(position.x - mouse.getRadius());
    mouse.setY(position.y - mouse.getRadius());
    cursor.setPosition(mouse.getX(), mouse.getY());

    if(event.type == sf::Event::MouseButtonPressed){
      mousePressed=true;
    }else{
      mousePressed=false;
    }
    
  }
  void render() {
    window.clear();
    window.draw(shape);
    if(mousePressed){
      cursor.setFillColor(sf::Color::Blue);
    }else{
      cursor.setFillColor(sf::Color::Red);
    }
    window.draw(cursor);
    window.display();
    
  }

  void calculate(){
    shape.move(1, 1);
  }

  void collision(){
  }

  sf::RenderWindow window;
  sf::CircleShape shape;
  sf::CircleShape cursor;
  sf::RectangleShape box;
  sf::Event event;
  bool mousePressed;
  Circle circle;
  Circle mouse;
  Square square;
};

int main() {
  Game game;
  game.gameLoop();

  return 0;
}
