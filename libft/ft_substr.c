/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:46:02 by brclemen          #+#    #+#             */
/*   Updated: 2023/10/19 14:46:07 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (sub != NULL)
	{
		i = 0;
		if (start < (size_t)ft_strlen(s))
		{
			while (i < len && s[start] != '\0')
			{
				sub[i] = s[start];
				i++;
				start++;
			}
		}
		sub[i] = '\0';
	}
	return (sub);
}
