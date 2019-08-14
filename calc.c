#include "calc.h"


char * addends[] = {"00000000", "00000000"};
char operation = '\0';


int main(){

    LTS = malloc(9 * sizeof(char));

    initscr();
    cbreak();/* remove line buffering but keep ctrl+functions */
    noecho();/*don't show the user typing on the keyboard */
    keypad(stdscr, TRUE);/*enable functions like mouse */
    
    MEVENT event;
    mousemask(BUTTON1_PRESSED, NULL);

    drawCalc();
    
    /* start recording number at index 0  */
    channel = 0;
    
    int running = 1;
    int userInput;
    while(running == 1){
        userInput = getch();
        if(userInput == 'q') running = 0;
        else if (userInput == KEY_MOUSE){
            if(getmouse(&event) == OK){
                
                chtype c;
                /* Find which character the user clicked on */
                if (event.x != 0 && event.x != 9 && event.y != 1 && event.y != 3 && event.y != 8){
                    c = mvinch(event.y, event.x);
                }
                move(20, 0);

                logicCalc(&c);
                drawCalc();
                /*printw("calc input: %c\n", (char) c); // code for debugging*/
            }
            refresh();
        }
    }
    endwin();
    return 0;
}