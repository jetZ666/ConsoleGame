#include <iostream>
#include <conio.h>
#include <windows.h>
#include "setup.cpp"
#include "menu.cpp"

using namespace std;

void Draw()
{
    SetupClass setup;
    setup.Optimization(0, 0);
    if (level == 2 && flag_2 == 1)
    {
        x = 1;
        y = 1;
        lvl = lvl2;
        flag_2 = 0;
    }
    // dopisat` ostal`nie levels
    for (int i = 0; i < height; i++)
        cout << lvl[i] << endl;
    cout << "Score: " << score << "        Level - " << level << endl;
}

void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 75:
            dir = LEFT;
            break;
        case 77:
            dir = RIGHT;
            break;
        case 72:
            dir = UP;
            break;
        case 80:
            dir = DOWN;
            break;
        case 'x':
            gameover = true;
            break;
        }
    }
}

void PlayerLogic()
{
    switch (dir)
    {
    case LEFT:
        if (lvl[y][x-1] != '#')
        {
            if (lvl[y][x-1] == 'f')
            {
                level += 1;
                break;
            }
            lvl[y][x] = ' ';
            x--;
            lvl[y][x] = '*';
            dir = STOP;
        }
        break;    
    case RIGHT:
        if (lvl[y][x+1] != '#')
        {
            if (lvl[y][x+1] == 'f')
            {
                level += 1;
                break;
            }
            lvl[y][x] = ' ';
            x++;
            lvl[y][x] = '*';
            dir = STOP;
        }
        break;
    case UP:
        if (lvl[y-1][x] != '#')
        {
            if (lvl[y-1][x] == 'f')
            {
                level += 1;
                break;
            }
            lvl[y][x] = ' ';
            y--;
            lvl[y][x] = '*';
            dir = STOP;
        }
        break;
    case DOWN:
        if (lvl[y+1][x] != '#')
        {
            if (lvl[y+1][x] == 'f')
            {
                level += 1;
                break;
            }
            lvl[y][x] = ' ';
            y++;
            lvl[y][x] = '*';
            dir = STOP;
        }
        break;
    }
}

int main()
{
    SetupClass setup;
    setup.Settings();

    MenuClass menu;
    if (menu.Menu()==2)
        return 0;
    else
    {
        while (!gameover)
        {
            Draw();
            Input();
            PlayerLogic();
        }
    }
}
