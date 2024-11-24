#include "ft_shmup.h"

void	display_timer(WINDOW *win, int row, int col, clock_t timer)
{
	int time_passed = (clock() - timer) / CLOCKS_PER_SEC;
	mvwprintw(win, row, col, "Time: %ds", time_passed);
}

void	display_lives(WINDOW *win, int row, int col, int lives)
{
	if (lives > 1)
		mvwprintw(win, row, col, "Lives: %d", lives);
	else
		mvwprintw(win, row, col, "Life: %d", lives);
}

void	display_score(WINDOW *win, int row, int col, int score)
{
	mvwprintw(win, row, col, "Score: %d", score);
}

void	display_proj(WINDOW *win, int row, int col, int Proj)
{
	mvwprintw(win, row, col, "Tir: %d", Proj);
}

void	display_fps(WINDOW *win, int row, int col, int fps)
{
	mvwprintw(win, row, col, "fps: %d", fps);
}

void	draw_frame(WINDOW *win)
{
	box(win, 0, 0);
}
