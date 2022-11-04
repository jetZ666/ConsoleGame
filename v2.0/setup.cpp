#include <iostream>
#include <ctime>
#include <windows.h>
#include "setup.h"

#pragma once
#ifndef SETUP_CPP
#define SETUP_CPP

using namespace std;

bool gameover;
const int width = 40;
const int height = 20;
int x, y, score, map_color, player_color, StrelMenuPos = 0, StrelMenuPos_lvl = 0;
enum eDir {STOP = 0, LEFT, RIGHT, UP, DOWN};
enum lastStep {NONE, L, R, U, D};
eDir dir;
lastStep last_move;
string player;
int coordMn1_i = 7, coordMn1_j = 6, coordMn2_i = 7, coordMn2_j = 6;
int level;
string *lvl;
int flag_1, flag_2, flag_3, flag_4;
int finish_x, finish_y;
int frames = 0;

string mn1[20] = {
    "###################",
    "#                 #",
    "#                 #",
    "#      menu       #",
    "#                 #",
    "#                 #",
    "#                 #",
    "#     -start      #",
    "#      levels     #",
    "#      exit       #",
    "#                 #",
    "#                 #",
    "#                 #",
    "#                 #",
    "#                 #",
    "~~~~~~~~~~~~~~~~~~~",
    "|made by N.Tokarev|",
    "~~~~~~~~~~~~~~~~~~~",
    "###################",
    "###################"
};

string mn2[20] = {
    "###################",
    "#                 #",
    "#                 #",
    "#      levels     #",
    "#                 #",
    "#                 #",
    "#                 #",
    "#     -level_1    #",
    "#      level_2    #",
    "#      level_3    #",
    "#      level_4    #",
    "#                 #",
    "#                 #",
    "#                 #",
    "#                 #",
    "~~~~~~~~~~~~~~~~~~~",
    "|made by N.Tokarev|",
    "~~~~~~~~~~~~~~~~~~~",
    "###################",
    "###################"
};

string mn3[20] = {
    "###################",
    "#                 #",
    "#                 #",
    "#                 #",
    "#    Game Over    #",
    "#                 #",
    "#                 #",
    "#  |-----------|  #",
    "#  |Press Enter|  #",
    "#  |-----------|  #",
    "#                 #",
    "#                 #",
    "#                 #",
    "#                 #",
    "#                 #",
    "~~~~~~~~~~~~~~~~~~~",
    "|made by N.Tokarev|",
    "~~~~~~~~~~~~~~~~~~~",
    "###################",
    "###################"
};

string lvl1[20]{
    "#######################################",
    "#*                  &                 #",
    "#                   &                 #",
    "#                  &&                 #",
    "#                                     #",
    "#    f                                #",
    "#                                     #",
    "#                                     #",
    "#                                     #",
    "#                                     #",
    "#                        <            #",
    "#                                     #",
    "#                                     #",
    "#             >                       #",
    "#                                     #",
    "#                <                    #",
    "#                                     #",
    "#        >                            #",
    "#                                     #",
    "#######################################"
};

string lvl2[20]{
    "#######################################",
    "#*                                    #",
    "#                                     #",
    "#                                     #",
    "#                   ##############    #",
    "#                   #                 #",
    "#                   #                 #",
    "#                   #                 #",
    "#                                     #",
    "#                   ##########        #",
    "#                            #        #",
    "#                            #        #",
    "#                            #        #",
    "#                            #   f    #",
    "#                            ##########",
    "#                                     #",
    "#                                     #",
    "#                                     #",
    "#                                     #",
    "#######################################"
};

string lvl3[20]{
    "#######################################",
    "#*                                    #",
    "#                                     #",
    "#                                     #",
    "#                                     #",
    "#                                     #",
    "#                                     #",
    "#                                     #",
    "#                                     #",
    "#                   ##########        #",
    "#                            #        #",
    "#                            #        #",
    "#                            #        #",
    "#                            #        #",
    "#                            ##########",
    "#                                     #",
    "#                                     #",
    "#                                     #",
    "#                                   f #",
    "#######################################"
};

string lvl4[20]{
    "#######################################",
    "#*                                    #",
    "#                                     #",
    "#                                     #",
    "#                   ##############    #",
    "#f                  #                 #",
    "#                   #                 #",
    "#                   #                 #",
    "#                                     #",
    "#                                     #",
    "#                                     #",
    "#                                     #",
    "#                                     #",
    "#                                     #",
    "#                                     #",
    "#                                     #",
    "#                                     #",
    "#                                     #",
    "#                                     #",
    "#######################################"
};

void SetupClass::Settings()
{
    gameover = false;
    player_color = 5, map_color = 1;
    dir = STOP;
    last_move = NONE;
    x = 1, y = 1;
    score = 0;
    level = 1;
    finish_x = 5, finish_y = 5;
    flag_1 = 1, flag_2 = 1, flag_3 = 1, flag_4 = 1;
}

void SetupClass::Optimization(int x, int y)
{
    //set cursor on pos x, y
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    // hide 'karetka' in console
    void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(handle,&structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo( handle, &structCursorInfo );
}

#endif