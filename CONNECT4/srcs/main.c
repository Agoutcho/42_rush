#include "connect4.h"

int main(int argc, char **argv)
{
	t_data data;
	int value;

	if (argc != 1 && argc != 3)
		return (ft_putstr_fd("Usage: ./connect4 <height> <width>.\n", 2), 1);
	init_data(&data);
	parse_grid_size(&data, argc, argv);
	data.active_ia = is_bot_active();
	data.player = rand() % 2 + 1;
	value = data.cell_height - 1;
	while (value >= 0)
	{
		char *str;
		DEBUG("player %d", data.player)
		print_grid(&data);
		ft_putstr("Entrer une colonne : ");
		str = ft_gnl(0);
		DEBUG("str : %s", str);
		data.cell_grid[value][ft_atoi(str)].type = data.player;
		data.player = (data.player + 2) % 2 + 1;
		value--;
		ft_free_gnl(0);
		free(str);
	}
	free_exit(&data);
}