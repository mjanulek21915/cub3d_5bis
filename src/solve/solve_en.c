#include "cub3d.h"

void					solve_en(t_game *game)
{
fprintf(stderr, "solve_en\n");
	solve_x(ceil(game->player->actor->pos_y), 1, game);
	solve_y(floor(game->player->actor->pos_x), 1, game);
}