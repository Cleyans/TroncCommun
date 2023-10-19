/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:30:44 by brclemen          #+#    #+#             */
/*   Updated: 2023/10/17 14:30:48 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *string, int recherche)
{
	const char	*dernier;

	dernier = NULL;
	while (*string != '\0')
	{
		if (*string == recherche)
			dernier = string;
		string++;
	}
	return ((char *)dernier);
}
