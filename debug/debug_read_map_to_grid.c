#include "cub3d.h"

void debug_read_map_to_grid(t_game *game)
{
fprintf(stderr, "----debug_read_map_to_grid start\n");
	char *temp_text;
	int i;

	i = 0;

	temp_text = game->map->text;

	while (i < game->map->grid->size)
	{
		game->map->grid->list[i++] = 0;
	}
	i = 0;

fprintf(stderr, "----debug_read_map_to_grid : temp text :\n%s\n", temp_text);
	while (*temp_text)
	{
		if (*temp_text && *temp_text != '\n')
		{
			if (*temp_text != '0')
			{

				if (!(game->map->grid->list[i] = malloc(sizeof(t_block))))
					lib_do_exit("debug_read_map_to_grid malloc error");
				game->map->grid->list[i]->type = *temp_text;
fprintf(stderr, "--debug_read_map_to_grid : *temp text : %c\n", *temp_text);
			}
			i++;
		}
		temp_text++;
	}
fprintf(stderr, "----debug_read_map_to_grid end\n");

}