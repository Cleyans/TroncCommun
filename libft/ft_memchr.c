/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:30:32 by brclemen          #+#    #+#             */
/*   Updated: 2023/10/18 11:30:37 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*source;
	unsigned char	caractere;
	size_t			index;

	caractere = (unsigned char)c;
	source = (unsigned char *)s;
	index = 0;
	if (caractere == '\0')
	{
		while (source[index])
			index++;
		return (void *)(source + index);
	}
	while (source[index] && index < n)
	{
		if (source[index] == caractere)
			return (void *)(source + index);
		index++;
	}
	return (NULL);
}
