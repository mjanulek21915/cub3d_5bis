#include "cub3d.h"

void					init_functions(t_game *game)
{
	game->solve_x[0] = solve_es_x;
	game->solve_x[1] = solve_se_x;
	game->solve_x[2] = solve_sw_x;
	game->solve_x[3] = solve_ws_x;
	game->solve_x[4] = solve_wn_x;
	game->solve_x[5] = solve_nw_x;
	game->solve_x[6] = solve_ne_x;
	game->solve_x[7] = solve_en_x;
	game->solve_x[8] = solve_en_x;

	game->solve_y[0] = solve_es_y;
	game->solve_y[1] = solve_se_y;
	game->solve_y[2] = solve_sw_y;
	game->solve_y[3] = solve_ws_y;
	game->solve_y[4] = solve_wn_y;
	game->solve_y[5] = solve_nw_y;
	game->solve_y[6] = solve_ne_y;
	game->solve_y[7] = solve_en_y;
	game->solve_y[8] = solve_en_y;
}