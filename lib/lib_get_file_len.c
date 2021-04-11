#include "cub3d.h"

int						lib_get_file_len(char *path)
{
	int fd;
	int len;
	char temp;

	len = 0;
	if ((fd = open(path, O_RDONLY)) < 0)
		lib_do_exit("lib_get_file_len open error");
	while (read(fd, &temp, 1))
		len++;
	return (len);
}