#include <ncurses.h>
#include <curses.h>
#include <cstdlib>
#include <csignal>
#include <iostream>

#include "GameBoard.h"

// http://www.manpagez.com/man/3/curs_inopts/
// http://www.manpagez.com/man/3/wgetch/

volatile __sig_atomic_t toStop = 0;

void sighandler(int a)
{
    (void)a;
    toStop = 1;
}

int main (int argc, char **argv)
{
    (void)argc; (void)argv;
    GameBoard gameboard;

    signal(SIGINT, sighandler);
    gameboard.init();
    gameboard.run();
    return (0);
}