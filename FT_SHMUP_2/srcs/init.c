#include "ft_shmup.h"

void	init_ennemy(game_t *game)
{
	for (int i = 0; i < MAX_ENNEMY; i++) 
	{
		game->ennemies[i].car = '&';
		game->ennemies[i].exist = false;
		game->ennemies[i].x = 0;
		game->ennemies[i].y = 0;
		for (int j = 0; j < MAX_PROJ; j++) 
		{
			game->ennemies[i].proj[j].x = 0;
			game->ennemies[i].proj[j].y = 0;
			game->ennemies[i].proj[j].active = false;
		}
	}
}

void	init_player(game_t *game)
{
	game->player.car = '>';
	game->player.x = 10;
	game->player.y = 5;
	game->player.score = 0;
	game->player.life = 3;
	game->player.proj_fired = 0;
	for (int i = 0; i < MAX_PROJ; i++) 
	{
		game->player.proj[i].x = 0;
		game->player.proj[i].y = 0;
		game->player.proj[i].active = false;
	}
}

void	init_game(game_t *game)
{
	game->running = true;
	game->top_win = NULL;
	game->bottom_win = NULL;
	game->first_fast_particles = NULL;
	game->first_slow_particles = NULL;
	game->frame_time = 0;
	game->frame = 0;
	game->fps = 0;
	game->loop_delta = 0;
	game->seconds = 0;
	game->index_fps = 0;
	game->sum_fps = 0;
	for (int i = 0;i < 10000; i++)
		game->average_fps[i] = 12501;
	game->state = STATE_MENU;
	init_player(game);
	init_ennemy(game);
	create_fast_particles(game);
	create_slow_particles(game);
	game->clock_begin = clock();
	game->clock_begin_frame = clock();
	game->clock_current_frame = clock();
	game->clock_begin_loop = clock();
	game->clock_end_loop = clock();
}

void	init_windows(game_t *game)
{
	getmaxyx(stdscr, game->total_height, game->total_width);
	game->top_height = game->total_height * 0.85;
	game->bottom_height = game->total_height - game->top_height;

	game->top_win = subwin(stdscr, game->top_height, game->total_width, 0, 0);
	game->bottom_win = subwin(stdscr, game->bottom_height, game->total_width, game->top_height, 0);
}

void	init(game_t *game)
{
	srand(time(NULL));
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	nodelay(stdscr, TRUE);
	start_color();
	init_pair(PLAYER_COLOR, COLOR_GREEN, COLOR_WHITE);
	init_pair(ENNEMY_COLOR, COLOR_RED, COLOR_WHITE);
	init_pair(BACKGROUND_COLOR, COLOR_BLUE, COLOR_BLACK);
	init_game(game);
	init_windows(game);
}
