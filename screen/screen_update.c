#include "cub3d.h"

void					screen_update(t_game *game)
{
// fprintf(stderr, "--screen_update start\n");
	int i;

	i = game->screen->res_h - 1;

screen_update_clear_buffer(game);
	while (i)
	{
		game->job_hdg = (game->player->actor->hdg + game->map->angles_h[i]);
		game->job_hdg = game->job_hdg + (2 * PI * (game->job_hdg < 0)) - (2 * PI * (game->job_hdg >= (2 * PI)));
		debug_solve(game);
		debug_draw(game, i);
		i--;
	}
// fprintf(stderr, "  i:%d\n  hdg : %f\n", i, game->map->angles_h[i]);
game->job_hdg = game->player->actor->hdg;
// fprintf(stderr, "  screen_update hdg : %f\n", game->job_hdg * 57.29578);
// fprintf(stderr, "  game->job_i : %d\n", game->job_i);
mlx_put_image_to_window(game->screen->mlx, game->screen->win, game->screen->img, 0, 0);
// fprintf(stderr, "--screen_update end\n");
}