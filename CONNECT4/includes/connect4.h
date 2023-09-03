#ifndef CONNECT4_H
#define CONNECT4_H

#include <stdio.h>
#include <stdlib.h>

#include <time.h>
//    time_t time(time_t *tloc);

#include "debug.h"
#include "../libft/include/libft.h"

#define REDBG "\033[0;41m"
#define YELLOWBG "\033[0;43m"

#define MAXGRIDHEIGHT 50
#define MINGRIDHEIGHT 6
#define MAXGRIDWIDTH 50
#define MINGRIDWIDTH 7

typedef enum e_cell_type
{
	NONE,
	PLAYER1,
	PLAYER2
}t_cell_type;

typedef struct s_cell
{
	t_cell_type type;
	size_t		cell_height;
}t_cell;

typedef struct s_data
{
	t_cell		**cell_grid;
	size_t		cell_height;
	size_t		cell_width;
	t_cell_type	player;
	int			active_ia;
	int			stop;
}t_data;

void		free_exit(t_data *data);
void		init_data(t_data *data);
int			is_bot_active();
int			is_input_column_valid(t_data *data, char *str);
void		launch_ia(t_data *data);
void		launch_player(t_data *data);
void		parse_grid_size(t_data *data, int argc, char **argv);
void		print_grid(t_data *data);

#endif /* CONNECT4_H */
