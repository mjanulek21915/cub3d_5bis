#include "cub3d.h"

void					solve_wn(t_game *game)
{
fprintf(stderr, "solve_wn\n");
	solve_x(ceil(game->player->actor->pos_y), -1, game);
	solve_y(floor(game->player->actor->pos_x), -1, game);
}