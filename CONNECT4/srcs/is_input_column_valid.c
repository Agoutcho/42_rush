#include "connect4.h"

static int is_a_number(char *argv)
{
	for (size_t j = 0; j < ft_strlen(argv) - 1; j++)
	{
		if (!ft_isdigit(argv[j]))
			return (0);
	}
	return (1);
}

int is_input_column_valid(t_data *data, char *str)
{
    size_t column;

    if (!is_a_number(str))
    {
		ft_putstr("Not a number.\n");
        return (0);
    }
    column = ft_atoi(str);
    if (column > data->cell_width || column < 1)
    {
        ft_putstr("Out of the box.\n");
        return (0);
    }
    column--;
    for (int i = data->cell_height - 1; i >= 0; i--)
    {
		int test = data->cell_grid[i][column].type;
		if (data->cell_grid[i][column].type == NONE)
		{
			data->cell_grid[i][column].type = data->player;
			data->player = (data->player + 2) % 2 + 1;
			break ;
		}
		if (i == 0 && (test - data->cell_grid[i][column].type) == 0)
		{
			ft_putstr("Column is full\n");
            return (0);
		}
    }
    return (1);
}