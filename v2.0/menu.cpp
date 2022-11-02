#include <conio.h>
#include "menu.h"
#include "setup.h"

#pragma once
#ifndef MENU_CPP
#define MENU_CPP

using namespace std;

int MenuClass::Menu()
{
	string *mn = new string;
	mn = mn1;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 3);

    while(true)
    {
        SetupClass setupMenu;
        setupMenu.Optimization(0, 0);
	    for (int i = 0; i<20; i++)
        {
            cout << mn[i] << endl;
        }
        int ke = _getch();
	    if (ke == 13)
        {
			return StrelMenuPos;
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
			if (mn[coordMn1_i-1][coordMn1_j+1] != ' ')
            {
				mn[coordMn1_i-1][coordMn1_j] = '-';
				mn[coordMn1_i][coordMn1_j] = ' ';
				coordMn1_i -= 1;
				StrelMenuPos -= 1;
			}
			break;
		case 80:
			// vniz
			if (mn[coordMn1_i+1][coordMn1_j+1] != ' ')
            {
				mn[coordMn1_i+1][coordMn1_j] = '-';
				mn[coordMn1_i][coordMn1_j] = ' ';
				coordMn1_i += 1;
				StrelMenuPos += 1;
			}
			break;
	    }
    }
	delete mn;
}

int MenuClass::Levels()
{
	string *mn = new string;
	mn = mn2;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 3);

    while(true)
    {
        SetupClass setupLevels;
        setupLevels.Optimization(0, 0);
	    for (int i = 0; i<20; i++)
        {
            cout << mn[i] << endl;
        }
        int ke = _getch();
	    if (ke == 13)
        {
			return StrelMenuPos_lvl;
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
			if (mn[coordMn2_i-1][coordMn2_j+1] != ' ')
            {
				mn[coordMn2_i-1][coordMn2_j] = '-';
				mn[coordMn2_i][coordMn2_j] = ' ';
				coordMn2_i -= 1;
				StrelMenuPos_lvl -= 1;
			}
			break;
		case 80:
			// vniz
			if (mn[coordMn2_i+1][coordMn2_j+1] != ' ')
            {
				mn[coordMn2_i+1][coordMn2_j] = '-';
				mn[coordMn2_i][coordMn2_j] = ' ';
				coordMn2_i += 1;
				StrelMenuPos_lvl += 1;
			}
			break;
	    }
    }
	delete mn;
}

void MenuClass::EndGame()
{
	system("cls");

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 3);

	while (true)
	{
		SetupClass setupEnd;
		setupEnd.Optimization(0, 0);
		for (int i = 0; i < 20; i++)
		{
			cout << mn3[i] << endl;;
		}
		if (_kbhit)
		{
			if (_getch()==13) break;
		}
	}
}
#endif