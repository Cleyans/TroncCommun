/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:49:47 by brclemen          #+#    #+#             */
/*   Updated: 2023/10/17 11:33:14 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *destination, char *source, size_t taille)
{
	size_t	index;
	size_t	destinationlen;

	index = 0;
	destinationlen = 0;
	while (destinationlen < taille && destination[destinationlen])
		destinationlen++;
	while (source[index] && (destinationlen + 1) < taille)
	{
		destination[destinationlen + index] = source[index];
		index++;
	}
	destination[destinationlen + index] = '\0';
	while (source[index] != '\0')
		index++;
	return (destinationlen + index);
}
