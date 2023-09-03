#include "connect4.h"

void launch_ia(t_data *data)
{
	int column;

	while(1)
	{
		if (data->player == PLAYER1)
		{
			ft_putstr_fd("Error: IA failed\n", 2);
			free_exit(data);
		}
		column = rand() % data->cell_width;
		for (int i = data->cell_height - 1; i >= 0; i--)
		{
			int test = data->cell_grid[i][column].type;
			if (data->cell_grid[i][column].type == NONE)
			{
				data->cell_grid[i][column].type = data->player;
				data->player = (data->player + 2) % 2 + 1;
				return ;
			}
			if (i == 0 && (test - data->cell_grid[i][column].type) == 0)
				ft_putstr("Column is full\n");
		}
	}
}

void launch_player(t_data *data)
{
    char	*str;

	ft_printf("\n");
	while (1)
	{
		if (data->player == PLAYER1)
			ft_printf(RED_P"Player %d"RESET_P" entrer une colonne : ", data->player);
		else
			ft_printf(YELLOW_P"Player %d"RESET_P" entrer une colonne : ", data->player);
		str = ft_gnl(0);
		if (!str)
		{
			data->stop = 1;
			ft_putstr("Exiting game.\n");
			return ;
		}
		ft_putstr("\033M\033[2K");
		ft_putstr("\033M\033[2K");
		if (is_input_column_valid(data, str))
			break ;
	}
    ft_free_gnl(0);
    free(str);
}