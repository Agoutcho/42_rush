#include "connect4.h"

static int is_a_number(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		for (size_t j = 0; j < ft_strlen(argv[i]); j++)
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
		}
	}
	return (1);
}

void parse_grid_size(t_data *data, int argc, char **argv)
{
	if (argc == 1)
	{
		data->cell_height = 6;
		data->cell_width = 7;
	}
	else
	{
		if (!is_a_number(argc, argv))
		{
			ft_putstr_fd("Error: Not a number.\n", 2);
			exit (1);
		}
		data->cell_height = ft_atoi(argv[1]);
		data->cell_width = ft_atoi(argv[2]);
	}
	if (data->cell_height < MINGRIDHEIGHT || data->cell_height > MAXGRIDHEIGHT)
	{
		ft_putstr_fd("Error: Height has to be between 6 and 50", 2);
		exit (1);
	}
	if (data->cell_width < MINGRIDWIDTH || data->cell_width > MAXGRIDWIDTH)
	{
		ft_putstr_fd("Error: Width has to be between 7 and 50", 2);
		exit (1);
	}
	data->cell_grid = (t_cell **) ft_calloc(data->cell_height, sizeof(*data->cell_grid));
	for (size_t i = 0; i < data->cell_height; i++)
		data->cell_grid[i] = (t_cell *) ft_calloc(data->cell_width, sizeof(**data->cell_grid));
}