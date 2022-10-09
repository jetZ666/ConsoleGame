#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

bool gameover;
const int width = 50;
const int height = 20;
int x, y, score, map_color, player_color, StrelMenuPos;
enum eDir {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDir dir;
string player;
int pl_i = 7, pl_j = 6;
int level = 1, finish_posX, finish_posY;

char mn[20][20] = {
	"###################",
    "#                 #",
    "#                 #",
    "#      menu       #",
    "#                 #",
    "#                 #",
    "#                 #",
    "#     -start      #",
    "#      exit       #",
    "#                 #",
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

void Setup()
{
    gameover = false;
    StrelMenuPos = 0;
    player = "*";
    player_color = 5;
    map_color = 1;
    dir = STOP;
    x = width / 2 - 1;
    y = height / 2 - 1;
    score = 0;
    finish_posX = 5;
    finish_posY = 5;
}

void Optimization(int x, int y)
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

int Menu()
{
    while(true)
    {
        Optimization(0, 0);
	    for (int i = 0; i<20; i++)
        {
            cout << mn[i] << endl;
        }
        int ke = _getch();
	    if (ke == 13)
        {
		    if (StrelMenuPos == 0)
            {
		    	return 0;
	    	}
	    	//exit v menu
	    	else return 1;
	    }
	    if (ke == 27)
        {
	    	//exit
		    return 0;
	    }
        int k = _getch();
	    switch (k)
	    {
		case 72:
			//vverh
			if (mn[pl_i-1][pl_j+1] != ' ')
            {
				mn[pl_i-1][pl_j] = '-';
				mn[pl_i][pl_j] = ' ';
				pl_i -= 1;
				StrelMenuPos = 0;
			}
			break;
		case 80:
			// vniz
			if (mn[pl_i+1][pl_j+1] != ' ')
            {
				mn[pl_i+1][pl_j] = '-';
				mn[pl_i][pl_j] = ' ';
				pl_i += 1;
				StrelMenuPos = 1;
			}
			break;
	    }
    }
}

void lvl_1()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            if (j == 0 || j == width-1)
            {
                SetConsoleTextAttribute(hConsole, map_color);
                cout << "#";
            }
            if (i == y && j == x)
            {
                SetConsoleTextAttribute(hConsole, player_color);
                cout << player;
                SetConsoleTextAttribute(hConsole, map_color);
            }
            else
                if (i == finish_posY && j == finish_posX)
                {
                    cout << "F";
                }
                else
                {
                    if (j != width-1)
                    cout << " ";
                }
        }
        cout << endl;
    }
}

void lvl_2()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            if (j == 0 || j == width-1)
            {
                SetConsoleTextAttribute(hConsole, map_color);
                cout << "#";
            }
            if (i == y && j == x)
            {
                SetConsoleTextAttribute(hConsole, player_color);
                cout << player;
                SetConsoleTextAttribute(hConsole, map_color);
            }
            else
                if (i == finish_posY && j == finish_posX)
                {
                    cout << "F";
                }
                else
                {
                    if (j != width-1)
                    cout << ".";
                }
        }
        cout << endl;
    }
}

void Draw()
{
    Optimization(0, 0);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < width+1; i++)
    {
        SetConsoleTextAttribute(hConsole, map_color);
        cout << "#";
    }
    cout << endl;

    switch (level)
    {
    case 1:
        lvl_1();
        break;
    case 2:
        lvl_2();
        break;
    default:
        break;
    }

    for (int i = 0; i < width+1; i++)
    {
        SetConsoleTextAttribute(hConsole, map_color);
        cout << "#";
    }
    cout << endl;
    cout << "Score: " << score << endl;
}

void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 75:
            // levo
            dir = LEFT;
            break;
        case 77:
            // pravo
            dir = RIGHT;
            break;
        case 72:
            // vverh
            dir = UP;
            break;
        case 80:
            //vniz
            dir = DOWN;
            break;
        case 'x':
            gameover = true;
            break;
        default:
            break;
        }
    }
}

void PlayerLogic()
{
    switch (dir)
    {
    case LEFT:
        if (x > 0)
        {
            x--;
            dir = STOP;
        }
        break;
    case RIGHT:
        if (x+2 < width)
        {
            //player = "→";
            x++;
            dir = STOP;
        }
        break;
    case UP:
        if (y > 0)
        {
            y--;
            dir = STOP;
        }
        break;
    case DOWN:
        if (y+1 < height)
        {
            y++;
            dir = STOP;
        }
    default:
        break;
    }

    if (x == finish_posX && y == finish_posY)
    {
        level += 1;
        finish_posX = 10;
        finish_posY = 10;
        system("cls");
    }
}

int main()
{
    Setup();
    if (Menu()==1)
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
