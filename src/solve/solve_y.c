#include "cub3d.h"

void					solve_y(float tgt_x, float sign, t_game *game)
{
	float x;
	float y;
	float tgt_y;
	float d_y;
	float d_x;
	int offset_x;
	int offset_y;

	x = game->player->actor->pos_x;
	y = game->player->actor->pos_y;

fprintf(stderr, "----solve_y start\n");

	d_x = tgt_x - x;
fprintf(stderr, "d_x = %f\n", d_x);
	d_y = d_x * tan(PI12 - game->player->actor->hdg) * sign;
fprintf(stderr, "d_y = %f\n", d_y);
	tgt_y = y + d_y;
fprintf(stderr, "tgt_x = %f\n>tgt_y = %f\n\n", tgt_x, tgt_y);
	offset_x = (int)(tgt_x - 1);
	offset_y = (int)(floor(tgt_y));
fprintf(stderr, ">offset_x = %d\n>offset_y = %d\n", offset_x, offset_y);
fprintf(stderr, "----solve_y end\n");

}