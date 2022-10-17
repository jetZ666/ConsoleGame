#include <iostream>
#include <windows.h>
#include "setup.h"

#pragma once
#ifndef SETUP_CPP
#define SETUP_CPP

using namespace std;

void SetupClass::Settings()
{
    gameover = false;
    StrelMenuPos = 0;
    player_color = 5;
    map_color = 1;
    dir = STOP;
    x = 1;
    y = 1;
    score = 0;
    lvl = lvl1;
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