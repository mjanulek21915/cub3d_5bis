#include "cub3d.h"

void					solve_y(double tgt_x, double sign, t_game *game, int detection_offset)
{
// fprintf(stderr, "------solve_y start\n");
	double x;
	double y;
	double tgt_y;
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


	d_x = (tgt_x - x);
	d_y = d_x * tan(PI12 - game->job_hdg) * sign;
	tgt_y = y + d_y;

	offset_x = (int)(tgt_x) + detection_offset;
	offset_y = (int)(floor(tgt_y));
	offset_x = offset_x * (offset_x > 0) * (offset_x < max_x);
	offset_y = offset_y * (offset_y > 0) * (offset_y < max_y);

	if (game->map->grid->blocks[offset_x][offset_y])
	{
		game->job_tgt_y->distance = (fabs(d_x / sin(game->job_hdg)));
		game->job_tgt_y->ratio = (tgt_y - offset_y);
		game->job_tgt_y->tgt = game->map->grid->blocks[offset_x][offset_y];
		game->job_tgt_y->type = game->map->grid->blocks[offset_x][offset_y]->type;
		game->job_y = 1;
if (fabs(game->player->actor->hdg - game->job_hdg) < 0.001)
{
fprintf(stderr, "----solve_y TEST:\n");
fprintf(stderr, "    d_x : %f\n", d_x);
fprintf(stderr, "    d_y : %f\n", d_y);
fprintf(stderr, "    tgt_x : %f\n", tgt_x);
fprintf(stderr, "    tgt_y : %f\n", tgt_y);
fprintf(stderr, "    offset_x : %d\n", offset_x);
fprintf(stderr, "    offset_y : %d\n", offset_y);
fprintf(stderr, "    type : %d\n", game->job_tgt_y->type);
fprintf(stderr, "    distance : %f\n", game->job_tgt_y->distance);
fprintf(stderr, "    hdg : %f\n", game->job_hdg * 57.29578);
fprintf(stderr, "----solve_y TEST END:\n");
}
	}
	// fprintf(stderr, "--------solve_y : TEST\n        tgt_x : %f\n        tgt_y : %f\n        offset_x: %d\n        offset_y: %d\n        type: %c\n        distance : %f\n", tgt_x, tgt_y, offset_x, offset_y, game->job_tgt_y->type, game->job_tgt_y->distance);

// fprintf(stderr, "------solve_y end\n");
}