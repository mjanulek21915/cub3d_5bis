#include "cub3d.h"

void					init_main(t_game *game)
{

	if (!(game->screen = malloc(sizeof(t_screen))))
		lib_do_exit("game->screen malloc fail");
	if (!(game->map = malloc(sizeof(t_map))))
		lib_do_exit("game->map malloc fail");
	game->map->path = MAP_PATH;

	init_functions(game);
	debug_read_map(game);
	init_player(game);
	init_screen(game);
	init_angles(game);
}