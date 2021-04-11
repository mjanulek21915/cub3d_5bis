#include "cub3d.h"

void					init_angles(t_game *game)
{
	float distance;
	float length;
	float *temp_angles;
	int i;
	int j;

	i = 0;
	length = game->screen->res_h/2 + 1;
	fprintf(stderr, "init_angles : length = %f\n", length);
	if (!(temp_angles = malloc(sizeof(float) * (int)length)))
		lib_do_exit("init_angles : temp_angles malloc fail");
	if (!(game->map->angles = malloc(sizeof(float) * game->screen->res_h)))
		lib_do_exit("init_angles : game->map->angles malloc fail");
	distance = tan(90 - (game->screen->fov_h/2)) * length;


	while (i < game->screen->res_h)
	{
		game->map->angles[i] = atan(length/distance);
		i++;
		length = length - 1;
	}
	i = 0;
// 	while (i < game->screen->res_h)
// 	{
// fprintf(stderr, "i = %d\ngame->map->angles = %f\n", i, game->map->angles[i]);
// 		i++;
// 	}
}