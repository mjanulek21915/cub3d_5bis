#include "cub3d.h"

void					lib_do_exit(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}