/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:08:33 by brclemen          #+#    #+#             */
/*   Updated: 2023/12/07 13:27:29 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx42.h"
#include <fcntl.h>

void	lecturemap(game_t *game)
{
	char	*str;
	int		i;

	game->maps.count_l = 0;
	game->maps.count_h = 0;
	i = 0;
	game->maps.fd = open("map.ber", O_RDONLY);
	str = get_next_line(game->maps.fd);
	game->maps.count_l = ft_strlen(str) - 1;
	while ((str = get_next_line(game->maps.fd)) != NULL)
	{
		i++;
	}
	close(game->maps.fd);
	game->maps.count_h = i + 1;
	game->maps.map = (char **)malloc(sizeof(char *) * (i + 1));
	game->maps.fd = open("map.ber", O_RDONLY);
	i = 0;
	while ((str = get_next_line(game->maps.fd)) != NULL)
	{
		game->maps.map[i] = str;
		i++;
	}
	game->maps.map[i] = NULL;
	close(game->maps.fd);
}

void	letter_to_png(game_t *game)
{
	int	h;
	int	l;

	game->maps.count_h = 0;
	game->maps.count_l = 0;
	while (game->maps.map[h])
	{
		while (game->maps.map[h][l])
		{
			if (game->maps.map[h][l] == 'P')
				mlx_image_to_window(game->mlx, game->graph.personnage,
					game->maps.count_h, game->maps.count_l);
			else if (game->maps.map[h][l] == 'C')
				mlx_image_to_window(game->mlx, game->graph.collect,
					game->maps.count_h, game->maps.count_l);
			else if (game->maps.map[h][l] == 'E')
				mlx_image_to_window(game->mlx, game->graph.exit,
					game->maps.count_h, game->maps.count_l);
			else if (game->maps.map[h][l]== '1')
				mlx_image_to_window(game->mlx, game->graph.walls,
					game->maps.count_h, game->maps.count_l);
			l++;
			game->maps.count_h += 64;
		}
		l = 0;
		game->maps.count_h = 0;
		h++;
		game->maps.count_l += 64;
	}
}
