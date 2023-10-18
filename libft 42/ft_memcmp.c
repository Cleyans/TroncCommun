/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:03:54 by brclemen          #+#    #+#             */
/*   Updated: 2023/10/18 12:03:56 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*source1;
	const unsigned char	*source2;
	size_t				index;

	source1 = (unsigned char *)s1;
	source2 = (unsigned char *)s2;
	index = 0;
	if (n == 0)
		return (0);
	while (index < n)
	{
		if (source1[index] != source2[index])
			return ((int)source1[index] - source2[index]);
		index++;
	}
	return (0);
}
