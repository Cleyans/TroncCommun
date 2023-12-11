/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:08:33 by brclemen          #+#    #+#             */
/*   Updated: 2023/12/11 16:34:23 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_game *game)
{
	char	*str;
	int		i;

	i = 0;
	game->maps.fd = open("./maps/map.ber", O_RDONLY);
	str = get_next_line(game->maps.fd);
	game->maps.count_lenght = ft_strlen(str) - 1;
	while (1)
	{
		str = get_next_line(game->maps.fd);
		if (str == NULL)
			break ;
		i++;
	}
	close(game->maps.fd);
	game->maps.count_height = i + 1;
	game->maps.map = (char **)malloc(sizeof(char *) * (i + 1));
	read_map_next(game, str);
}

void	read_map_next(t_game *game, char *str)
{
	int	i;

	game->maps.fd = open("./maps/map.ber", O_RDONLY);
	i = 0;
	while (1)
	{
		str = get_next_line(game->maps.fd);
		if (str == NULL)
			break ;
		game->maps.map[i] = str;
		i++;
	}
	free(str);
	game->maps.map[i] = NULL;
	close(game->maps.fd);
}
