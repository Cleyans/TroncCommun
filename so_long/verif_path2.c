#include "so_long.h"
#include "minilibx/mlx42.h"

void	free_mapcheck(t_game *game)
{
	int	i;

	i = -1;
	while (++i <= game->maps.count_height)
		free(game->maps.path[i]);
	free(game->maps.path);
}

void	init_mapcheck(t_game *game)
{
	int	y;
	int	x;
	
	game->maps.path = malloc((game->maps.count_height + 2) * sizeof(char *));
	y = -1;
	while (++y < (game->maps.count_height))
	{
		game->maps.path[y] = ft_strdup(game->maps.map[y]);
		x = -1;
		while (game->maps.path[y][++x])
		{
			if (game->maps.path[y][x] != '1' && game->maps.path[y][x] != '\n')
				game->maps.path[y][x] = '0';
		}
	}
	game->maps.path[y] = NULL;
}

int	map_checked(t_game *game, int y, int x)
{
	return (game->maps.path[y][x] - 48);
}

void	count_items(t_game *game, int y, int x)
{
	if (game->maps.path[y][x] == 'C')
		game->count_c -= 1;
	if (game->maps.path[y][x] == 'E')
		game->maps.count_e -= 1;
	game->maps.path[y][x] = '1';
}

int	check_path(t_game *game, int y, int x)
{
	int	result[4];

	result[0] = 0;
	result[1] = 0;
	result[2] = 0;
	result[3] = 0;
	count_items(game, y, x);
	if (game->count_c == game->count_c && game->maps.count_e >= 1)
		return (1);
	if (x < 0 || x >= game->maps.count_walls + 1 || y < 0
		|| y >= game->maps.count_height || game->maps.map[y][x] == '1')
		return (0);
	if (game->maps.map[y][x + 1] != '1' && !map_checked(game, y, x + 1))
		result[0] = check_path(game, y, x + 1);
	if (game->maps.map[y][x - 1] != '1' && !map_checked(game, y, x - 1))
		result[1] = check_path(game, y, x - 1);
	if (game->maps.map[y + 1][x] != '1' && !map_checked(game, y + 1, x))
		result[2] = check_path(game, y + 1, x);
	if (game->maps.map[y - 1][x] != '1' && !map_checked(game, y - 1, x))
		result[3] = check_path(game, y - 1, x);
	return (result[0] || result[1] || result[2] || result[3]);
}