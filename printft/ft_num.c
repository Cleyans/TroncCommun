/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:26:51 by brclemen          #+#    #+#             */
/*   Updated: 2023/10/31 15:45:50 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	nbdigit(int n)
{
	int	count;

	count = 0;
	if (n < 0 && n > -2147483647)
	{
		count++;
		n = -n;
	}
	else if (n == 0)
		return (1);
	while (n >= 1)
	{
		n /= 10;
		count++;
	}
	return (count);
}

void ft_putint(unsigned int nb, size_t *index)
{
    char *temp;
    temp = ft_itoa(nb);
    ft_putstr(temp, index);
}