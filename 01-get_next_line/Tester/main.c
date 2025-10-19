#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(void)
{
	int		fd;
	char	*line;
	int		res;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		res = get_next_line(fd, &line);
		printf("%d\n", res);
		if (res != -1)
		{
			printf("%s\n", line);
			free(line);
		}
		if (!res || res == -1)
			break;
	}
	close(fd);
	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		res = get_next_line(fd, &line);
		printf("%d\n", res);
		if (res != -1)
		{
			printf("%s\n", line);
			free(line);
		}
		if (!res || res == -1)
			break;
	}
	return (0);
}
