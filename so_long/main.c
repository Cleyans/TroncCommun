/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:08:42 by brclemen          #+#    #+#             */
/*   Updated: 2023/12/07 15:23:04 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx42.h"
#include "so_long.h"

static void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t	main(void)
{
	game_t	game;

	lecturemap(&game);
	game.maps.longueur = game.maps.count_l * 64;
	game.maps.hauteur = game.maps.count_h * 64;
	if (!(game.mlx = mlx_init(game.maps.longueur, game.maps.hauteur, "So_long", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	affiche_img(&game);
	mlx_image_to_window(game.mlx, game.graph.background, 0, 0); 
	letter_to_png(&game);
	mlx_key_hook(game.mlx, keyhook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}