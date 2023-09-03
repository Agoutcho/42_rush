#include "connect4.h"

void init_data(t_data *data)
{
    srand(time(NULL));
    ft_bzero(data, sizeof(*data));
}