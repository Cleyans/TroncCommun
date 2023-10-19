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
	size_t			index;

	source = (unsigned char *)s;
	index = 0;
	while (source[index] && n > 0)
	{
		if (source[index] == c)
			return ((unsigned char *)source + index);
		n--;
	}
	return (NULL);
}
