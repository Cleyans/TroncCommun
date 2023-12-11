/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letter_to_png.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:56:32 by brclemen          #+#    #+#             */
/*   Updated: 2023/12/11 16:58:27 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	letter_to_png(t_game *game)
{
	game->maps.count_height = 0;
	game->maps.count_lenght = 0;
	while (game->maps.map[game->maps.h])
	{
		while (game->maps.map[game->maps.h][game->maps.l])
		{
			if (game->maps.map[game->maps.h][game->maps.l] == 'P')
				load_letter_p(game);
			else if (game->maps.map[game->maps.h][game->maps.l] == 'C')
				load_letter_c(game);
			else if (game->maps.map[game->maps.h][game->maps.l] == 'E')
				load_letter_e(game);
			else if (game->maps.map[game->maps.h][game->maps.l] == '1')
				mlx_image_to_window(game->mlx, game->graph.walls,
					game->maps.count_height, game->maps.count_lenght);
			game->maps.l++;
			game->maps.count_height += 64;
		}
		game->maps.l = 0;
		game->maps.count_height = 0;
		game->maps.h++;
		game->maps.count_lenght += 64;
	}
	map_error(game);
	// error_rectangle(game);
}

void	load_letter_p(t_game *game)
{
	game->maps.count_p++;
	mlx_image_to_window(game->mlx, game->graph.person,
		game->maps.count_height, game->maps.count_lenght);
	game->player.player_height = game->maps.h;
	game->player.player_lenght = game->maps.l;
}

void	load_letter_c(t_game *game)
{
	game->count_c++;
	mlx_image_to_window(game->mlx, game->graph.collect,
		game->maps.count_height, game->maps.count_lenght);
}

void	load_letter_e(t_game *game)
{
	game->maps.count_e++;
	mlx_image_to_window(game->mlx, game->graph.exit,
		game->maps.count_height, game->maps.count_lenght);
}

void	load_letter_1(t_game *game)
{
	mlx_image_to_window(game->mlx, game->graph.walls,
		game->maps.count_height, game->maps.count_lenght);
}
