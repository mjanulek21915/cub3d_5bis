#include "cub3d.h"

void debug_solve(t_game *game)
{
	int i;
	int temp;
	int direction;
	double x;
	double y;
	t_job *temp_job;
	int is_done = 1;

	i = 0;

	temp = (int)((game->job_hdg / (2 * PI)) * 8);
	direction = ((temp + 1 - (7 * (temp > 6))) / 2) * (temp < 7);

	game->job_tgt_x = &(game->jobs_hidden[16]);
	game->job_tgt_y = &(game->jobs_hidden[17]);

	x = 0;
	y = 0;

	game->job_x = 0;
	game->job_y = 0;

	while (!game->job_x)
	{
		game->solve_x[temp](game, x);
		x = x + 1;
	}
	while (!game->job_y)
	{
		game->solve_y[temp](game, y);
		y = y + 1;
	}


	while (is_done)
	{
		while (game->job_tgt_x->distance < game->job_tgt_y->distance && game->job_tgt_x->type != 'x')
		{
			game->job_x = 0;
			temp_job = game->jobs[i];
			game->jobs[i] = game->job_tgt_x;
			game->job_tgt_x = temp_job;
			i++;
			game->job_i = i;

			if (game->jobs[i - 1]->type = '1')
			{
				return;
			}

			game->job_x = 0;

			while (!game->job_x)
			{
				game->solve_x[temp](game, x);
				x = x + 1;
			}
		}
		while (game->job_tgt_x->distance >= game->job_tgt_y->distance && game->job_tgt_y->type != 'x')
		{
			game->job_y = 0;
			temp_job = game->jobs[i];
			game->jobs[i] = game->job_tgt_y;
			game->job_tgt_y = temp_job;
			i++;
			game->job_i = i;

			if (game->jobs[i - 1]->type = '1')
			{
				return;
			}

			game->job_y = 0;

			while (!game->job_y)
			{
				game->solve_y[temp](game, y);
				y = y + 1;
			}

		}
	}
// fprintf(stderr, "----debug_solve end\n");
}