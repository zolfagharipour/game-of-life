#include "gol.h"

int	**column_2(t_map map_d)
{
	int	**ptr;
	int	i = 0;
	int	j = 0;

	ptr = (int **)malloc(sizeof(int) * map_d.height);
	if (!ptr)
		return(0);
	while (j < map_d.height)
	{
		ptr[j] = (int *)malloc(sizeof(int) * map_d.width);
		if (!ptr[j])
			return (0);
		while(i < map_d.width)
		{
			if (i % 2 == 0)
				ptr[j][i] = 0;
			else
				ptr[j][i] = 1;
			i++;
		}
		i = 0;
		j++;
	}
	return (ptr);
}

void	map_print(int **map, t_map map_d)
{
	int	i = 0;
	int	j = 0;

	while (j < map_d.height)
	{
		while (i < map_d.width)
		{
			if (map[j][i] == 0)
			{
				write (1, ".  ", 3);
			}
			else
			{
				write (1, "#  ", 3);
			}
			i++;
		}
		write (1, "\n", 1);
		i = 0;
		j++;
	}
	i = 0;
	while (i < map_d.width)
	{
		write (1, "    ", 3);
		i++;
	}
	write (1, "\n", 1);
}
