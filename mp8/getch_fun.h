#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

/* Initialize new terminal i/o settings */
void initTermios(int echo);

/* Restore old terminal i/o settings */
void resetTermios(void);

/* Read 1 character - echo defines echo mode */
char getch_(int echo);

/* Read 1 character without echo */
char getch(void);

/* Read 1 character with echo */
char getche(void);