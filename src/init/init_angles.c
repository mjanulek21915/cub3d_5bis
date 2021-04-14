#include "cub3d.h"

void					init_angles(t_game *game)
{
	float distance;
	float length;
	int i;
	int j;

	i = 0;
	length = (float)(game->screen->res_h/2 + 1);
	fprintf(stderr, "init_angles : length = %f\n", length);
	if (!(game->map->angles_h = malloc(sizeof(float) * game->screen->res_h)))
		lib_do_exit("init_angles : game->map->angles_h malloc fail");
	distance = tan(90 - (game->screen->fov_h/2)) * length;


	while (i < game->screen->res_h)
	{
		game->map->angles_h[i] = atan(length/distance);
		i++;
		length = length - 1;
	}


	i = 0;
	length = (float)(game->screen->res_v/2 + 1);
		fprintf(stderr, "init_angles : length = %f\n", length);
	if (!(game->map->angles_v = malloc(sizeof(float) * game->screen->res_v)))
		lib_do_exit("init_angles : game->map->angles_h malloc fail");

	while (i < game->screen->res_v)
	{
		game->map->angles_v[i] = atan(length/distance);
		i++;
		length = length - 1;
	}

}