#include "cub3d.h"

void					solve_nw(t_game *game)
{
fprintf(stderr, "solve_nw\n");
	solve_x(ceil(game->player->actor->pos_y), -1, game);
	solve_y(floor(game->player->actor->pos_x), -1, game);
}