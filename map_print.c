#include "gol.h"

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
				write (1, "-", 1);
			}
			else
			{
				write (1, "#", 1);
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


int	**map_fit(int **map, t_map map_d)
{
	int	**fit_map;
	int	i;
	int	j;
	
	fit_map = (int **)malloc(sizeof(int *) * 70);
	map_d.j = 0;
	j = 0;
	while (map_d.j < 70)
	{
		fit_map[map_d.j] = (int *)malloc(sizeof(int) * 280);
		map_d.i = 0;
		i = 0;
		while (map_d.i < 280)
		{
			if (map_d.i >= 140 - map_d.width /2 && map_d.i <= 140 + map_d.width /2 && map_d.j >= 35 - map_d.height /2 && map_d.j <= 35 + map_d.height /2)
			{
				fit_map[map_d.j][map_d.i] = map[j][i];
				i++;
			}
			else
				fit_map[map_d.j][map_d.i] = 0;	
			
			map_d.i++;
		}
		if (map_d.j >= 35 - map_d.height /2)
			j++;
		map_d.j++;

	}
	j = 0;
	while(j < map_d.height)
	{
		free (map [j]);
		j++;
	}
	free(map);
	return (fit_map);
}