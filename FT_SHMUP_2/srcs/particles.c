#include "ft_shmup.h"

void create_slow_particles(game_t *game)
{
	particles_t *temp, *first;

	if (game->first_slow_particles == NULL)
	{
		game->first_slow_particles = (particles_t*) malloc(sizeof(particles_t));
		if (game->first_slow_particles == NULL)
			exit_win(game);
		temp = game->first_slow_particles;
	}
	else
	{
		for(first = game->first_slow_particles; first->next != NULL; first = first->next);
		first->next = (particles_t*) malloc(sizeof(particles_t));
		if (first->next == NULL)
			exit_win(game);
		temp = first->next;
	}
	temp->next = NULL;
	temp->car = '~';
	temp->x = COLS - 2;
	temp->y = 1 + rand() % (game->top_height - 2);
}

void create_fast_particles(game_t *game)
{
	particles_t *temp, *first;

	if (game->first_fast_particles == NULL)
	{
		game->first_fast_particles = (particles_t*) malloc(sizeof(particles_t));
		if (game->first_fast_particles == NULL)
			exit_win(game);
		temp = game->first_fast_particles;
	}
	else
	{
		for(first = game->first_fast_particles; first->next != NULL; first = first->next);
		first->next = (particles_t*) malloc(sizeof(particles_t));
		if (first->next == NULL)
			exit_win(game);
		temp = first->next;
	}
	temp->next = NULL;
	temp->car = '.';
	temp->x = COLS - 2;
	temp->y = 1 + rand() % (game->top_height - 2);
}

void update_fast_particles(game_t *game)
{
	particles_t *first;

	for(first = game->first_fast_particles; first != NULL; first = first->next)
	{
		if (first != NULL && 1 >= first->x)
		{
			if (first == game->first_fast_particles)
			{
				first = game->first_fast_particles->next;
				free (game->first_fast_particles);
			}
			game->first_fast_particles = first;
		}
		if (first != NULL)
			first->x--;
		else
			create_fast_particles(game);
	}
}

void update_slow_particles(game_t *game)
{
	particles_t *first;

	for(first = game->first_slow_particles; first != NULL; first = first->next)
	{
		if (first != NULL && 1 >= first->x)
		{
			if (first == game->first_slow_particles)
			{
				first = game->first_slow_particles->next;
				free (game->first_slow_particles);
			}
			game->first_slow_particles = first;
		}
		if (first != NULL)
			first->x--;
		else
			create_slow_particles(game);
	}
}

