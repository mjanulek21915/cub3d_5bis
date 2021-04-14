#include "cub3d.h"

void					solve_se_x(t_game *game, float f)
{
	solve_x(ceil(game->player->actor->pos_y + f), 1, game, 0, 0);
}

void					solve_se_y(t_game *game, float f)
{
	solve_y(ceil(game->player->actor->pos_x + f), 1, game, 1, 0);
}