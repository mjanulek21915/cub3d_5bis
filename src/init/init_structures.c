#include "cub3d.h"

void					init_structures(t_game *game)
{
	int i;
	int x;
	int y;
	long long int *temp;

	i = 0;
	x = 0;
	y = 0;
	game->job_tgt_x = 0;
	game->job_tgt_y = 0;
	temp = (long long int *)game->screen->img->data;
	while (i < 15)
	{
		game->jobs[i] = &(game->jobs_hidden[i]);
		i++;
	}
	i = 0;
	if (!(game->bitmap = malloc(sizeof(long long **) * game->screen->res_h)))
		lib_do_exit("init_structures : game->bitmap malloc fail\n");
	while (i < game->screen->res_h)
	{
		if (!(game->bitmap[i] = malloc(sizeof(long long *) * game->screen->res_v)))
		lib_do_exit("init_structures : game->bitmap malloc fail\n");
		i++;
	}
	i = 0;

	while (x < game->screen->res_h)
	{
		while (y < game->screen->res_v)
		{
			game->bitmap[y][x] = &(temp[i]);
			y++;
			i++;
		}
		y = 0;
		x++;
	}

}