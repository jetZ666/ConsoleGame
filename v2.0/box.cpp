#include <iostream>
#include "setup.cpp"
#include "box.h"

using namespace std;


void BoxClass::box_move()
{
    static int f = 0;
    static int boxX1 = 0, boxY1= 0, boxX2 = 0, boxY2= 0, boxX3 = 0, boxY3= 0, boxX4 = 0, boxY4= 0;

    if (f == 1)
    {
        switch (last_move)
        {
        case 1:
            if (boxX2 != 0 && boxY2 != 0)
            {
                lvl[y][x-1] = '&';
            }
            break;
        case 2:
            if (boxX1 != 0 && boxY1 != 0)
            {
                lvl[y][x+1] = '&';
            }
            break;
        case 3:
            if (boxX4 != 0 && boxY4 != 0)
            {
                lvl[y-1][x] = '&';
            }
            break;
        case 4:
            if (boxX3 != 0 && boxY3 != 0)
            {
                lvl[y+1][x] = '&';
            }
            break;
        }
        boxX1 = 0, boxY1= 0, boxX2 = 0, boxY2= 0, boxX3 = 0, boxY3= 0, boxX4 = 0, boxY4= 0;
    }

    f = 0;
    if (lvl[y][x+1] == '&')
    {
        f = 1;
        boxX1 = x+1;
        boxY1 = y;
    }
    if (lvl[y][x-1] == '&')
    {
        f = 1;
        boxX2 = x-1;
        boxY2 = y;
    }
    if (lvl[y+1][x] == '&')
    {
        f = 1;
        boxX3 = x;
        boxY3 = y+1;
    }
    if (lvl[y-1][x] == '&')
    {
        f = 1;
        boxX4 = x;
        boxY4 = y-1;
    }
}