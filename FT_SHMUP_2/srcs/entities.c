#include "ft_shmup.h"

void    fire_projectile(player_t *player)
{
	for (int i = 0; i < MAX_PROJ; i++) 
	{
		if (!player->proj[i].active)
		{
			player->proj[i].x = player->x + 1;
			player->proj[i].y = player->y;
			player->proj[i].active = true;
			player->proj_fired++;
			break;
		}
	}
}

void    fire_enemy_projectile(ennemy_t *ennemy)
{
	for (int i = 0; i < MAX_PROJ; i++)
	{
		if (!ennemy->proj[i].active)
		{
			ennemy->proj[i].x = ennemy->x - 1;
			ennemy->proj[i].y = ennemy->y;
			ennemy->proj[i].active = true;
			break;
		}
	}
}

void    create_random_ennemy(game_t *game)
{
	for (int i = 0; i < MAX_ENNEMY; i++)
	{
		if (!game->ennemies[i].exist)
		{
			game->ennemies[i].exist = true;
			game->ennemies[i].x = COLS - 2;
			game->ennemies[i].y = 1 + rand() % (game->top_height - 2);
			break;
		}
	}
}

bool is_there_ennemy(game_t *game, ennemy_t ennemy, bool top)
{
	for (int i = 0; i < MAX_ENNEMY; i++)
	{
		if (game->ennemies[i].exist)
		{
			if (top)
			{
				if (ennemy.y - 1 == game->ennemies[i].y)
					return true;
			}
			else
			{
				if (ennemy.y + 1 == game->ennemies[i].y)
					return true;
			}
		}
	}
	return false;
}

void    update_ennemies(game_t *game)
{
	for (int i = 0; i < MAX_ENNEMY; i++)
	{
		if (game->ennemies[i].exist)
		{
			game->ennemies[i].x--;
			if (game->ennemies[i].x < 1)
			{
				game->ennemies[i].exist = false;
				if (game->player.life > 0) // si un ennemie arrive au bout de la map le perso perd une vie c'est degueulasse de mettre ça ici mais c'est un rush sans norme et je pense que même dans la norme c'est pas interdit d'uptade une variable du player dans une fonction qui update la position de l'ennemi
					game->player.life--;
			}
			if (rand() % 5 == 0)
			{
				if ((game->top_height - (int)game->ennemies[i].y >= game->top_height - (int)game->player.y) && !is_there_ennemy(game, game->ennemies[i], false))
					game->ennemies[i].y += ((int)game->ennemies[i].y + 1 < game->top_height - 1);
				else if (!is_there_ennemy(game, game->ennemies[i], true))
					game->ennemies[i].y -= (game->ennemies[i].y - 1 > 1);
			}
		}
	}
}
