#include "ft_shmup.h"

void resetTerminal()
{
    system("stty -raw");
    system("stty echo");
    system("stty onlcr");
}