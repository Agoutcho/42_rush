#include "ft_shmup.h"

void render_background(WINDOW *win, game_t *game)
{
	particles_t *first;

	for(first = game->first_fast_particles; first != NULL; first = first->next)
	{
		wattron(win, COLOR_PAIR(BACKGROUND_COLOR));
		mvwaddch(win, first->y, first->x, first->car);
		wattroff(win, COLOR_PAIR(BACKGROUND_COLOR));
	}
	for(first = game->first_slow_particles; first != NULL; first = first->next)
	{
		wattron(win, COLOR_PAIR(BACKGROUND_COLOR));
		mvwaddch(win, first->y, first->x, first->car);
		wattroff(win, COLOR_PAIR(BACKGROUND_COLOR));
	}
}

void render_projectils(WINDOW *win, player_t *player, int frame)
{
	for (int i = 0; i < MAX_PROJ; i++)
	{
		if (player->proj[i].active)
		{
			mvwaddch(win, player->proj[i].y, player->proj[i].x, ' ');
			if (frame % 100 == 0)
			{
				player->proj[i].x++;
			}
			if (player->proj[i].x > (uint32_t)COLS - 2) 
				player->proj[i].active = false;
			else 
				mvwaddch(win, player->proj[i].y, player->proj[i].x, '-');
		}
	}
}

void render_enemy_projectiles(game_t *game)
{
	for (int i = 0; i < MAX_ENNEMY; i++)
	{
		if (game->ennemies[i].exist)
		{
			for (int j = 0; j < MAX_PROJ; j++)
			{
				if (game->ennemies[i].proj[j].active)
				{
					game->ennemies[i].proj[j].x--;
					if (game->ennemies[i].proj[j].x < 1)
					{
						game->ennemies[i].proj[j].active = false;
					}
				}
			}
		}
	}
}
