#include "so_long.h"
#include "minilibx/mlx42.h"
#include <fcntl.h>

void lecturemap(game_t *game)
{
    char *str;
    int i;

    i = 0;
    game->maps.fd = open("maps/map.ber", O_RDONLY);
    str = get_next_line(game->maps.fd);
    game->maps.count_x = ft_strlen(str) - 1;
    while ((str =get_next_line(game->maps.fd))!= NULL)
         i++;
    close(game->maps.fd);
    game->maps.count_y = i + 1;
    game->maps.map = (char **)malloc(sizeof(char *) * (i + 1));
    game->maps.fd = open("maps/map.ber", O_RDONLY);
    i = 0;
    while ((str = get_next_line(game->maps.fd)) != NULL)
    {
        game->maps.map[i] = str;
        i++;
    }
    game->maps.map[i] = NULL;
    close(game->maps.fd);
}

// char	open_maps_malloc(game_t *game)
// {
//     int index;

// 	index = 0;
//     game->maps.fd = open("maps/map.ber", O_RDONLY);
// 	game->maps.str = get_next_line(game->maps.fd);
// 	game->maps.count_x = ft_strlen(game->maps.str) - 1;
// 	while (1)
// 	{
// 		game->maps.str = get_next_line(game->maps.fd);
// 		if (game->maps.str)
// 			return ("Hello");
// 		index++;
// 	}
// 	close(game->maps.fd);
// 	game->maps.map = (char **)malloc(sizeof(char *) * index + 1);
// 	game->maps.count_y = index + 1;
// }

// void	open_maps(game_t *game)
// {
// 	size_t	index;

// 	index = 0;
// 	game->maps.fd = open("maps/map.ber", O_RDONLY);
// 	while (1)
// 	{
// 		game->maps.map = (char **)get_next_line;
// 		game->maps.map[index] = game->maps.str;
// 		index++;
// 	}
// 	game->maps.map[index] = NULL;
// 	close(game->maps.fd);
// }

void	letter_to_png(game_t *game)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	game->maps.count_x = 0;
	game->maps.count_y = 0;
	while (game->maps.map[y])
	{
		while (game->maps.map[y][x])
		{
			if (game->maps.map[y][x] == 'P')
				mlx_image_to_window(game->mlx, game->graph.personnage, game->maps.count_x, game->maps.count_y);
			if (game->maps.map[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->graph.collect, game->maps.count_x, game->maps.count_y);
			if (game->maps.map[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->graph.collect, game->maps.count_x, game->maps.count_y);
			if (game->maps.map[y][x]== '1')
				mlx_image_to_window(game->mlx, game->graph.walls, game->maps.count_x, game->maps.count_y);
			x++;
			game->maps.count_x += 64;
		}
		x = 0;
		game->maps.count_x = 0;
		y++;
		game->maps.count_y += 64;
	}
}