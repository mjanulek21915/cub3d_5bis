#include "cub3d.h"

void					solve_wn_x(t_game *game, double f)
{
	solve_x(floor(game->player->actor->pos_y - f), 1, game, -1);
}

void					solve_wn_y(t_game *game, double f)
{
	solve_y(floor(game->player->actor->pos_x - f), 1, game, -1);
}