/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:43:23 by brclemen          #+#    #+#             */
/*   Updated: 2023/11/13 16:50:01 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	index;

	if (!str)
		return (0);
	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_strjoin(char *stash, char *buff)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!stash)
	{
		stash = (char *)malloc(1 * sizeof(char));
		stash[0] = '\0';
	}
	if (!stash || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(stash) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (stash)
		while (stash[++i] != '\0')
			str[i] = stash[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(stash) + ft_strlen(buff)] = '\0';
	free(stash);
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strcpyy(char *dst, const char *src)
{
	int		i;

	i = 0;
	while (src[i] && src[i] != '\n')
	{
		dst[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
	{
		dst[i] = '\n';
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
