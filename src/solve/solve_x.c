#include "cub3d.h"

void					solve_x(double tgt_y, double sign, t_game *game, int detection_offset)
{
// fprintf(stderr, "------solve_x start\n");
	double x;
	double y;
	double tgt_x;
	double d_y;
	double d_x;
	int offset_x;
	int offset_y;
	int max_x;
	int max_y;


	x = game->player->actor->pos_x;
	y = game->player->actor->pos_y;
	max_x = game->map->grid->size_x + 1;
	max_y = game->map->grid->size_y + 1;

// fprintf(stderr, "solve_x : game->player->actor->pos_x : %f\n    game->player->actor->pos_y : %f\n    tgt_y : %f\n    sign : %f\n", game->player->actor->pos_x, game->player->actor->pos_y, tgt_y, sign);


	d_y = tgt_y - y;
	d_x = d_y * tan(game->job_hdg) * sign;
	tgt_x = x + d_x;

	offset_x = ((int)(floor(tgt_x)));
	offset_y = ((int)(tgt_y)) + detection_offset;
	offset_x = offset_x * (offset_x > 0) * (offset_x < max_x);
	offset_y = offset_y * (offset_y > 0) * (offset_y < max_y);

	if (game->map->grid->blocks[offset_x][offset_y])
	{
		game->job_tgt_x->distance = (fabs(d_y / cos(game->job_hdg)));
		game->job_tgt_x->ratio = (tgt_x - offset_x);
		game->job_tgt_x->tgt = game->map->grid->blocks[offset_x][offset_y];
		game->job_tgt_x->type = game->map->grid->blocks[offset_x][offset_y]->type;
		game->job_x = 1;
if (fabs(game->player->actor->hdg - game->job_hdg) < 0.001)
{
fprintf(stderr, "----solve_x TEST:\n");
fprintf(stderr, "    tgt_x : %f\n", tgt_x);
fprintf(stderr, "    tgt_y : %f\n", tgt_y);
fprintf(stderr, "    offset_x : %d\n", offset_x);
fprintf(stderr, "    offset_y : %d\n", offset_y);
fprintf(stderr, "    type : %d\n", game->job_tgt_x->type);
fprintf(stderr, "    distance : %f\n", game->job_tgt_x->distance);
fprintf(stderr, "    hdg : %f\n", game->job_hdg * 57.29578);
fprintf(stderr, "----solve_x TEST END:\n");
}
	}


// fprintf(stderr, "------solve_x end\n");
}