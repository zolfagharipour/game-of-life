#ifndef GOL_H
# define GOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_map{
	int	height;
	int	width;
	int	i;
	int	j;
} t_map;

int		**next_step(int **map, t_map map_d);
void	map_print(int **map, t_map map_d);
int		**column_2(t_map map_d);


#endif