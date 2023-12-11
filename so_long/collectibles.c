/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:56:22 by brclemen          #+#    #+#             */
/*   Updated: 2023/12/11 16:41:32 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(t_game *game)
{
	if (game->exit == 0 && game->maps.map[game->player.player_height]
		[game->player.player_lenght] == 'E')
		mlx_close_window(game->mlx);
}

void	collects(t_game *game, int y, int x)
{
	int	index;

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
