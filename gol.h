#ifndef GOL_H
# define GOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_map{
	int	height;
	int	width;
	int	i;
	int	j;
} t_map;

int		**next_step(int **map, t_map map_d);
void	map_print(int **map, t_map map_d);
int		**map_open(char *file_name, t_map *map_d);
t_map	*map_dim(char *buffer, t_map	*map_d);


#endif