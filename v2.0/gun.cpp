#include <iostream>
#include "setup.cpp"
#include "gun.h"

using namespace std;

int GunClass::calc(int i, int j, int k, char a, int f)
{
    if (lvl[i][k] == '#')
        return 0;
    if (lvl[i][k] == '&')
    {
        if (a == '<')
        {
            for (int m = k+1; m < width-2; m++)
            {
                if (lvl[i][m] != '*') lvl[i][m] = ' ';
            }
            return 0;
        }
        if (a == '>')
        {
            for (int m = k-1; m > 0; m--)
            {
                if (lvl[i][m] != '*') lvl[i][m] = ' ';
            }
            return 0;
        }
    }
    if (k % 3 == f)
    {
        lvl[i][k] = '+';
        if (i == y && k == x)
        {
            gameover = 1;
            return 0;
        }
    }
    else
    {
        if (lvl[i][k] != '#' && lvl[i][k] != '*')
            lvl[i][k] = ' ';
    }
    return 1; //without meaning
}

void GunClass::turel()
{
    static int f = 0;
    if (frames % 15 == 0)
    {
        if (f == 0) 
            f = 1;
        else{
            if (f == 1)
            {
                f = 2;
            }
            else
            {
                f = 0;
            }
        }
        frames = 0;
    }
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width-1; j++)
        {
            if (lvl[i][j] == '<')
            {
                for (int k = j+1; k < width-1; k++)
                {
                    if (calc(i, j, k, '<', f) == 0)
                        break;
                }
            }
            if (lvl[i][j] == '>')
            {
                for (int k = j-1; k > 0; k--)
                {
                    if (calc(i, j, k, '>', f) == 0)
                        break;
                }
            }
        }
    }
}
