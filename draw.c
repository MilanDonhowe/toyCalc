// File which cotains the function for drawing the calculator
#include "calc.h"

void drawCalc(void){

    //function to draw the calculator!
    char * calcDisp = addends[channel];


    mvaddch(1,0, ACS_ULCORNER);
    whline(stdscr, ACS_HLINE, 8);
    mvaddch(1, 9, ACS_URCORNER);
    mvaddch(2, 0, ACS_VLINE);
    printw("%s", calcDisp);//input/output line calc screen
    mvaddch(2, 9, ACS_VLINE);
    mvaddch(3, 0, ACS_LTEE);    
    whline(stdscr, ACS_HLINE, 8);
    mvaddch(3, 9, ACS_RTEE);
    mvaddch(4, 0, ACS_VLINE);
    addstr(" 7 8 9 /");
    mvaddch(4, 9, ACS_VLINE);
    mvaddch(5, 0, ACS_VLINE);
    addstr(" 4 5 6 *");
    mvaddch(5, 9, ACS_VLINE);
    mvaddch(6, 0, ACS_VLINE);
    addstr(" 1 2 3 -");
    mvaddch(6, 9, ACS_VLINE);
    mvaddch(7, 0, ACS_VLINE);
    addstr(" 0 c = +");
    mvaddch(7, 9, ACS_VLINE);
    mvaddch(8, 0, ACS_LLCORNER);
    whline(stdscr, ACS_HLINE, 8);
    mvaddch(8, 9, ACS_LRCORNER);
    mvprintw(10, 0, "Press q to exit!");
    move(20, 0);

    refresh();
}
