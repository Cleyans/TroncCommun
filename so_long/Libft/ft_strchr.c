/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:50:30 by brclemen          #+#    #+#             */
/*   Updated: 2023/12/05 12:06:00 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	if (!s)
	{
		while (s[index])
			index++;
		return ((char *)&s[index]);
	}
	while (s[index] != '\0')
	{
		if (s[index] == (char)c)
		{
			return ((char *)&s[index]);
		}
		s++;
	}
	if (s[index] == (char)c)
		return ((char *)&s[index]);
	return (NULL);
}
