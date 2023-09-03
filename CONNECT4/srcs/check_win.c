#include "connect4.h"

static int check_width_win(t_data *data)
{
    int val = 0;
    t_cell_type test;

    for (size_t i = 0; i < data->cell_height; i++)
    {
        val = 0;
        for(size_t j = 0; j < data->cell_width; j++)
        {
            test = data->cell_grid[i][j].type;
            if (test == NONE)
            {
                val = 0;
                continue ;
            }
            if (val == 3)
                return (1);
            if (j + 1 < data->cell_width)
            {
                if (test == data->cell_grid[i][j + 1].type)
                    val++;
                else
                    val = 0;
            }
        }
    }
    return (0);
}

static int check_height_win(t_data *data)
{
    int val = 0;
    t_cell_type test;

    for (size_t i = 0; i < data->cell_width; i++)
    {
        val = 0;
        for(size_t j = 0; j < data->cell_height; j++)
        {
            test = data->cell_grid[j][i].type;
            if (test == NONE)
            {
                val = 0;
                continue ;
            }
            if (val == 3)
                return (1);
            if (j + 1 < data->cell_height)
            {
                if (test == data->cell_grid[j + 1][i].type)
                    val++;
                else
                    val = 0;
            }
        }
    }
    return (0);
}

static int check_diag_win(t_data *data)
{
    t_cell_type test;

    for (size_t i = 0; i < data->cell_width; i++)
    {
        for(size_t j = 0; j < data->cell_height; j++)
        {
            test = data->cell_grid[j][i].type;
            if (test == NONE)
                continue ;
            if (j + 3 < data->cell_height && i + 3 < data->cell_width)
            {
                if (test == data->cell_grid[j + 1][i + 1].type && 
                    test == data->cell_grid[j + 2][i + 2].type && 
                    test == data->cell_grid[j + 3][i + 3].type)
                        return (1);
            }
        }
    }
    return (0);
}

static int check_reverse_diag_win(t_data *data)
{
    int val = 0;
    t_cell_type test;

    for (long i = 0; i < (long)data->cell_width; i++)
    {
        val = 0;
        for(long j = 0; j < (long)data->cell_height; j++)
        {
            test = data->cell_grid[j][i].type;
            if (test == NONE)
                continue ;
            if (j - 3 >= 0 && i + 3 < (long)data->cell_width)
            {
                if (test == data->cell_grid[j - 1][i + 1].type && 
                    test == data->cell_grid[j - 2][i + 2].type && 
                    test == data->cell_grid[j - 3][i + 3].type)
                        return (1);
            }
        }
    }
    return (0);
}

static int check_draw(t_data *data)
{
    for (size_t i = 0; i < data->cell_height; i++)
    {
        for(size_t j = 0; j < data->cell_width; j++)
        {
            if (data->cell_grid[i][j].type == NONE)
                return (0);
        }
    }
    return (1);
}

int check_win(t_data *data)
{
    if (check_draw(data))
    {
        ft_printf("Draw\n");
        return (!data->stop);
    }
    if (check_width_win(data))
    {
        data->player = (data->player + 2) % 2 + 1;
        ft_printf("Player %d won.\n", data->player);
        return (!data->stop);
    }
    if (check_height_win(data))
    {
        data->player = (data->player + 2) % 2 + 1;
        ft_printf("Player %d won.\n", data->player);
        return (!data->stop);
    }
    if (check_diag_win(data) || check_reverse_diag_win(data))
    {
        data->player = (data->player + 2) % 2 + 1;
        ft_printf("Player %d won.\n", data->player);
        return (!data->stop);
    }
    return (data->stop);
}