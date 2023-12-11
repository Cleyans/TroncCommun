/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:08:42 by brclemen          #+#    #+#             */
/*   Updated: 2023/12/11 16:29:44 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx42.h"
#include "so_long.h"

void	var_ini(t_game *game)
{
	game->player.moving = 0;
	game->player.nb_collect = 0;
	game->player.player_height = 0;
	game->player.player_lenght = 0;
	game->maps.count_height = 0;
	game->maps.count_lenght = 0;
	game->maps.count_walls = 0;
	game->count_c = 0;
	game->exit = 1;
	game->maps.count_e = 0;
	game->maps.count_p = 0;
	game->maps.h = 0;
	game->maps.l = 0;
}

static void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t	main(void)
{
	t_game	game;

	var_ini(&game);
	read_map(&game);
	game.maps.lenght = game.maps.count_lenght * 64;
	game.maps.height = game.maps.count_height * 64;
	game.mlx = mlx_init(game.maps.lenght, game.maps.height, "So_long", true);
	if (!game.mlx)
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	put_img(&game);
	mlx_image_to_window(game.mlx, game.graph.background, 0, 0);
	letter_to_png(&game);
	mlx_key_hook(game.mlx, keyhook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
