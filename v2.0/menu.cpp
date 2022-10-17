#include <conio.h>
#include "menu.h"
#include "setup.h"

#pragma once
#ifndef MENU_CPP
#define MENU_CPP

using namespace std;

int MenuClass::Menu()
{
    while(true)
    {
        SetupClass setup;
        setup.Optimization(0, 0);
	    for (int i = 0; i<20; i++)
        {
            cout << mn[i] << endl;
        }
        int ke = _getch();
	    if (ke == 13)
        {
            switch (StrelMenuPos)
            {
            case 0:
                return 0;
            case 1:
                //levels v stadii razrabotki!!!----------------------------
                return 0;
                break;
            case 2:
                return 2;
            }
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
				StrelMenuPos -= 1;
			}
			break;
		case 80:
			// vniz
			if (mn[pl_i+1][pl_j+1] != ' ')
            {
				mn[pl_i+1][pl_j] = '-';
				mn[pl_i][pl_j] = ' ';
				pl_i += 1;
				StrelMenuPos += 1;
			}
			break;
	    }
    }
}

#endif