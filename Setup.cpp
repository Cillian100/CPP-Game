#include <SFML/Graphics.hpp>

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
  
private:
  int x;
  int y;
  int radius;
};
  
class Game{
public:
  Game()
    : window(sf::VideoMode(800, 600), "Platformer!"),
      circle(100, 100, 100){
    shape.setRadius(circle.getRadius());
    shape.setPosition(circle.getX(), circle.getY());
    shape.setFillColor(sf::Color::Green);
  }

  void gameLoop() {
    sf::Time t1 = sf::milliseconds(10);
    while (window.isOpen()) {
      sf::Event event;
      while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
          window.close();
        }
      }
      calculate();
      render();
      sf::sleep(t1);
    }
  }

private:
  void render() {
    window.clear();
    window.draw(shape);
    window.display();
  }

  void calculate(){
    shape.move(1, 1);
  }

  sf::RenderWindow window;
  sf::CircleShape shape;
  Circle circle;
};

int main() {
  Game game;
  game.gameLoop();

  return 0;
}
