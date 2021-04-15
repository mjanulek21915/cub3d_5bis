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

#define START_POS_X 2.5
#define START_POS_Y 2.5
#define START_HDG 0

#define MAP_PATH "debug_map"

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
#include "limits.h"

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

struct						s_job;
typedef struct s_job		t_job;

struct						s_texture;
typedef struct s_texture	t_texture;

struct						s_bitmap;
typedef struct s_texture	t_bitmap;

struct						s_entity;
typedef struct s_entity		t_entity;

struct						s_job
{
	char type;
	int direction;
	t_block *tgt;
	double distance;
	double ratio;
};

struct						s_game
{
	int direction_x[4];
	int direction_y[4];
	t_job *job_tgt_x;
	t_job *job_tgt_y;
	t_job jobs_hidden[18];
	t_job *jobs[16];
	int job_x;
	int job_y;
	int job_i;
	double job_hdg;
	int direction;

	t_texture *textures[127];

	t_screen *screen;
	t_player *player;
	t_map *map;
	unsigned int ***bitmap;
	void (*solve_x[9])(t_game *game, double f);
	void (*solve_y[9])(t_game *game, double f);
};


struct						s_texture
{
	unsigned int ***grids[4];
	unsigned int *bitmap_n;
	unsigned int ***grid_n;
	int grid_n_size_x;
	int grid_n_size_y;
	double mult_n_x;
	double mult_n_y;

	unsigned int *bitmap_s;
	unsigned int ***grid_s;
	int grid_s_size_x;
	int grid_s_size_y;
	double mult_s_x;
	double mult_s_y;

	unsigned int *bitmap_e;
	unsigned int ***grid_e;
	int grid_e_size_x;
	int grid_e_size_y;
	double mult_e_x;
	double mult_e_y;

	unsigned int *bitmap_w;
	unsigned int ***grid_w;
	int grid_w_size_x;
	int grid_w_size_y;
	double mult_w_x;
	double mult_w_y;
};

struct						s_screen
{
	void *mlx;
	void *win;
	t_img *img;
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


struct						s_map
{
	char *text;
	char *path;
	t_grid *grid;
	double *angles_h;
	double *angles_v;
	int r_limit;
};

struct						s_grid
{
	t_block ***blocks;
	t_block **list;
	t_block *filler;
	int size;
	int size_x;
	int size_y;
};

void debug_read_map_get_size(t_game *game);
int debug_read_map(t_game *game);
void debug_read_map_to_grid(t_game *game);
void debug_solve(t_game *game);
void debug_print_map(t_game *game);
void debug_draw(t_game *game, int column);
void debug_mk_default_block(t_game *game);


void					init_angles(t_game *game);
void					init_functions(t_game *game);
void					init_main(t_game *game);
void					init_player(t_game *game);
void					init_screen(t_game *game);
void					init_structures(t_game *game);


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

void					solve_x(double tgt_y, double sign, t_game *game, int detection_offset_x, int detection_offset_y);
void					solve_y(double tgt_x, double sign, t_game *game, int detection_offset_x, int detection_offset_y);

void					screen_update(t_game *game);
void					screen_update_clear_buffer(t_game *game);


void					solve_en_x(t_game *game, double f);
void					solve_en_y(t_game *game, double f);
void					solve_es_x(t_game *game, double f);
void					solve_es_y(t_game *game, double f);
void					solve_ne_x(t_game *game, double f);
void					solve_ne_y(t_game *game, double f);
void					solve_nw_x(t_game *game, double f);
void					solve_nw_y(t_game *game, double f);
void					solve_se_x(t_game *game, double f);
void					solve_se_y(t_game *game, double f);
void					solve_sw_x(t_game *game, double f);
void					solve_sw_y(t_game *game, double f);
void					solve_wn_x(t_game *game, double f);
void					solve_wn_y(t_game *game, double f);
void					solve_ws_x(t_game *game, double f);
void					solve_ws_y(t_game *game, double f);


#endif