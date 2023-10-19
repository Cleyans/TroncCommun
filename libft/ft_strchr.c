/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:50:30 by brclemen          #+#    #+#             */
/*   Updated: 2023/10/17 13:50:32 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *string, int caractereRecherche)
{
	while (*string != '\0')
	{
		if (*string == caractereRecherche)
		{
			return ((char *)string);
		}
		string++;
	}
	if (caractereRecherche == '\0')
		return ((char *)string);
	return (NULL);
}
