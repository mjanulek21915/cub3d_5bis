#include "cub3d.h"

void					init_main(t_game *game)
{

	if (!(game->screen = malloc(sizeof(t_screen))))
		lib_do_exit("game->screen malloc fail");
	if (!(game->map = malloc(sizeof(t_map))))
		lib_do_exit("game->map malloc fail");
	game->map->path = MAP_PATH;

	init_functions(game);
fprintf(stderr, "----init_functions ok\n");

	debug_read_map(game);
fprintf(stderr, "----init_functions ok\n");

	init_player(game);
fprintf(stderr, "----init_player ok\n");

	init_screen(game);
fprintf(stderr, "----init_screen ok\n");

	init_angles(game);
fprintf(stderr, "----init_angles ok\n");

	init_structures(game);
fprintf(stderr, "----init_structures ok\n");

	debug_mk_default_block(game);
fprintf(stderr, "----debug_mk_default_block ok\n");


}