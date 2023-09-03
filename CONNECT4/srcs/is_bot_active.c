#include "connect4.h"

int is_bot_active()
{
    char *str = NULL;

    ft_putstr("Press 1 to play with a bot or anything else :\n");
    str = ft_gnl(0);
    if (str && ft_strlen(str) == 2 && !ft_strncmp(str, "1", 1))
        return (free(str), ft_free_gnl(0), 1);
    return (free(str), ft_free_gnl(0), 0);
}