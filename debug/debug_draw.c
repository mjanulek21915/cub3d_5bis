#include "cub3d.h"

void debug_draw(t_game *game, int column)
{
// fprintf(stderr, "----debug_draw start\n");
	t_texture *texture;
	int texture_x;
	int texture_y;
	int screen_x;
	int i;
	int j;
	int done;
	int texture_start;
	int screen_start;

	i = game->job_i;
	j = 0;
	done = 0;
	screen_start = (game->screen->res_v / 2) - 1;
	while (i--)
	{
		texture = game->textures[game->jobs[i]->type];
		texture_y = (int)(game->jobs[i]->ratio * (double)(texture->grid_n_size_y));
		texture_start = texture->grid_n_size_x/2;
		j = 0;
		while (!done)
		{
			texture_x = texture_start + ((int)((double)j * game->jobs[i]->distance * texture->mult_n_x));
			if (texture_x >= texture->grid_n_size_x || j > screen_start)
				break;
			// fprintf(stderr, "    debug_draw loop a : texture_x : %d\n", texture_x);
			// fprintf(stderr, "    debug_draw loop a : texture_y : %d\n", texture_y);
			// fprintf(stderr, "    debug_draw loop a texture->grid_n : %u\n", *(texture->grid_n[texture_x][texture_y]));
			// fprintf(stderr, "    debug_draw loop a column :  %d\n", column);
			// fprintf(stderr, "    debug_draw loop a screen_start + j : %d\n", screen_start + j);


			*(game->bitmap[column][screen_start + j]) = *(texture->grid_n[texture_x][texture_y]);


			// fprintf(stderr, "    debug_draw loop a ok\n\n");

			j++;
		}
		j = 1;
		while (!done)
		{
			// fprintf(stderr, "    debug_draw loop b\n");
			texture_x = texture_start - ((int)((double)j * game->jobs[i]->distance * texture->mult_n_x));
			if (texture_x < 0 || j > screen_start)
				break;
			*(game->bitmap[column][screen_start - j]) = *(texture->grid_n[texture_x][texture_y]);
			j++;
		}
	}
// fprintf(stderr, "----debug_draw end\n");
}