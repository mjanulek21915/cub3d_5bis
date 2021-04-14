#include "cub3d.h"

void debug_mk_default_block(t_game *game)
{
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;

	if (!(game->textures['1'] = malloc(sizeof(t_texture))))
		lib_do_exit("debug_mk_default_block : game->textures['1'] malloc fail");

	if (!(game->textures['1']->bitmap_n = malloc(sizeof(long long) * (100) * (100))))
		lib_do_exit("debug_mk_default_block : game->textures['1'] malloc fail");
	if (!(game->textures['1']->grid_n = malloc(sizeof(long long **) * (100))))
		lib_do_exit("debug_mk_default_block : game->textures['1'] malloc fail");
	while (i < 100)
	{
		if (!(game->textures['1']->grid_n[i] = malloc(sizeof(long long *) * (100))))
			lib_do_exit("debug_mk_default_block : game->textures['1'] malloc fail");
		i++;
	}
	i = 0;

	if (!(game->textures['1']->bitmap_s = malloc(sizeof(long long) * (100) * (100))))
		lib_do_exit("debug_mk_default_block : game->textures['1'] malloc fail");
	if (!(game->textures['1']->grid_s = malloc(sizeof(long long **) * (100))))
		lib_do_exit("debug_mk_default_block : game->textures['1'] malloc fail");
	while (i < 100)
	{
		if (!(game->textures['1']->grid_s[i] = malloc(sizeof(long long *) * (100))))
			lib_do_exit("debug_mk_default_block : game->textures['1'] malloc fail");
		i++;
	}
	i = 0;

	if (!(game->textures['1']->bitmap_e = malloc(sizeof(long long) * (100) * (100))))
		lib_do_exit("debug_mk_default_block : game->textures['1'] malloc fail");
	if (!(game->textures['1']->grid_e = malloc(sizeof(long long **) * (100))))
		lib_do_exit("debug_mk_default_block : game->textures['1'] malloc fail");
	while (i < 100)
	{
		if (!(game->textures['1']->grid_e[i] = malloc(sizeof(long long *) * (100))))
			lib_do_exit("debug_mk_default_block : game->textures['1'] malloc fail");
		i++;
	}
	i = 0;

	if (!(game->textures['1']->bitmap_w = malloc(sizeof(long long) * (100) * (100))))
		lib_do_exit("debug_mk_default_block : game->textures['1'] malloc fail");
	if (!(game->textures['1']->grid_w = malloc(sizeof(long long **) * (100))))
		lib_do_exit("debug_mk_default_block : game->textures['1'] malloc fail");
	while (i < 100)
	{
		if (!(game->textures['1']->grid_w[i] = malloc(sizeof(long long *) * (100))))
			lib_do_exit("debug_mk_default_block : game->textures['1'] malloc fail");
		i++;
	}
	i = 0;

	while (x < 100)
	{
		while (y < 100)
		{
			game->textures['1']->grid_n[y][x] = &(game->textures['1']->bitmap_n[i]);
			game->textures['1']->grid_s[y][x] = &(game->textures['1']->bitmap_s[i]);
			game->textures['1']->grid_e[y][x] = &(game->textures['1']->bitmap_e[i]);
			game->textures['1']->grid_w[y][x] = &(game->textures['1']->bitmap_w[i]);
			y++;
			i++;
		}
		y = 0;
		x++;
	}
	i = 0;
	while (i < 10000)
	{
		game->textures['1']->bitmap_n[i] = 0x0000ff;
		game->textures['1']->bitmap_s[i] = 0x00ff00;
		game->textures['1']->bitmap_e[i] = 0xff0000;
		game->textures['1']->bitmap_w[i] = 0xffffff;
		i++;
	}
	game->textures['1']->mult_n_x = 1;
	game->textures['1']->mult_n_y = 1;
	game->textures['1']->mult_s_x = 1;
	game->textures['1']->mult_s_y = 1;
	game->textures['1']->mult_e_x = 1;
	game->textures['1']->mult_e_y = 1;
	game->textures['1']->mult_w_x = 1;
	game->textures['1']->mult_w_y = 1;

	game->textures['1']->grid_n_size_x = 100;
	game->textures['1']->grid_n_size_y = 100;
	game->textures['1']->grid_s_size_x = 100;
	game->textures['1']->grid_s_size_y = 100;
	game->textures['1']->grid_e_size_x = 100;
	game->textures['1']->grid_e_size_y = 100;
	game->textures['1']->grid_w_size_x = 100;
	game->textures['1']->grid_w_size_y = 100;
}