#include "cub3d.h"



void					init_screen(t_game *game)
{
	game->screen->res_v = RES_V;
	game->screen->res_h = RES_H;
	game->screen->fov_v = FOV_V;
	game->screen->fov_h = FOV_H;

	if (!(game->screen->mlx = mlx_init()))
		lib_do_exit("mlx_init fail");
	if (!(game->screen->win = mlx_new_window(game->screen->mlx, game->screen->res_h, game->screen->res_v, "test_window")))
		lib_do_exit("mlx_new_window fail");
	if (!(game->screen->img = mlx_new_image(game->screen->mlx, game->screen->res_h, game->screen->res_v)))
		lib_do_exit("mlx_new_image fail");
}