/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:08:42 by brclemen          #+#    #+#             */
/*   Updated: 2023/12/15 16:22:47 by brclemen         ###   ########.fr       */
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

void	free_map(t_game *game)
{
	int	height;

	height = 0;
	while (height < game->maps.h)
	{
		free(game->maps.map[height]);
		height++;
	}
	free(game->maps.map);
	mlx_delete_image(game->mlx, game->graph.background);
	mlx_delete_texture(game->texture.background_texture);
	mlx_delete_image(game->mlx, game->graph.person);
	mlx_delete_texture(game->texture.person_texture);
	mlx_delete_image(game->mlx, game->graph.collect);
	mlx_delete_texture(game->texture.collect_texture);
	mlx_delete_image(game->mlx, game->graph.exit);
	mlx_delete_texture(game->texture.exit_texture);
	mlx_delete_image(game->mlx, game->graph.walls);
	mlx_delete_texture(game->texture.walls_texture);
}

int32_t	main(int argc, char **argv)
{
	t_game	game;

	if (argc > 2)
	{
		ft_printf("You have more than two arguments.\n");
		return (0);
	}
	var_ini(&game);
	game.maps.chosen_file = argv[1];
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
	free_map(&game);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
