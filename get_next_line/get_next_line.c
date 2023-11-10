/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:43:18 by brclemen          #+#    #+#             */
/*   Updated: 2023/11/10 15:59:01 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_clear(char *str)
{
	char	*next;
	size_t index;

	index = 0;
	next = NULL;
	while (str[index] && str[index] != '\n')
		index++;
	if (str[index] == '\n')
		index++;
	next = ft_strjoin(next, &str[index]);
	free(str);
	return (next);
}

void	ft_extraire(char *reserve, char *ligne)
{
	size_t	index;

	index = 0;
	if (!reserve)
		return ;
	while (reserve[index] && reserve[index] != '\n')
		index++;
	ligne = malloc(sizeof(char) * (index + 2));
	if (!ligne)
		return ;
	index = 0;
	while(reserve[index] && reserve[index] != '\0')
	{
		ligne[index] = reserve[index];
		index++;
	}
	if (reserve[index] == '\n')
		ligne[index] = reserve[index];
	free(ligne);
}

int	ft_read(int fd, char *str)
{
	char	*tmp;
	int	i;
	
	tmp = str;
	tmp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp)
		return (0);
	i = read(fd, tmp, BUFFER_SIZE);
	free(tmp);
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*reserve;
	char	*ligne;
	int count_read; // train
	reserve = NULL;
	ligne = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	count_read = ft_read(fd, reserve);
	if (!reserve)
		return (NULL);
	if (ft_strchr(reserve, '\n') != NULL)
	{
		ligne = malloc(sizeof(char) * (count_read + 1));
		ft_extraire(reserve, ligne);
		reserve = ft_clear(reserve);
	}
	return (ligne);
}