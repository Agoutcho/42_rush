#include "ft_shmup.h"

int	main ()
{
	game_t	game;
	int 	current_height = 0, current_width = 0;
	
	init(&game);
	if (LINES <= 40 || COLS <= 120) {
			endwin();
			printf("Window size too small.\n");
			game.running = false;
	}
	while(game.running)
	{
		switch (game.state)
		{
			case STATE_MENU:
				handle_menu(&game);
				break;
			case STATE_PLAYING:
				handle_playing(&game);
				break;
			case STATE_PAUSED:
				handle_paused(&game);
				break;
			case STATE_GAME_OVER:
				handle_game_over(&game);
				break;
			default:
				game.running = false;
				break;
		}
		getmaxyx(stdscr, current_height, current_width);
		if (game.total_height != current_height || game.total_width != current_width) {
			endwin();
			printf("DON'T CHANGE WINDOW SIZE !\n");
			game.running = false;
			break;
		}
	}
	delwin(game.top_win);
	delwin(game.bottom_win);
	endwin();
	exit(0);
}
