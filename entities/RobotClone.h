#include <SFML/Graphics.hpp>
#include "Square.h"
#include <vector>
#include "Robot.h"
using namespace std;

#pragma once

class RobotClone : public Robot{
 public:
  void getPosition();
  void automatedInput(char key);
  void robotOnRobotCollision(Robot &robot);
  RobotClone(int inputX, int inputY, int inputWidth, int inputHeight);
 private:
};
