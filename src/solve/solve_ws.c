#include "cub3d.h"

void					solve_ws(t_game *game)
{
fprintf(stderr, "solve_ws\n");
	solve_x(ceil(game->player->actor->pos_y), -1, game);
	solve_y(ceil(game->player->actor->pos_x), -1, game);
}