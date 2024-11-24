#include "ft_shmup.h"

void handle_menu(game_t *game)
{
	int	total_height, total_width;
	getmaxyx(stdscr, total_height, total_width);
	
	int	mid_height = total_height / 2;
	int	mid_width = total_width / 2;

	const char	*game_name = "LA GUERRE DES ETOILES";
	const char	*menu = "MENU";
	const char	*option_start = "1 - Start Game";
	const char	*option_exit = "2 - Exit";
	const char	*credits = "Made by @atchougo - @gueberso";

    werase(stdscr);
    mvprintw(mid_height - 4, mid_width - strlen(game_name) / 2, "%s", game_name);
    mvprintw(mid_height - 1, mid_width - strlen(menu) / 2, "%s", menu);
    mvprintw(mid_height + 2, mid_width - strlen(option_start) / 2, "%s", option_start);
	mvprintw(mid_height + 5, mid_width - strlen(option_exit) / 2, "%s", option_exit);
 	mvprintw(total_height - 1, mid_width - strlen(credits) / 2, "%s", credits);
    refresh();

    int ch = getch();
    switch (ch)
	{
        case '1':
			init_player(game);
			init_ennemy(game);
            game->state = STATE_PLAYING;
			//game->running = true;
            break;
        case '2':
            game->running = false;
			game->state = 0;
            break;
        default:
            break;
    }
}

void handle_paused(game_t *game)
{
	int	total_height, total_width;
	getmaxyx(stdscr, total_height, total_width);
	
	int	mid_height = total_height / 2;
	int	mid_width = total_width / 2;

	const char	*pause = "PAUSED";
	const char	*options = "Press 'r' to resume or 'esc' to quit";
	const char	*credits = "Made by @atchougo - @gueberso";

    werase(stdscr);
    mvprintw(mid_height - 4, mid_width - strlen(pause) / 2, "%s", pause);
    mvprintw(mid_height - 1, mid_width - strlen(options) / 2, "%s", options);
	mvprintw(total_height - 1, mid_width - strlen(credits) / 2, "%s", credits);
    refresh();

    int ch = getch();
    switch (ch) {
        case 'r':
            game->state = STATE_PLAYING;
            break;
        case 27:
            game->running = false;
			game->state = 0;
            break;
        default:
            break;
    }
}

void handle_game_over(game_t *game)
{
	int	total_height, total_width;
	getmaxyx(stdscr, total_height, total_width);
	
	int	mid_height = total_height / 2;
	int	mid_width = total_width / 2;

	const char	*game_over = "GAME OVER";
	const char	*score = "Score: ";
	const char	*options = "press 'm' to return to menu or 'esc' to quit";
	const char	*credits = "Made by @atchougo - @gueberso";

    werase(stdscr);
    mvprintw(mid_height - 4, mid_width - strlen(game_over) / 2, "%s", game_over);
    mvprintw(mid_height - 1, mid_width - strlen(score) / 2, "%s%lu", score, game->player.score);
    mvprintw(mid_height + 2, mid_width - strlen(options) / 2, "%s", options);
	mvprintw(total_height - 1, mid_width - strlen(credits) / 2, "%s", credits);
    refresh();

    int ch = getch();
    switch (ch) {
        case 'm':
            game->state = STATE_MENU;
            break;
        case 27:
            game->running = false;
			game->state = 0;
            break;
        default:
            break;
    }
}

void handle_playing(game_t *game)
{
	game->clock_begin_frame = clock();
    int ch = getch();
	switch (ch)
	{
		case 27:
			game->state = STATE_PAUSED;
			break;
		case KEY_DOWN:
			if ((int)game->player.y < game->top_height - 2)
				game->player.y++;
			break;
		case KEY_UP:
			if ((int)game->player.y > 1)
				game->player.y--;
			break;
		case KEY_LEFT:
			if ((int)game->player.x > 1)
				game->player.x--;
			break;
		case KEY_RIGHT:
			if ((int)game->player.x < game->total_width - 2)
				game->player.x++;
			break;
		case KEY_SPACE:
			fire_projectile(&game->player);
			break;
		default:
			break;
	}
	if (game->frame % (rand() % 8000 + 1000) == 0)
	{
		create_fast_particles(game);
	}
	if (game->frame % (rand() % 2000 + 10000) == 0)
	{
		create_slow_particles(game);
	}
	if (game->frame % 750 == 0)
	{
		update_fast_particles(game);
	}
	if (game->frame % 1500 == 0)
	{
		update_slow_particles(game);
	}
	if (game->frame % 20000 == 0)
	{
		create_random_ennemy(game);
	}
	if (game->frame % 1000 == 0) 
	{
		update_ennemies(game);
	}
	if (game->frame % 3000 == 0)
	{
		for (int i = 0; i < MAX_ENNEMY; i++) {
			if (game->ennemies[i].exist && rand() % 4 == 0)
			{
				fire_enemy_projectile(&game->ennemies[i]);
			}
		}
	}
	if (game->frame % 200 == 0) 
	{
		render_enemy_projectiles(game);
	}
	check_collision(game);
	handle_top_window(game->top_win, game);
	handle_bottom_window(game->bottom_win, game);

	game->clock_current_frame = clock();
	if (game->frame % 10000 == 0)
	{
		for (int i = 0; i < 9999; i++)
			game->sum_fps += game->average_fps[i];
		game->fps = game->sum_fps / 9999;
		game->sum_fps = 0;
	}
	game->average_fps[game->frame % 9999] = CLOCKS_PER_SEC / (game->clock_current_frame - game->clock_begin_frame);
	game->frame++;
}
