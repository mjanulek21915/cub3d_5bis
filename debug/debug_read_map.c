#include "cub3d.h"

int debug_read_map(t_game *game)
{
fprintf(stderr, "----debug_read_map start\n");

	char *temp;
	int x;
	int y;
	int i;

	i = 0;
	x = 0;
	y = 0;

	if (!(game->map->grid = malloc(sizeof(t_grid))))
		lib_do_exit("debug_read_map : grid malloc error");

	game->map->text = lib_get_file(game->map->path);

	debug_read_map_get_size(game);

	if (!(game->map->grid->blocks = malloc(sizeof (t_block**) * (game->map->grid->size_x + 1))))
		lib_do_exit("debug_read_map : grid [*] malloc error");


	while (x < game->map->grid->size_x + 1)
	{
		if (!(game->map->grid->blocks[x] = malloc(sizeof (t_block*) * (game->map->grid->size_y + 1))))
			lib_do_exit("debug_read_map : grid [*] malloc error");
		x++;
	}


	if (!(game->map->grid->list = malloc(sizeof (t_block*) * game->map->grid->size)))
		lib_do_exit("debug_read_map : grid [*] malloc error");

	if (!(game->map->grid->filler = malloc(sizeof (t_block))))
		lib_do_exit("debug_read_map : grid [*] malloc error");

game->map->grid->filler->type = 'x';

	x = 1;	
	y = 1;

	debug_read_map_to_grid(game);

	while (x < game->map->grid->size_x + 1)
	{
		while (y < game->map->grid->size_y + 1)
		{
			game->map->grid->blocks[x][y] = game->map->grid->list[i++];
			y++;
		}
		y = 1;
		x++;
	}

	x = 0;
	y = 0;

	while (x < game->map->grid->size_x + 1)
	{
		game->map->grid->blocks[x][y] = game->map->grid->filler;
		x++;
	}
	x = 0;

	while (y < game->map->grid->size_y + 1)
	{
		game->map->grid->blocks[x][y] = game->map->grid->filler;
		y++;
	}

	game->map->r_limit = 5;

	debug_print_map(game);

fprintf(stderr, "----debug_read_map end\n");
}