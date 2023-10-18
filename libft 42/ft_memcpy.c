/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:31:26 by brclemen          #+#    #+#             */
/*   Updated: 2023/10/17 17:56:19 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tempdest;
	unsigned char	*tempsource;
	size_t			index;

	tempdest = (unsigned char *)dest;
	tempsource = (unsigned char *)src;
	index = 0;
	while (n > index)
	{
		tempdest[index] = tempsource[index];
		index++;
	}
	return (dest);
}
