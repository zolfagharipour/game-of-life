#include "gol.h"
//int		**next_step(int **map, t_map map_d);
void	map_print(int **map, t_map map_d);
int		**column_2(t_map map_d);


int	main()
{
	t_map map_d;
	int	i = 0;
	int	**map;

	map_d.height = 11;
	map_d.width = 11;
	map = column_2(map_d);
	while (i < 30)
	{
		map_print(map, map_d);
		map = next_step(map, map_d);
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