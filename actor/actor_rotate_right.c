#include "cub3d.h"

void					actor_rotate_right(t_actor *actor, double angle)
{

	actor->hdg = actor->hdg - (angle/57.29578);
}