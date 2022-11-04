#include <iostream>
#include <conio.h>
#include <windows.h>
#include "setup.cpp"
#include "menu.cpp"
#include "gun.cpp"
#include "box.cpp"

using namespace std;

void ChangeLevel()
{
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
}

void Draw()
{
    SetupClass setup;
    setup.Optimization(0, 0);
    
    ChangeLevel();

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (lvl[finish_y+1][finish_x] == '*') lvl[finish_y+1][finish_x] = ' ';
    if (lvl[finish_y-1][finish_x] == '*') lvl[finish_y-1][finish_x] = ' ';
    if (lvl[finish_y][finish_x+1] == '*') lvl[finish_y][finish_x+1] = ' ';
    if (lvl[finish_y][finish_x-1] == '*') lvl[finish_y][finish_x-1] = ' ';
    
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
                if (i == y && j == x) lvl[i][j] = '*';
                if (lvl[i][j] == '*')
                {
                    if (i != y || j != x)
                    {
                        lvl[i][j] = ' ';
                    }
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
            last_move = L;
            break;
        case 77:
            dir = RIGHT;
            last_move = R;
            break;
        case 72:
            dir = UP;
            last_move = U;
            break;
        case 80:
            dir = DOWN;
            last_move = D;
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
        if (lvl[y][x-1] != '#' && lvl[y][x-1] != '<' && lvl[y][x-1] != '>' && lvl[y][x-1] != '^' && (lvl[y][x-1] != '&' || lvl[y][x-2] != '&') && (lvl[y][x-1] != '&' || lvl[y][x-2] != '#') 
            && (lvl[y][x-1] != '&' || lvl[y][x-2] != '<') && (lvl[y][x-1] != '&' || lvl[y][x-2] != '>') && (lvl[y][x-1] != '&' || lvl[y][x-2] != '^') && (lvl[y][x-1] != '&' || lvl[y][x-2] != 'f'))
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
        if (lvl[y][x+1] != '#' && lvl[y][x+1] != '<' && lvl[y][x+1] != '>' && lvl[y][x+1] != '^' && (lvl[y][x+1] != '&' || lvl[y][x+2] != '&') && (lvl[y][x+1] != '&' || lvl[y][x+2] != '#')
            && (lvl[y][x+1] != '&' || lvl[y][x+2] != '<') && (lvl[y][x+1] != '&' || lvl[y][x+2] != '>') && (lvl[y][x+1] != '&' || lvl[y][x+2] != '^') && (lvl[y][x+1] != '&' || lvl[y][x+2] != 'f'))
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
        if (lvl[y-1][x] != '#' && lvl[y-1][x] != '<' && lvl[y-1][x] != '>' && lvl[y-1][x] != '^' && (lvl[y-1][x] != '&' || lvl[y-2][x] != '&') && (lvl[y-1][x] != '&' || lvl[y-2][x] != '#')
            && (lvl[y-1][x] != '&' || lvl[y-2][x] != '<') && (lvl[y-1][x] != '&' || lvl[y-2][x] != '>') && (lvl[y-1][x] != '&' || lvl[y-2][x] != '^') && (lvl[y-1][x] != '&' || lvl[y-2][x] != 'f'))
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
        if (lvl[y+1][x] != '#' && lvl[y+1][x] != '<' && lvl[y+1][x] != '>' && lvl[y+1][x] != '^' && (lvl[y+1][x] != '&' || lvl[y+2][x] != '&') && (lvl[y+1][x] != '&' || lvl[y+2][x] != '#')
            && (lvl[y+1][x] != '&' || lvl[y+2][x] != '<') && (lvl[y+1][x] != '&' || lvl[y+2][x] != '>') && (lvl[y+1][x] != '&' || lvl[y+2][x] != '^') && (lvl[y+1][x] != '&' || lvl[y+2][x] != 'f'))
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
    GunClass gun;
    BoxClass box;

    while (true)
    {
        setup.Settings();
        switch (menu.Menu())
        {
        case 0:
            while (!gameover)
            {
                frames += 1;
                Draw();
                Input();
                PlayerLogic();
                box.box_move();
                gun.turel();
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
                frames += 1;
                Draw();
                Input();
                PlayerLogic();
                box.box_move();
                gun.turel();
            }
            break;
        case 2:
            return 0;
        }
        menu.EndGame();
    }
    return 0;
}
