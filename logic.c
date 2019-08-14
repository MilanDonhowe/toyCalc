/* file contains function with script for operating the calculator's logic */
#include "calc.h"



void insertDigit(int digit){

    digit -= 48;

    //insert digit to the right most index
    int newValue = ((int) strtol(addends[channel], NULL, 10)) * 10;
    newValue += digit;

    //insert the new numeric value into the array
    /*
    char * output = (char *) malloc(9 * sizeof(char));
    char * fmt = (char *) malloc(9 * sizeof(char));
    */
    
    char * output = (char *) malloc(9 * sizeof(char));
    char * fmt = (char *) malloc(9 * sizeof(char));

    //char fmt[9] = "";
    //char output[9] = "";


    sprintf(fmt, "%d", newValue);


    int inputLength = 8 - strlen(fmt);
    int i;
    for(int i=0; i < inputLength; i++){
        output[i] = '0';
    }
    
    //mvprintw(30, 0, "fmt is %s", fmt);
    //mvprintw(31, 0, "output is %s", output);
    strcat(output, fmt);
    //mvprintw(32, 0, "now output is %s", output);
    addends[channel] = output;
    //mvprintw(33, 0, "addends[channel] is %s", addends[channel]);
    //free(fmt);
    //free(output);
}


void logicCalc(chtype *input){
    
    
    if ((isdigit(*input)) && (addends[channel][0] == '0')){
        insertDigit(*input);
    }

    switch(*input){
        case 'c':
            addends[0] = "00000000";
            addends[1] = "00000000";
            channel = 0;
            break;
        case '+':
            if (channel == 0){
                channel = 1;
                operation = '+';
            }
            break;
        case '-':
            if (channel == 0){
                channel = 1;
                operation = '-';
            }
            break;
        case '/':
            if (channel == 0){
                channel = 1;
                operation = '/';
            }
            break;
        case '*':
            if (channel == 0){
                channel = 1;
                operation = '*';
            }
            break;
        case '=':
            if ((channel == 1) && (operation != '\0')){

                //mvprintw(25, 0, "equal sign function running");

                /*do the calculation */
                int operandOne = ((int) strtol(addends[0], NULL, 10));
                int operandTwo = ((int) strtol(addends[1], NULL, 10));
                int answer;

                //mvprintw(25, 0, "operand 1 is %d", operandOne);
                //mvprintw(26, 0, "operand 2 is %d", operandTwo);


                if (operation == '*') answer = operandOne * operandTwo;
                else if (operation == '/') answer = operandOne / operandTwo;
                else if (operation == '+') answer = operandOne + operandTwo;
                else if (operation == '-') answer = operandOne - operandTwo;

                //mvprintw(27, 0, "The answer is %d", answer);
                // display the change
                channel = 0;
                operation = '\0';

                char stringAnswer[9];//28260
                sprintf(stringAnswer, "%d", answer);
                //mvprintw(18, 0, "the number as a string before padding is %s", stringAnswer);
                //in the event of overflow
                if (strlen(stringAnswer) > 8){
                    addends[channel] = "overflow";
                    break;
                } else {
                    // add zero padding
                    refresh();
                    
                    
                    int i;
                    int distance = 8 - strlen(stringAnswer);
                    free(LTS);
                    LTS = calloc(9, sizeof(char));

                    //mvprintw(14, 0, "distance is at %d", distance);
                    
                    char stringPadding[9];

                    //mvprintw(15, 0, "the stringpadding now is %s", stringPadding);
                    
                    /*
                    Okay I see you laughing, dumb switch/case right?
                    Well I tried to do a for loop; it broke the program due to some weird character insertion
                    bullshit for displaying numbers with more than 4 characters.

                    for(i=0; i < distance; i++){
                        stringPadding[i] = '0';
                    }
                    There's your for loop, comment out my switch/case, use the for loop, then
                    you'll see the genius of my switch case.
                     */
                    switch(distance){
                        case 0:
                            strcpy(stringPadding, "\0");
                            break;
                        case 1:
                            strcpy(stringPadding, "0");
                            break;
                        case 2:
                            strcpy(stringPadding, "00");
                            break;
                        case 3:
                            strcpy(stringPadding, "000");
                            break;
                        case 4:
                            strcpy(stringPadding, "0000");
                            break;
                        case 5:
                            strcpy(stringPadding, "00000");
                            break;
                        case 6:
                            strcpy(stringPadding, "000000");
                            break;
                        case 7:
                            strcpy(stringPadding, "0000000");
                            break;
                        case 8:
                            strcpy(stringPadding, "00000000");
                            break;
                    }

                    
                    addends[1] = "00000000";
                    //mvprintw(19, 0, "the padding for the string: %s", stringPadding);
                    strcat(stringPadding, stringAnswer);

                    for (int j=0; j < strlen(stringPadding); j++){
                        *(LTS + j) = stringPadding[j];
                    }
                    //addends[channel] = stringPadding;
                    addends[channel] = LTS;
                }
                //mvprintw(28, 0, "The stringified version of answer is %s", addends[channel]);


            }
            break;
    }

}