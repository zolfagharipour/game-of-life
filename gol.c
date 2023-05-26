#include "gol.h"
int		**map_open(char *file_name, t_map *map_d);
int	**map_fit(int **map, t_map map_d);

int	main()
{
	t_map map_d;
	int	i = 0;
	int	**map;
	//int	**map1;

	map = map_open("map2.txt", &map_d);
	map = map_fit(map, map_d);
	map_d.width = 280;
	map_d.height = 70;

	while (i < 1000)
	{
		write (1, "\033[0;0H", 7);
		map_print(map, map_d);
		map = next_step(map, map_d);
		usleep (200000);
		i++;
	}
	i = 0;
	while (i < map_d.height)
	{
		free (map[i]);
		i++;
	}
	free (map);
	return 0;
}