#ifndef CONNECT4_H
#define CONNECT4_H

#include <stdio.h>
#include <stdlib.h>

#include <time.h>
//    time_t time(time_t *tloc);

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
	size_t		cell_weight;
	t_cell_type	player;
}t_data;


#endif /* CONNECT4_H */
