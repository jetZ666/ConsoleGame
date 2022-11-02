#include <iostream>

#include "setup.cpp"
#include "gun.h"

using namespace std;

void GunClass::turel()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width-1; j++)
        {
            if (lvl[i][j] == '<')
            {
                for (int k = j+1; k < width-1; k+=2)
                {
                    if (lvl[i][k] != '#')
                    {
                        lvl[i][k] = '+';
                    }
                    if (i == y && k == x)
                    {
                        gameover = 1;
                        break;
                    }
                }
            }
            // ------------------------------ 
        }
    }
}
