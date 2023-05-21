#include "gol.h"
int		**map_open(char *file_name, t_map *map_d);

int	main()
{
	t_map map_d;
	int	i = 0;
	int	**map;

	map = map_open("map3.txt", &map_d);

	while (i < 100)
	{
		write (1, "\033[0;0H", 7);
		map_print(map, map_d);
		map = next_step(map, map_d);
		usleep (400000);
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