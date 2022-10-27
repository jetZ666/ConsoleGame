#include <iostream>
#include <conio.h>
#include <windows.h>
#include "setup.cpp"
#include "menu.cpp"
#include "gun.cpp"

using namespace std;

void Draw()
{
    SetupClass setup;
    setup.Optimization(0, 0);
    if (level == 1 && flag_1 == 1)
    {
        x = 1;
        y = 1;
        lvl = lvl1;
        finish_x = 5;
        finish_y = 5;
        flag_1 = 0;
    }
    if (level == 2 && flag_2 == 1)
    {
        x = 1;
        y = 1;
        lvl = lvl2;
        finish_x = 34;
        finish_y = 13;
        flag_2 = 0;
    }
    if (level == 3 && flag_3 == 1)
    {
        x = 1;
        y = 1;
        finish_x = 37;
        finish_y = 18;
        lvl = lvl3;
        flag_3 = 0;
    }
    if (level == 4 && flag_4 == 1)
    {
        x = 1;
        y = 1;
        finish_x = 1;
        finish_y = 5;
        lvl = lvl4;
        flag_4 = 0;
    }
    if (level == 5)
    {
        gameover = true;
    }

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    for (int i = 0; i < height; i++)
    {
        if (i != y && i != finish_y)
        {
            SetConsoleTextAttribute(hConsole, map_color);
            cout << lvl[i] << endl;
        }
        else
        {
            for (int j = 0; j < width; j++)
            {
                if (lvl[i][j] == '*')
                {
                    SetConsoleTextAttribute(hConsole, player_color);
                }
                if (lvl[i][j] == 'f')
                {
                    SetConsoleTextAttribute(hConsole, 2);
                }
                cout << lvl[i][j];
                SetConsoleTextAttribute(hConsole, map_color);
            }
            cout << endl;
        }
    }
    SetConsoleTextAttribute(hConsole, 3);    
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
    MenuClass menu;
        
    setup.Settings();
    switch (menu.Menu())
    {
    case 0:
        while (!gameover)
        {
            Draw();
            Input();
            PlayerLogic();
        }
        break;
    case 1:
        switch (menu.Levels())
        {
        case 0:
            level = 1;
            break;
        case 1:
            level = 2;
            break;
        case 2:
            level = 3;
            break;
        case 3:
            level = 4;
            break;
        }
        while (!gameover)
        {
            Draw();
            Input();
            PlayerLogic();
        }
        break;
    case 2:
        return 0;
    }
    menu.EndGame();
    return 0;
}
