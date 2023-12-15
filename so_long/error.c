/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:56:25 by brclemen          #+#    #+#             */
/*   Updated: 2023/12/15 13:23:57 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(t_game *game)
{
	if (game->maps.count_p != 1)
	{
		ft_printf("Your map are not available,\
not the exact amount of player wished.\n");
		mlx_close_window(game->mlx);
	}
	if (game->maps.count_e != 1)
	{
		ft_printf("Your map are not available,\
not the exact amount of exit wished.\n");
		mlx_close_window(game->mlx);
	}
	if (game->count_c < 1)
	{
		ft_printf("Your map are not available,\
you don't have enought colletibles\n");
		mlx_close_window(game->mlx);
	}
}

void	error_rectangle(t_game *game)
{
	int	height;

	height = 0;
	while (height != game->maps.h)
	{
		if (height != game->maps.h - 1)
		{
			if (strlen_new_line(game->maps.map[height])
				!= strlen_new_line(game->maps.map[height + 1]))
			{
				ft_printf("Your map are not available, it is not rectangle.\n");
				mlx_close_window(game->mlx);
				break ;
			}
		}
		height++;
	}
}

void	one_all_around(t_game *game)
{
	int	height;
	int	max_lenght;

	height = 1;
	if (strlen_verif_one(game->maps.map[0]) != 1)
	{
		verif_close(game);
		return ;
	}
	if (strlen_verif_one(game->maps.map[game->maps.h - 1]) != 1)
	{
		verif_close(game);
		return ;
	}
	max_lenght = strlen_new_line(game->maps.map[height]);
	while (height != game->maps.h - 1)
	{
		if (game->maps.map[height][0] != '1'
			|| game->maps.map[height][max_lenght - 1] != '1')
		{
			verif_close(game);
			return ;
		}
		height++;
	}
}
// void	verif_path(t_game *game)
// {
	
// }

void	verif_errors_maps(t_game *game)
{
	map_error(game);
	error_rectangle(game);
	one_all_around(game);
}