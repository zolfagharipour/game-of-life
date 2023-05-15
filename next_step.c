#include "gol.h"

int	this_step(int **map, t_map map_d)
{
	int	i = map_d.i - 1;
	int	j = map_d.j - 1;
	int	counter = 0;

	while (j < map_d.j + 2 && j < map_d.height)
	{
		while (j >= 0 && i < map_d.i + 2 && i < map_d.width)
		{
			if (i >= 0 && map[j][i] == 1)
				counter++;
			i++;
		}
		i = map_d.i - 1;
		j++;
	}
	//printf("%d,  ", counter);
	if (counter == 3 || (map[map_d.j][map_d.i] == 1 && counter == 4))
		return (1);
	return (0);
}



int	**next_step(int **map, t_map map_d)
{
	int	map1[map_d.height][map_d.width];

	map_d.i = 0;
	map_d.j = 0;
	while (map_d.j < map_d.height)
	{
		while (map_d.i < map_d.width)
		{
			map1[map_d.j][map_d.i] = this_step(map, map_d);
			map_d.i++;
		}
		//write(1,"\n",1);
		map_d.i = 0;
		map_d.j++;
	}
	
	map_d.i = 0;
	map_d.j = 0;
	while (map_d.j < map_d.height)
	{
		while (map_d.i < map_d.width)
		{
			map[map_d.j][map_d.i] = map1[map_d.j][map_d.i];
			map_d.i++;
		}
		//write(1,"\n",1);
		map_d.i = 0;
		map_d.j++;
	}


	return (map);
}