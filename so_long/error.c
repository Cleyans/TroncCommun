/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:56:25 by brclemen          #+#    #+#             */
/*   Updated: 2023/12/12 14:28:07 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(t_game *game)
{
	if (game->maps.count_p != 1)
	{
		ft_printf("Votre map n'est pas valide, nombre \
invalide de personnage.\n");
		mlx_close_window(game->mlx);
	}
	if (game->maps.count_e != 1)
	{
		ft_printf("Votre map n'est pas valide, nombre invalide de sortie\n");
		mlx_close_window(game->mlx);
	}
	if (game->count_c < 1)
	{
		ft_printf("Votre map n'est pas valide, aucun collectibles trouvé\n");
		mlx_close_window(game->mlx);
	}
}

int strlen_new_line(char *str)
{
	int index;
	
	index = 0;
	while (str[index] && str[index] != '\n')
		index++;
	return (index);
}

void    error_rectangle(t_game *game)
{

	int	height;

	height = 0;
	while(height != game->maps.h)
	{
		if (height != game->maps.h - 1)
		{
			if (strlen_new_line(game->maps.map[height]) != strlen_new_line(game->maps.map[height + 1]))
			{
				ft_printf("Votre map n'est pas valide, elle n'est rectangle.\n");
				mlx_close_window(game->mlx);
				break ;
			}
		}
	height++;
	}
}

int	strlen_verif_one(char *str)
{
	int index;
	index = 0;
	while (str[index] && str[index] == '1')
		index++;
	if (strlen_new_line(str) == index)
		return (1);
	return (0);
}

void	one_all_around(t_game *game)
{
	int height;
	int max_lenght;

	height = 1;
	if (strlen_verif_one(game->maps.map[0]) != 1)
	{
		verif_close(game);
		return ;
	}
	if (strlen_verif_one(game->maps.map[game->maps.h - 1]) == 0)
	{
		verif_close(game);
		return ;
	}
	max_lenght = 0;
	while (height != game->maps.h - 1)
	{
		max_lenght = strlen_new_line(game->maps.map[height]);
		if (game->maps.map[height][0] == '1' && game->maps.map[height][max_lenght] == '1')
		{
			verif_close(game);
			return ;
		}
		height++;
	}
}

void	verif_close(t_game *game)
{
	ft_printf("Votre map n'est pas valide, elle n'est pas ferme\n");
	mlx_close_window(game->mlx);
}
