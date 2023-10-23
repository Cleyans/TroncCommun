/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:36:59 by brclemen          #+#    #+#             */
/*   Updated: 2023/10/23 11:27:12 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	index;
	int	resultat;
	int	sign;

	index = 0;
	resultat = 0;
	sign = 1;
	while (str[index] == ' ' || (str[index] >= '\t' && str[index] <= '\r'))
		index++;
	if (str[index] == '-')
	{
		sign = -1;
		index++;
	}
	else if (str[index] == '+')
		index++;
	while (str[index] != '\0')
	{
		if (str[index] >= '0' && str[index] <= '9')
			resultat = resultat * 10 + str[index] - '0';
		else
			break ;
		index++;
	}
	return (sign * resultat);
}
