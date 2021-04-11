#include "cub3d.h"

void debug_read_map_get_size(t_game *game)
{
	char *temp;
	int x;
	int y;
	int temp_x;
	int temp_y;

	x = 0;
	y = 0;
	temp_y = 0;

	temp = game->map->text;
	while (*temp)
	{
		if (*temp == '\n'|| !*(temp + 1))
		{
			if (temp_y < y)
				temp_y = y;
			y = 0;
			x++;
		}
		else
			y++;
		temp++;
	}
	game->map->grid->size_x = x;
	game->map->grid->size_y = temp_y;
	game->map->grid->size = x * temp_y;
}