/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:19:17 by brclemen          #+#    #+#             */
/*   Updated: 2023/10/18 13:19:18 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	indexbig;
	size_t	indexlittle;

	indexbig = 0;
	indexlittle = 0;
	if (little == NULL)
		return ((char *)big);
	while (little[indexlittle])
	{
		while (little[indexlittle] == big[indexbig + indexlittle]
			&& (indexbig + indexlittle) < len)
		{
			indexlittle++;
			if (little[indexlittle] == '\0')
				return ((char *)big + indexbig);
		}
		indexlittle = 0;
		indexbig++;
	}
	return (NULL);
}
