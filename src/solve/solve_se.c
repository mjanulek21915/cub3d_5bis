#include "cub3d.h"

void					solve_se(t_game *game)
{
fprintf(stderr, "solve_se\n");
	solve_x(ceil(game->player->actor->pos_y), 1, game);
	solve_y(ceil(game->player->actor->pos_x), 1, game);

}