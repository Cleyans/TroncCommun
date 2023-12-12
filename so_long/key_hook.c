/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:56:35 by brclemen          #+#    #+#             */
/*   Updated: 2023/12/12 12:21:05 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		player_up(game);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		player_down(game);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		player_left(game);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		player_right(game);
}

void	player_up(t_game *game)
{
	int	hauteur;
	int	longueur;

	hauteur = game->player.player_height;
	longueur = game->player.player_lenght;
	if (game->maps.map[hauteur - 1][longueur] == '1')
		return ;
	game->graph.person->instances[0].y -= 64;
	game->player.player_height--;
	game->player.moving++;
	ft_printf("%d\n", game->player.moving);
	collects(game, game->player.player_height, longueur);
	ft_exit(game);
}

void	player_left(t_game *game)
{
	int	hauteur;
	int	longueur;

	hauteur = game->player.player_height;
	longueur = game->player.player_lenght;
	if (game->maps.map[hauteur][longueur - 1] == '1')
		return ;
	game->graph.person->instances[0].x -= 64;
	game->player.player_lenght--;
	game->player.moving++;
	ft_printf("%d\n", game->player.moving);
	collects(game, hauteur, game->player.player_lenght);
	ft_exit(game);
}

void	player_down(t_game *game)
{
	int	hauteur;
	int	longueur;

	hauteur = game->player.player_height;
	longueur = game->player.player_lenght;
	if (game->maps.map[hauteur + 1][longueur] == '1')
		return ;
	game->graph.person->instances[0].y += 64;
	game->player.player_height++;
	game->player.moving++;
	ft_printf("%d\n", game->player.moving);
	collects(game, game->player.player_height, longueur);
	ft_exit(game);
}

void	player_right(t_game *game)
{
	int	hauteur;
	int	longueur;

	hauteur = game->player.player_height;
	longueur = game->player.player_lenght;
	if (game->maps.map[hauteur][longueur + 1] == '1')
		return ;
	game->graph.person->instances[0].x += 64;
	game->player.player_lenght++;
	game->player.moving++;
	ft_printf("%d\n", game->player.moving);
	collects(game, hauteur, game->player.player_lenght);
	ft_exit(game);
}
