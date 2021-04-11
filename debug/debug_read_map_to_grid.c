#include "cub3d.h"

void debug_read_map_to_grid(t_game *game)
{
fprintf(stderr, "debug_read_map_to_grid start\n");
	char *temp_text;
	// t_block **game->map->grid->list;
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;

	temp_text = game->map->text;
fprintf(stderr, "%s\n", temp_text);

	while (i < game->map->grid->size)
	{
		game->map->grid->list[i++] = 0;
	}
	i = 0;

fprintf(stderr, "x = %d, y = %d\n", game->map->grid->size_x, game->map->grid->size_y);

	while (*temp_text)
	{
		if (*temp_text && *temp_text != '\n')
		{
			if (*temp_text != '0')
			{
				fprintf(stderr, "debug_read_map_to_grid : found a block. x = %d y = %d\n", i / game->map->grid->size_x, i % game->map->grid->size_y);

				if (!(game->map->grid->list[i] = malloc(sizeof(t_block))))
					lib_do_exit("game->map->grid->list_malloc error");

				game->map->grid->list[i]->type = *temp_text;
			}
			i++;
		}
		temp_text++;
	}
// debug_print_map(game);
fprintf(stderr, "debug_read_map_to_grid end. i = %d\n", i);

}