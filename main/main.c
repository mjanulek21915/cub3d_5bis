#include "cub3d.h"


int						main(int ac, char **av)
{
	fprintf(stderr, "main\n");
	t_game game;
	init_main(&game);
	mlx_key_hook(game.screen->win, src_mlx_key_hook, &game);
	mlx_loop_hook(game.screen->mlx, src_mlx_loop_hook, &game);
	mlx_loop(game.screen->mlx);
}