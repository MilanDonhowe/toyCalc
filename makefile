CC=gcc
calc: calc.c draw.c logic.c
	$(CC) calc.c draw.c logic.c -lncurses -o calc