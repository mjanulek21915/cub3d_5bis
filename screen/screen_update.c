#include "cub3d.h"

void					screen_update(t_game *game)
{
fprintf(stderr, "--screen_update start\n");
	int i;

	i = game->screen->res_h - 1;

// 	while (i)
// 	{
// 		game->job_hdg = (game->player->actor->hdg + game->map->angles_h[i]);
// 		game->job_hdg = game->job_hdg + (2 * PI * (game->job_hdg < 0)) - (2 * PI * (game->job_hdg >= (2 * PI)));
// 		// debug_draw(game, i);
// 		i--;
// 	}
// fprintf(stderr, "  i:%d\n  hdg : %f\n", i, game->map->angles_h[i]);
game->job_hdg = game->player->actor->hdg;
fprintf(stderr, "  screen_update hdg : %f\n", game->job_hdg * 57.29578);
debug_solve(game);
fprintf(stderr, "--screen_update end\n");
}