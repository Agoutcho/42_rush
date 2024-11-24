#include "ft_shmup.h"

void handle_top_window(WINDOW *win, game_t *game) 
{
	werase(win);
	draw_frame(win);

	render_background(win, game);
	wattron(win, COLOR_PAIR(PLAYER_COLOR));
	mvwaddch(win, game->player.y, game->player.x, game->player.car);
	render_projectils(win, &game->player, game->frame);
	wattroff(win, COLOR_PAIR(PLAYER_COLOR));
	wattron(win, COLOR_PAIR(ENNEMY_COLOR));
    for (int i = 0; i < MAX_ENNEMY; i++)
	{
        if (game->ennemies[i].exist) {
            mvwaddch(win, game->ennemies[i].y, game->ennemies[i].x, game->ennemies[i].car);
        }
    }
	for (int i = 0; i < MAX_ENNEMY; i++)
	{
		if (game->ennemies[i].exist)
		{
			for (int j = 0; j < MAX_PROJ; j++)
			{
				if (game->ennemies[i].proj[j].active) 
					mvwaddch(win, game->ennemies[i].proj[j].y, game->ennemies[i].proj[j].x, '*');
			}
		}
	}
    wattroff(win, COLOR_PAIR(ENNEMY_COLOR));
	wrefresh(win);
}

void handle_bottom_window(WINDOW *win, game_t *game) 
{
	int width, height;
	getmaxyx(win, height, width);

	werase(win);
	draw_frame(win);

	int first_row = height / 2;
	int second_row = first_row + 1;
	int col_time = (width - 10) / 2;
	int col_score = (width - 10) / 4;
	int col_proj_fired = col_score;
	int col_lives = ((width - 10) * 3) / 4;
	int col_fps = col_time;

	display_timer(win, first_row, col_time, game->clock_begin);
	display_lives(win, first_row, col_lives, game->player.life);
	display_score(win, first_row, col_score, game->player.score);
	display_proj(win, second_row, col_proj_fired, game->player.proj_fired);
	display_fps(win, second_row, col_fps, game->fps);

	wrefresh(win);
}

void exit_win(game_t *game)
{
	delwin(game->top_win);
	delwin(game->bottom_win);
	endwin();
	exit(-1);
}
