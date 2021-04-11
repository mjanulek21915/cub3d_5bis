#include "cub3d.h"

int debug_read_map(t_game *game)
{
fprintf(stderr, "----debug_read_map start\n");

	char *temp;
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;

	if (!(game->map->grid = malloc(sizeof(t_grid))))
		lib_do_exit("debug_read_map : grid malloc error");

	game->map->text = lib_get_file(game->map->path);

	debug_read_map_get_size(game);

	if (!(game->map->grid->blocks = malloc(sizeof (t_block**) * game->map->grid->size_x)))
		lib_do_exit("debug_read_map : grid [*] malloc error");


	while (x < game->map->grid->size_x)
	{
		if (!(game->map->grid->blocks[x] = malloc(sizeof (t_block*) * game->map->grid->size_y)))
			lib_do_exit("debug_read_map : grid [*] malloc error");
		x++;
	}


	if (!(game->map->grid->list = malloc(sizeof (t_block*) * game->map->grid->size)))
		lib_do_exit("debug_read_map : grid [*] malloc error");


	x = 0;	

	debug_read_map_to_grid(game);

	while (x < game->map->grid->size_x)
	{
		while (y < game->map->grid->size_y)
		{
			game->map->grid->blocks[x][y] = game->map->grid->list[i++];
			y++;
		}
		y = 0;
		x++;
	}

	game->map->r_limit = 5;

	debug_print_map(game);

fprintf(stderr, "----debug_read_map end\n");
}