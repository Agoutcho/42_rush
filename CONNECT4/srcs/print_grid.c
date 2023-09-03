#include "connect4.h"

static void print_first_line(t_data *data)
{
	ft_putstr(RED_P);
	ft_putstr("PLAYER 1");
	ft_putstr(RESET_P);
	ft_putstr(" vs ");
	ft_putstr(YELLOW_P);
	if (data->active_ia)
		ft_putstr("IA");
	else
        ft_putstr("PLAYER 2");
	ft_putstr(RESET_P);
	ft_putstr("\n");
}

static void print_cell(t_cell cell)
{
	if (cell.type == PLAYER1)
	{
		ft_putstr(REDBG);
		ft_putstr("_");
		ft_putstr(RESET_P);
	}
	else if (cell.type == PLAYER2)
	{
		ft_putstr(YELLOWBG);
		ft_putstr("_");
		ft_putstr(RESET_P);
	}
	else
		ft_putstr("_");
}

void print_grid(t_data *data)
{
    print_first_line(data);
	for (size_t i = 0; i < data->cell_height; i++)
	{
		ft_putstr("|");
		for (size_t j = 0; j < data->cell_width; j++)
		{
			print_cell(data->cell_grid[i][j]);
			ft_putstr("|");
		}
		ft_putstr("\n");
	}
}
