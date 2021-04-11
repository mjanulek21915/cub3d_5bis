#include "cub3d.h"

void debug_print_map(t_game *game)
{
	int x = 0;
	int y = 0;
	int i = 0;


fprintf(stderr, "------debug_print_map\n");

fprintf(stderr, "list:\n");
	while (i < game->map->grid->size)
	{
		if (game->map->grid->list[i])
				fprintf(stderr, "%c", game->map->grid->list[i]->type);
			else
				fprintf(stderr, "0");
			i++;
fprintf(stderr, "<\n");	
	}


fprintf(stderr, "grid:\n");
	while (x < game->map->grid->size_x)
	{
		while (y < game->map->grid->size_y)
		{
			if (game->map->grid->blocks[x][y])
				fprintf(stderr, "%c", game->map->grid->blocks[x][y]->type);
			else
				fprintf(stderr, "0");
			y++;
		}
		y = 0;
		x++;
		fprintf(stderr, "<\n");
	}
	fprintf(stderr, "------debug_print_map end\n");
}