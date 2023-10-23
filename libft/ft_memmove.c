/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:38:53 by brclemen          #+#    #+#             */
/*   Updated: 2023/10/23 11:30:49 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*strdestination;
	unsigned char	*strsource;

	strdestination = (unsigned char *)dest;
	strsource = (unsigned char *)src;
	if (strdestination == NULL && strsource == NULL)
		return (NULL);
	if (strsource < strdestination && strdestination < strsource + n)
	{
		strdestination += n;
		strsource += n;
		while (n--)
			*(--strdestination) = *(--strsource);
	}
	else
	{
		while (n--)
		{
			*strdestination++ = *strsource++;
		}
	}
	return (dest);
}
