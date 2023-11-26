#include <ncurses.h>
#include <curses.h>
#include <cstdlib>
#include <csignal>

// http://www.manpagez.com/man/3/curs_inopts/
// http://www.manpagez.com/man/3/wgetch/

int main (int argc, char **argv)
{
    (void)argc; (void)argv;
    int y, x;
    int c;
    system("resize -s 30 80");
    WINDOW *win = initscr();              // Initialise la structure WINDOW et autres paramètres 
    timeout(0);
    if (noecho() == -1)
        std::cerr << "error" << std::endl;
    printw("Hello World");  // Écrit Hello World à l'endroit où le curseur logique est positionné
    getyx(win, y, x);
    printw("y = %d, x = %d",y, x);  // Écrit Hello World à l'endroit où le curseur logique est positionné
    refresh();              // Rafraîchit la fenêtre courante afin de voir le message apparaître
    do
    {
        mvprintw(0,100, "T");
        refresh();              // Rafraîchit la fenêtre courante afin de voir le message apparaître
        mvprintw(0,100, "A");
        refresh();              // Rafraîchit la fenêtre courante afin de voir le message apparaître
        c = getch();                // On attend que l'utilisateur appui sur une touche pour quitter
        if (c == ERR)
            ;// no input
    }while(1);
    endwin();               // Restaure les paramètres par défaut du terminal

    return (0);
}