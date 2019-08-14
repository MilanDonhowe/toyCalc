/* Header file containing the global includes*/

#ifndef LOADED_CALC_H   
#define LOADED_CALC_H

    #include <ncurses.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <ctype.h>
    #include <inttypes.h>

    void drawCalc(void);
    void logicCalc(chtype *input);


    char * addends[2];
    int channel;
    char * LTS;//long term storage for answer
    char operation;
#endif
