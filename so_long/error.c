/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:56:25 by brclemen          #+#    #+#             */
/*   Updated: 2023/12/11 16:58:04 by brclemen         ###   ########.fr       */
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

// void    error_rectangle(t_game *game)
// {
//     int size_lenght;
//     int lenght;
//     int height;

//     size_lenght = 0;
//     lenght = 0;
//     height = 0;
//     while (game->maps.map[0][size_lenght])
//         game->maps.map[0][size_lenght]++;
//     while(game->maps.map[height])
//     {
//         if (ft_strlen(&game->maps.map[height][lenght]) != size_lenght)
//         {
//             ft_printf("Erreur : Ta map n'est pas rectangle.\n");
//             mlx_close_window(game->mlx);
//         }
//         height++;
//     }
// }
