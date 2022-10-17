#include <iostream>

#pragma once
#ifndef SETUP_H
#define SETUP_H

using namespace std;

bool gameover;
const int width = 40;
const int height = 20;
int x, y, score, map_color, player_color, StrelMenuPos;
enum eDir {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDir dir;
eDir last_move;
string player;
int pl_i = 7, pl_j = 6;
int level = 1;
string *lvl;
int flag_2 = 1;
int flag_3 = 1;
int flag_4 = 1;

char mn[20][20] = {
    "###################",
    "#                 #",
    "#                 #",
    "#      menu       #",
    "#                 #",
    "#                 #",
    "#                 #",
    "#     -start      #",
    "#      level      #",
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

string lvl1[20]{
    "#######################################",
    "#*                                    #",
    "#                                     #",
    "#                                     #",
    "#                                     #",
    "#    f                                #",
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
    "#                                     #",
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
    "#                            #        #",
    "#                            ##########",
    "#                                     #",
    "#                                     #",
    "#                                     #",
    "#                                     #",
    "#######################################"
};

class SetupClass
{
public:
    void Settings();
    void Optimization(int x, int y);
};

#endif