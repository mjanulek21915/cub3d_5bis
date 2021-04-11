#include "cub3d.h"

void					init_player(t_game *game)
{
	if ((!(game->player = malloc(sizeof(t_player)))) || (!(game->player->actor = malloc(sizeof(t_actor)))))
		lib_do_exit("game->player->actor malloc fail");
	game->player->translation_speed = TRANSLATION_SPEED;
	game->player->rotation_speed = ROTATION_SPEED;
	game->player->actor->pos_x = START_POS_X;
	game->player->actor->pos_y = START_POS_Y;
	game->player->actor->hdg = START_HDG;
}