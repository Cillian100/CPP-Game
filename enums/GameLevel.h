#ifndef GAMESTATE_H_
#define GAMESTATE_H_

enum GameLevel{
    STARTING_SCREEN,
    LEVEL_1,
    LEVEL_2,
    LEVEL_3,
    VIEW_LEVELS,
    SETTINGS,
    EXIT
};

extern GameLevel gameLevel;

#endif
