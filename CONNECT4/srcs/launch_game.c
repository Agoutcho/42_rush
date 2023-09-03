#include "connect4.h"

void launch_ia(t_data *data)
{
    data->stop = 1;
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