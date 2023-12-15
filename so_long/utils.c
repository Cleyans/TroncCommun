/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:21:06 by brclemen          #+#    #+#             */
/*   Updated: 2023/12/15 12:20:27 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	strlen_new_line(char *str)
{
	int	index;

	index = 0;
	while (str[index] && str[index] != '\n')
		index++;
	return (index);
}

int	strlen_verif_one(char *str)
{
	int	index;

	index = 0;
	while (str[index] && str[index] == '1')
		index++;
	if (strlen_new_line(str) == index)
		return (1);
	return (0);
}

void	verif_close(t_game *game)
{
	ft_printf("Your map are not available, it is not closed.\n");
	mlx_close_window(game->mlx);
}
