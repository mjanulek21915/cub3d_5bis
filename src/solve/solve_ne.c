#include "cub3d.h"

void					solve_ne_x(t_game *game, float f)
{
	solve_x(ceil(game->player->actor->pos_y + f), 1, game, 0, 0);
}

void					solve_ne_y(t_game *game, float f)
{
	solve_y(floor(game->player->actor->pos_x - f), 1, game, 0, 0);
}