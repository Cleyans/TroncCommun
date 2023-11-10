/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:43:23 by brclemen          #+#    #+#             */
/*   Updated: 2023/11/10 15:59:02 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (n > i)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*result;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	total_len = (ft_strlen((char *)s1) + ft_strlen((char *)s2));
	result = (char *)malloc(total_len + 1);
	if (result == NULL)
		return (NULL);
	if (s1 != NULL)
		ft_memcpy(result, s1, ft_strlen((char *)s1));
	if (s2 != NULL)
		ft_memcpy(result + ft_strlen((char *)s1), s2, ft_strlen((char *)s2));
	result[total_len] = '\0';
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	if (s == NULL)
	{
		while (s[index])
			index++;
		return ((char *)&s[index]);
	}
	while (s[index] != '\0')
	{
		if (s[index] == (char)c)
		{
			return ((char *)&s[index]);
		}
		s++;
	}
	if (s[index] == (char)c)
		return ((char *)&s[index]);
	return (NULL);
}
