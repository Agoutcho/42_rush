#include "connect4.h"

void launch_ia(t_data *data)
{
	while(1)
	{
		if (data->player == PLAYER1)
		{
			ft_putstr_fd("Error: IA failed\n", 2);
			free_exit(data);
		}
		for (size_t column = 0; column < data->cell_width; column++)
		{
			for (int i = data->cell_height - 1; i >= 0; i--)
			{
				if (data->cell_grid[i][column].type == NONE)
				{
					data->cell_grid[i][column].type = data->player;
					if (check_win_ia(data))
					{
						data->player = (data->player + 2) % 2 + 1;
						return ;
					}
					data->cell_grid[i][column].type = NONE;
					break ;
				}
				if (i == 0)
					break ;
			}
		}
		for (size_t column = 0; column < data->cell_width; column++)
		{
			for (int i = data->cell_height - 1; i >= 0; i--)
			{
				if (data->cell_grid[i][column].type == NONE)
				{
					data->cell_grid[i][column].type = PLAYER1;
					if (check_win_ia(data))
					{
						data->cell_grid[i][column].type = data->player;
						data->player = (data->player + 2) % 2 + 1;
						return ;
					}
					data->cell_grid[i][column].type = NONE;
					break ;
				}
				if (i == 0)
					break ;
			}
		}
		int column = rand() % data->cell_width;
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
			{
				column = rand() % data->cell_width;
				i = data->cell_height - 1;
			}
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
			ft_free_gnl(0);
    		free(str);
			return ;
		}
		ft_putstr("\033M\033[2K");
		ft_putstr("\033M\033[2K");
		if (is_input_column_valid(data, str))
			break ;
    	ft_free_gnl(0);
		free(str);
	}
	ft_free_gnl(0);
    free(str);
}