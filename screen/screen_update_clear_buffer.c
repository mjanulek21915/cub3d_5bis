#include "cub3d.h"

void					screen_update_clear_buffer(t_game *game)
{	
	int x;
	int y;
	int y_p;

	x = game->screen->res_v;
	y = game->screen->res_h;
	y_p = y;

	while (x--)
	{
		while (y--)
		{
			// fprintf(stderr, "----screen_update_clear_buffer x : %d, y : %d\n", x, y);
			*(game->bitmap[y][x]) = 0;
		}
		y = y_p;
	}
}