#ifndef __CUBD_H__
# define __CUBD_H__

# define FOV_V 60
# define FOV_H 90
# define RES_V 400
# define RES_H 600

# define TRANSLATION_SPEED 0.1
# define ROTATION_SPEED 3

#define PI 3.14159265359
#define PI14 0.785398
#define PI12 1.570796
#define PI32 4.712389

#define START_POS_X 1.5
#define START_POS_Y 1.5
#define START_HDG 0

#define MAP_PATH "debug_map"

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <unistd.h>

# include "mlx_int.h"
# include "mlx.h"


struct						s_game;
typedef struct s_game		t_game;

struct						s_map;
typedef struct s_map		t_map;

struct						s_grid;
typedef struct s_grid		t_grid;

struct						s_screen;
typedef struct s_screen		t_screen;

struct						s_actor;
typedef struct s_actor		t_actor;

struct						s_player;
typedef struct s_player		t_player;

struct						s_block;
typedef struct s_block		t_block;

struct						s_game
{
	t_screen *screen;
	t_player *player;
	t_map *map;
	void (*solve[9])(t_game *game);

};

struct						s_screen
{
	void *mlx;
	void *win;
	t_img *img;
	int **bitmap_xy;
	int res_h;
	int res_v;
	int size;
	double fov_v;
	double fov_h;
};

struct						s_player
{
	t_actor *actor;
	double translation_speed;
	double rotation_speed;
};


struct						s_actor
{
	double pos_x;
	double pos_y;
	double hdg;
};



struct						s_block
{
	char type;
};

// game->player->actor

struct						s_map
{
	char *text;
	char *path;
	t_grid *grid;
	float *angles;
	int r_limit;
};

struct						s_grid
{
	t_block ***blocks;
	t_block **list;
	int size;
	int size_x;
	int size_y;
};

void debug_read_map_get_size(t_game *game);
int debug_read_map(t_game *game);
void debug_read_map_to_grid(t_game *game);
void debug_solve(t_game *game);
void debug_print_map(t_game *game);

void					init_main(t_game *game);
void					init_player(t_game *game);
void					init_screen(t_game *game);
void					init_angles(t_game *game);
void					init_functions(t_game *game);

void					lib_do_exit(char *str);
int						lib_get_file_len(char *path);
char					*lib_get_file(char *path);

int						src_mlx_key_hook(int key, t_game *game);
int						src_mlx_loop_hook(t_game *game);

void					actor_translate_up(t_actor *actor, double dst);
void					actor_translate_right(t_actor *actor, double dst);
void					actor_translate_left(t_actor *actor, double dst);
void					actor_translate_down(t_actor *actor, double dst);

void					actor_rotate_right(t_actor *actor, double angle);
void					actor_rotate_left(t_actor *actor, double angle);

void					solve_x(float tgt_y, float sign, t_game *game);
void					solve_y(float tgt_x, float sign, t_game *game);


void					solve_en(t_game *game);
void					solve_es(t_game *game);
void					solve_ne(t_game *game);
void					solve_nw(t_game *game);
void					solve_se(t_game *game);
void					solve_sw(t_game *game);
void					solve_wn(t_game *game);
void					solve_ws(t_game *game);

#endif