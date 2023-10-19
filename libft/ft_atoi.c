/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:36:59 by brclemen          #+#    #+#             */
/*   Updated: 2023/10/18 14:37:01 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	size_t	index;
	int		sign;
	int		result;

	index = 0;
	sign = 1;
	result = 0;
	while (nptr[index] == '-' || nptr[index] == '+')
	{
		if (nptr[index] == '-')
		{
			sign *= -1;
		}
		index++;
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		result = result * 10 + (nptr[index] - '0');
		index++;
	}
	return (result * sign);
}
