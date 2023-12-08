/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:08:42 by brclemen          #+#    #+#             */
/*   Updated: 2023/12/08 18:14:36 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx42.h"
#include "so_long.h"

static void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	map_error(game_t *game)
{
	if (game->maps.count_p > 1)
	{
		printf("Votre map n'est pas valide, plus d'un personnage dectecte.\n");
		mlx_close_window(game->mlx);
	}
	if (game->maps.count_e > 1)
	{
		printf("Votre map n'est pas valide, plus d'une sortie detecte.\n");
		mlx_close_window(game->mlx);
	}
}

void variable_zero(game_t *game)
{
	game->player.deplacement = 0;
	game->player.nb_collect = 0;
	game->player.player_hauteur = 0;
	game->player.player_longueur = 0;
	game->maps.count_h = 0;
	game->maps.count_l = 0;
	game->maps.count_walls = 0;
	game->count_c = 0;
	game->exit = 1;
	game->maps.count_e = 0;
	game->maps.count_p = 0;
}

void	ft_exit(game_t *game)
{
	if (game->exit == 0 && game->maps.map[game->player.player_hauteur][game->player.player_longueur] == 'E')
		mlx_close_window(game->mlx);
}

void collectibles(game_t *game, int y, int x)
{
	int    index;

    if (!(game->maps.map[y][x] == 'C'))
        return ;
    index = -1;
    while (++index < (int)game->graph.collect->count)
    {
        if (game->graph.collect->instances[index].y / 64 != y)
            continue ;
        if (game->graph.collect->instances[index].x / 64 != x)
            continue ;
        if (!(game->graph.collect->instances[index].enabled))
            continue ;
        game->graph.collect->instances[index].enabled = false;
        game->count_c -= 1;
        if (game->count_c <= 0)
            game->exit = 0;
    }
}

int32_t	main(void)
{
	game_t	game;

	variable_zero(&game);
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
