#include "gol.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>

t_map	*map_dim(char *buffer, t_map *map_d)
{
	int		i = 0;

	map_d->height = 1;
	map_d->width = 0;
	while (buffer[i] != 'x')
	{
		if (buffer[i] == '\n')
		{
			map_d->width = 0;
			map_d->height++;
		}
		else
			map_d->width++;
		i++;
	}
	return (map_d);
}

int	**binary_map(char *buffer, t_map *map_d)
{
	int		i = 0;
	int		**map;

	map_d->i = 0;
	map_d->j = 0;
	map = (int **)malloc(sizeof(int *) * map_d->height);
	map[0] = (int *)malloc(sizeof (int) * map_d->width);
	while (buffer[i] != 'x')
	{
		if (buffer[i] != 'x' && buffer[i] != '\n')
		{
			if (buffer[i] == '*')
				map[map_d->j][map_d->i] = 1;
			else
				map[map_d->j][map_d->i] = 0;
			map_d->i++;
		}
		else if (buffer[i] == '\n')
		{
			map_d->i = 0;
			map_d->j++;
			map[map_d->j] = (int *)malloc(sizeof (int) * map_d->width);
		}
		i++;
	}
	return (map);
}

int	**map_open(char *file_name, t_map	*map_d)
{
	int		fd;
	int		fb;
	int		**map;
	char	buffer[1024];

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (0);
	fb = read(fd, buffer, sizeof (buffer));
	if (fb < 0)
		return (0);
	map_d = map_dim(buffer, map_d);
	map = binary_map(buffer, map_d);
	return (map);
}
