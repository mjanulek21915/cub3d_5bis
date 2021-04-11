#include "cub3d.h"

void					init_functions(t_game *game)
{
	game->solve[0] = solve_es;
	game->solve[1] = solve_se;
	game->solve[2] = solve_sw;
	game->solve[3] = solve_ws;
	game->solve[4] = solve_wn;
	game->solve[5] = solve_nw;
	game->solve[6] = solve_ne;
	game->solve[7] = solve_en;
	game->solve[8] = solve_en;
}