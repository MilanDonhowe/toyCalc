// File which cotains the function for drawing the calculator
#include "calc.h"

#define CORNER '+'
#define VLINE '|'


void drawCalc(void){


    //function to draw the calculator!
    char * calcDisp = addends[channel];
    char calcEdge[] = "+--------+";
    char calcMid[] = "|--------|";
    mvprintw(1, 0, calcEdge);
    mvaddch(2, 0, VLINE);
    printw("%s", calcDisp);
    mvaddch(2, 9, VLINE);
    mvprintw(3, 0, "%s", calcMid);
    mvaddch(4, 0, VLINE);
    addstr(" 7 8 9 /");
    mvaddch(4, 9, VLINE);
    mvaddch(5, 0, VLINE);
    addstr(" 4 5 6 *");
    mvaddch(5, 9, VLINE);
    mvaddch(6, 0, VLINE);
    addstr(" 1 2 3 -");
    mvaddch(6, 9, VLINE);
    mvaddch(7, 0, VLINE);
    addstr(" 0 c = +");
    mvaddch(7, 9, VLINE);
    mvprintw(8, 0, "%s", calcEdge);
    mvprintw(10, 0, "Press q to exit!");
    move(20, 0);

    refresh();
}
