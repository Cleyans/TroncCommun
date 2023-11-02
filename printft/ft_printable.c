/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:03:09 by brclemen          #+#    #+#             */
/*   Updated: 2023/11/02 17:03:12 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putchar(char c, size_t *index)
{
	write(1, &c, 1);
	(*index)++;
}

void ft_putpercent(size_t *index)
{
	ft_putchar('%', index);
}

void ft_putstr(char *str, size_t *index)
{
	int i;

	i = 0;
	while(str[i])
	{
		ft_putchar(str[i], index);
		i++;
	}
}