#ifndef FT_SHMUP_H
#define FT_SHMUP_H

#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define FPS 30
#define FRAME_SPEED_IN_MS 5
#define KEY_SPACE 32
#define MAX_ENNEMY 30
#define MAX_PROJ 150
#define X_WIN 200
#define Y_WIN 60

enum colors_e
{
	PLAYER_COLOR = 1,
	ENNEMY_COLOR,
	BACKGROUND_COLOR
};

typedef enum state_e 
{
	STATE_GAME_OVER,
	STATE_MENU,
	STATE_PAUSED,
	STATE_PLAYING
}	game_state_t;

typedef struct particles_s
{
	char            	car;
	unsigned int    	x;
	unsigned int    	y;
	struct particles_s *next;
}	particles_t;

typedef struct projectile_s 
{
	unsigned int x;
	unsigned int y;
	bool active;
}   projectile_t;

typedef struct ennemy_projectiles_s
{
	int x;
	int y;
	bool active;
}   enemy_proj_t;

typedef struct ennemy_s
{
	char            car;
	bool            exist;
	unsigned int    x;
	unsigned int    y;
	projectile_t    proj[MAX_PROJ];
}   ennemy_t;

typedef struct player_s
{
	char            car;
	unsigned int    x;
	unsigned int    y;
	unsigned long   score;
	unsigned long   life;
	projectile_t 	proj[MAX_PROJ];
	unsigned long   proj_fired;
}	player_t;

typedef struct game_s
{
	bool            running;
	clock_t         clock_begin_frame;
	clock_t         clock_begin_loop;
	clock_t         clock_begin;
	clock_t         clock_current_frame;
	clock_t         clock_end_loop;
	ennemy_t        ennemies[MAX_ENNEMY];
	game_state_t	state;
	int				bottom_height;
	int				top_height;
	int				total_height;
	int				total_width;
	particles_t		*first_fast_particles;
	particles_t		*first_slow_particles;
	player_t		player;
	unsigned long	fps;
	unsigned long	frame_time;
	unsigned long	frame;
	unsigned long   loop_delta;
    unsigned long   seconds;
    WINDOW          *top_win;
	WINDOW          *bottom_win;
	uint64_t 		average_fps[10000];
	uint64_t		index_fps;
	uint64_t		sum_fps;
}	game_t;

void    init_game(game_t *game);
void    init_player(game_t *game);
void    init_windows(game_t *game);
void 	init_ennemy(game_t *game);
void    init(game_t *game);

void	exit_win(game_t *game);

void    handle_bottom_window(WINDOW *win, game_t *game);
void    handle_top_window(WINDOW *win, game_t *game);

void	render_background(WINDOW *win, game_t *game);
void	render_enemy_projectiles(game_t *game);
void	render_projectils(WINDOW *win, player_t *player, int frame);

void	check_collision(game_t *game);
void    display_fps(WINDOW *win, int row, int col, int fps);
void    display_lives(WINDOW *win, int row, int col, int lives);
void    display_proj(WINDOW *win, int row, int col, int Proj);
void    display_score(WINDOW *win, int row, int col, int score);
void    display_timer(WINDOW *win, int row, int col, clock_t timer);
void    draw_frame(WINDOW *win);

void    create_random_ennemy(game_t *game);
void    fire_enemy_projectile(ennemy_t *ennemy);
void    fire_projectile(player_t *player);
void    update_ennemies(game_t *game);


void	create_fast_particles(game_t *game);
void	update_slow_particles(game_t *game);
void    create_slow_particles(game_t *game);
void    update_fast_particles(game_t *game);

void	handle_game_over(game_t *game);
void	handle_menu(game_t *game);
void	handle_paused(game_t *game);
void	handle_playing(game_t *game);

#endif /* FT_SHMUP_H */
