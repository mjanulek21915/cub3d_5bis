#include "cub3d.h"

void					actor_translate_right(t_actor *actor, double dst)
{
	actor->pos_x = actor->pos_x - cos(actor->hdg) * dst;
	actor->pos_y = actor->pos_y + sin(actor->hdg) * dst;
}