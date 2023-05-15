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
				write (1, "  ", 2);
			}
			else
			{
				write (1, "# ", 2);
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
