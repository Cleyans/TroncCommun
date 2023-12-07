/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:08:38 by brclemen          #+#    #+#             */
/*   Updated: 2023/12/07 13:17:11 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	load_png(game_t *game)
{
	game->texture.background_texture = mlx_load_png("assets/decor.png");
	if (!game->texture.background_texture)
		error();
	game->texture.personnage_texture = mlx_load_png("assets/pig.png");
	if (!game->texture.personnage_texture)
		error();
	game->texture.collect_texture = mlx_load_png("assets/tomate.png");
	if (!game->texture.collect_texture)
		error();
	game->texture.walls_texture = mlx_load_png("assets/bush.png");
	if (!game->texture.walls_texture)
		error();
	game->texture.exit_texture = mlx_load_png("assets/sortie.png");
	if (!game->texture.exit_texture)
		error();
}

void	texture_to_image(game_t *game)
{
	game->graph.background = mlx_texture_to_image(game->mlx,
			game->texture.background_texture);
	game->graph.personnage = mlx_texture_to_image(game->mlx,
			game->texture.personnage_texture);
	game->graph.collect = mlx_texture_to_image(game->mlx,
			game->texture.collect_texture);
	game->graph.walls = mlx_texture_to_image(game->mlx,
			game->texture.walls_texture);
	game->graph.exit = mlx_texture_to_image(game->mlx,
			game->texture.exit_texture);
}

void	resize_image(game_t *game)
{
	mlx_resize_image(game->graph.background,
		game->maps.longueur, game->maps.hauteur);
	mlx_resize_image(game->graph.personnage, 64, 64);
	mlx_resize_image(game->graph.collect, 64, 64);
	mlx_resize_image(game->graph.walls, 64, 64);
	mlx_resize_image(game->graph.exit, 64, 64);
}

void	affiche_img(game_t *game)
{
	load_png(game);
	texture_to_image(game);
	resize_image(game);
}
