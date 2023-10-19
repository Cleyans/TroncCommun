/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:04:19 by brclemen          #+#    #+#             */
/*   Updated: 2023/10/19 10:04:21 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*temp;
	size_t	totalsize;

	totalsize = nmemb * size;
	temp = 0;
	if (nmemb == 0 || size == 0)
		return (NULL);
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	temp = malloc(totalsize);
	if (temp == NULL)
		return (NULL);
	ft_bzero(temp, totalsize);
	return (temp);
}
