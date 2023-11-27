#include "ft_shmup.h"

void resetTerminal()
{
    system("stty -raw");
    system("stty echo");
    system("stty onlcr");
}

int kbhit(void)
{
    int ch = getch();

    if (ch != ERR) {
        ungetch(ch);
        return 1;
    } else {
        return 0;
    }
}