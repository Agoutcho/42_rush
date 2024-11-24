#include "ft_shmup.h"

void	check_death(game_t *game)
{
	if (game->player.life <= 0)
	{
		//game->running = false;
		game->state = STATE_GAME_OVER;
	}
}

void	check_ennemy_hit(game_t *game)
{
	for(int j = 0; j < MAX_ENNEMY; j++)
	{
		for(int i = 0; i < MAX_PROJ; i++)
		{
			if (game->ennemies[j].proj[i].active &&\
				game->ennemies[j].proj[i].x == game->player.x &&\
				game->ennemies[j].proj[i].y == game->player.y)
			{
				if (game->player.life > 0)
					game->player.life--;
				game->ennemies[j].proj[i].active = false;
			}
		}
	}

	for(int j = 0; j < MAX_ENNEMY; j++)
	{
		if (game->ennemies[j].exist &&\
			game->ennemies[j].x == game->player.x &&\
			game->ennemies[j].y == game->player.y)
		{
			if (game->player.life > 0)
				game->player.life--;
			game->ennemies[j].exist = false;
		}
	}
}


void	check_score(game_t *game)
{
	for(int j = 0; j < MAX_ENNEMY; j++)
	{
		if (game->ennemies[j].exist)
		{
			for(int i = 0; i < MAX_PROJ; i++)
			{
				if (game->player.proj[i].active && \
					game->player.proj[i].x == game->ennemies[j].x &&\
					game->player.proj[i].y == game->ennemies[j].y)
				{
					game->player.score++;
					game->ennemies[j].exist = false;
					for(int i = 0; i < MAX_PROJ; i++)
						game->ennemies[j].proj[i].active = false;
					game->player.proj[i].active = false;
				}
			}
		}
	}
}

void check_projectils(game_t *game)
{
	for(int j = 0; j < MAX_ENNEMY; j++)
	{
		if (game->ennemies[j].exist)
		{
			for(int i = 0; i < MAX_PROJ; i++)
			{
				if (game->ennemies[j].proj[i].active == false)
					continue;
				for(int k = 0; k < MAX_PROJ; k++)
				{
					if (game->ennemies[j].proj[i].active && game->player.proj[k].active &&\
						game->ennemies[j].proj[i].x == game->player.proj[k].x &&\
						game->ennemies[j].proj[i].y == game->player.proj[k].y)
					{
						game->player.proj[k].active = false;
						game->ennemies[j].proj[i].active = false;
					}
				}
			}
		}
	}
}

void	check_collision(game_t *game)
{
	check_projectils(game);
	check_ennemy_hit(game);
	check_score(game);
	check_death(game);
}
