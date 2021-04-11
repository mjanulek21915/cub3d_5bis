#include "cub3d.h"

void					actor_translate_down(t_actor *actor, double dst)
{
	actor->pos_x = actor->pos_x - sin(actor->hdg) * dst;
	actor->pos_y = actor->pos_y - cos(actor->hdg) * dst;
}