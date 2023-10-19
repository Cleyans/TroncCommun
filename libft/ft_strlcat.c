/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:49:47 by brclemen          #+#    #+#             */
/*   Updated: 2023/10/19 16:49:58 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	index;
	size_t	destinationlen;

	index = 0;
	destinationlen = 0;
	while (destinationlen < size && dest[destinationlen])
		destinationlen++;
	while (src[index] && (destinationlen + 1) < size)
	{
		dest[destinationlen + index] = src[index];
		index++;
	}
	dest[destinationlen + index] = '\0';
	while (src[index] != '\0')
		index++;
	return (destinationlen + index);
}
