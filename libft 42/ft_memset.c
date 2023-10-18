/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:02:01 by brclemen          #+#    #+#             */
/*   Updated: 2023/10/17 11:33:20 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *string, int valeur, size_t nombre)
{
	char	*temp;
	int		index;

	temp = (unsigned char *)string;
	index = 0;
	while (nombre > index)
	{
		*temp = (unsigned char)valeur;
		temp++;
		index++;
	}
	return (string);
}