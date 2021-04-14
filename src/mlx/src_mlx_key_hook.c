#include "cub3d.h"


int						src_mlx_key_hook(int key, t_game *game)
{
fprintf(stderr, "key = %d\n", key);

	double *hdg;
	int temp;
	int direction;

	hdg = &(game->player->actor->hdg);
	if (key == 65307)
		exit(0);
	else if  (key == 65362)
		actor_translate_up(game->player->actor, game->player->translation_speed);
	else if  (key == 65364)
		actor_translate_down(game->player->actor, game->player->translation_speed);
	else if  (key == 65361)
		actor_rotate_left(game->player->actor, game->player->rotation_speed);
	else if  (key == 65363)
		actor_rotate_right(game->player->actor, game->player->rotation_speed);

	*hdg = *hdg + (2 * PI * (*hdg < 0)) - (2 * PI * (*hdg >= (2 * PI)));
	temp = (int)((*hdg / (2 * PI)) * 8);
	direction = ((temp + 1 - (7 * (temp > 6))) / 2) * (temp < 7);
	fprintf (stderr, "pos_x : %f\npos_y : %f\ndeg : %f\n rads : %f\n\n", game->player->actor->pos_x, game->player->actor->pos_y, game->player->actor->hdg * 57.29578, game->player->actor->hdg);
	fprintf(stderr, "direction : %d\ntemp : %d\n", direction, temp);
	screen_update(game);
	// debug_solve(game);
	
}
