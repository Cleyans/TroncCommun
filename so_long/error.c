/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:56:25 by brclemen          #+#    #+#             */
/*   Updated: 2023/12/18 17:08:31 by brclemen         ###   ########.fr       */
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

void	verif_path(t_game *game)
{
	int	height;
	int lenght;
	int	collect2;
	int exit;

	height = game->player.player_height;
	lenght = game->player.player_lenght;
	collect2 = game->count_c;
	exit = game->exit;
	while (1)
	{
		if (game->maps.map[height][lenght + 1 != '1'])
		{
			while (game->maps.map[height][lenght + 1] != '1')
			{
				lenght++;
				verif_collects(game, height, lenght, &collect2, &exit); // add exit
				game->maps.map[height][lenght] = '1';
			}
			verif_path(game);
		}
		else if (game->maps.map[height + 1][lenght] != '1')
		{
			while (game->maps.map[height + 1][lenght] != '1')
			{
				height++;
				verif_collects(game, height, lenght, &collect2, &exit);
				game->maps.map[height][lenght] = '1';
			}
			verif_path(game);
		}
		else if (game->maps.map[height][lenght - 1] != '1')
		{
			while (game->maps.map[height][lenght - 1] != '1')
			{
				lenght--;
				verif_collects(game, height, lenght, &collect2, &exit);
				game->maps.map[height][lenght] = '1';
			}
			verif_path(game);
		}
		else if (game->maps.map[height - 1][lenght] != '1')
		{
			while (game->maps.map[height - 1][lenght] != '1')
			{
				height--;
				verif_collects(game, height, lenght, &collect2, &exit);
				game->maps.map[height][lenght] = '1';
			}
			verif_path(game);
		}
		else
			break;
	}
	if (collect2 == 0 && exit == 0)
	{
		ft_printf("The map can be played.\n");
		return ;
	}
	else
	{
		ft_printf("The map cannot be played.\n");
		return ;
	}
}

void	verif_collects(t_game *game, int height, int lenght, int *collect2, int *exit)
{
	if (game->maps.map[height][lenght] == 'C')
	{
		collect2--;
		return ;
	}
	else if (game->maps.map[height][lenght] == 'E')
	{
		exit--;
		return ;
	}
	else 
		return ;
}

void	verif_errors_maps(t_game *game)
{
	map_error(game);
	error_rectangle(game);
	one_all_around(game);
	verif_path(game);
}