#include "cub3d.h"

void debug_solve(t_game *game)
{
fprintf(stderr, "debug_solve : %d\n", (int)((game->player->actor->hdg / (2 * PI)) * 8));
	game->solve[(int)(game->player->actor->hdg / (2 * PI) * 8)](game);
}