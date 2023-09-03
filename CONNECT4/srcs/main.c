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
	while (!data.stop)
	{
		print_grid(&data);
		if (data.active_ia)
			launch_ia(&data);
		else
			launch_player(&data);
	}
	free_exit(&data);
}