/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:30:44 by brclemen          #+#    #+#             */
/*   Updated: 2023/10/23 11:32:24 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"  

char	*ft_strrchr(const char *string, int recherche)
{
	const char	*dernier;
	size_t		index;

	dernier = NULL;
	index = 0;
	if ((char)recherche == '\0')
	{
		while (string[index])
			index++;
		return ((char *)&string[index]);
	}
	while (string[index])
	{
		if (string[index] == (char)recherche)
			dernier = &string[index];
		index++;
	}
	return ((char *)dernier);
}
