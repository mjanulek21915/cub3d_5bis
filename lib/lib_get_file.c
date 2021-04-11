#include "cub3d.h"

char					*lib_get_file(char *path)
{
	char *rst;
	int fd;
	int len;

	len = lib_get_file_len(path);
fprintf(stderr, "lib_get_file len : %d\n", len);
	if (!(rst = malloc(sizeof(char) * (len + 1))))
		lib_do_exit("lib_get_file malloc fail");
	if ((fd = open(path, O_RDONLY)) < 0)
		lib_do_exit("lib_get_file open fail");
	if (read(fd, rst, len) != len)
		lib_do_exit("lib_get_file read fail");
	rst[len] = 0;
	
	return (rst);
}