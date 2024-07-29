#OBJS specifies which files to compile as part of the project
OBJS = Setup.cpp levels/StartingScreen.cpp entities/Robot.cpp entities/Block.cpp levels/Level_1.cpp entities/Border.cpp entities/Square.cpp entities/InfoButton.cpp entities/Mouse.cpp entities/RobotClone.cpp entities/EndPoint.cpp

CC = g++
COMPILER_FLAGS = -w
LINKER_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = game

#This is the target that compiles our executable
all : $(OBJS)
	g++ $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
	./game

