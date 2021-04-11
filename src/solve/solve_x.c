#include "cub3d.h"

void					solve_x(float tgt_y, float sign, t_game *game)
{
	float x;
	float y;
	float tgt_x;
	float d_y;
	float d_x;
	int offset_x;
	int offset_y;


	x = game->player->actor->pos_x;
	y = game->player->actor->pos_y;

fprintf(stderr, "----solve_x start\n");


	d_y = tgt_y - y;
fprintf(stderr, ">d_y = %f\n", d_y);
	d_x = d_y * tan(game->player->actor->hdg) * sign;
fprintf(stderr, ">d_x = %f\n", d_x);
	tgt_x = x + d_x;
fprintf(stderr, ">tgt_x = %f\n>tgt_y = %f\n", tgt_x, tgt_y);
	offset_x = (int)(floor(tgt_x));
	offset_y = (int)(tgt_y - 1);
fprintf(stderr, ">offset_x = %d\n>offset_y = %d\n", offset_x, offset_y);
fprintf(stderr, "----solve_x end\n");

}