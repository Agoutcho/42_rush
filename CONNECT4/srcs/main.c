#include "connect4.h"

int main(int argc, char **argv)
{
	t_data data;

	if (argc != 1 && argc != 3)
		return (ft_putstr_fd("Usage: ./connect4 <height> <width>.\n", 2), 1);
	init_data(&data);
	parse_grid_size(&data, argc, argv);
	data.active_ia = is_bot_active();
	data.player = rand() % 2 + 1;
	print_grid(&data, 0);
	while (!data.stop)
	{
		if (check_win(&data))
			break ;
		if (data.active_ia && data.player == PLAYER2)
			launch_ia(&data);
		else
			launch_player(&data);
		print_grid(&data, 1);
	}
	free_exit(&data);
}