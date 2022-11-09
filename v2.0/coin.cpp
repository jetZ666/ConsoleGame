#include <iostream>
#include "setup.cpp"
#include "coin.h"

using namespace std;

inline void CoinClass::calcPrise()
{
    switch (level)
    {
    case 1:
        score += 10;
        break;
    case 2:
        score += 20;
        break;
    case 3:
        score += 25;
        break;
    case 4:
        score += 30;
        break;
    }
}

void CoinClass::get_coin()
{
    static int f = 0;
    static int coinX1 = 0, coinY1= 0, coinX2 = 0, coinY2= 0, coinX3 = 0, coinY3= 0, coinX4 = 0, coinY4= 0;

    if (f == 1)
    {
        switch (last_move)
        {
        case 1:
            if (coinX2 == x && coinY2 == y)
            {
                calcPrise();
            }
            break;
        case 2:
            if (coinX1 == x && coinY1 == y)
            {
                calcPrise();
            }
            break;
        case 3:
            if (coinX4 == x && coinY4 == y)
            {
                calcPrise();
            }
            break;
        case 4:
            if (coinX3 == x && coinY3 == y)
            {
                calcPrise();
            }
            break;
        }
        coinX1 = 0, coinY1= 0, coinX2 = 0, coinY2= 0, coinX3 = 0, coinY3= 0, coinX4 = 0, coinY4= 0;
    }

    f = 0;
    if (lvl[y][x+1] == '$')
    {
        f = 1;
        coinX1 = x+1;
        coinY1 = y;
    }
    if (lvl[y][x-1] == '$')
    {
        f = 1;
        coinX2 = x-1;
        coinY2 = y;
    }
    if (lvl[y+1][x] == '$')
    {
        f = 1;
        coinX3 = x;
        coinY3 = y+1;
    }
    if (lvl[y-1][x] == '$')
    {
        f = 1;
        coinX4 = x;
        coinY4 = y-1;
    }
}