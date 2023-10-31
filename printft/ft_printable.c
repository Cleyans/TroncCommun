/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:13:48 by brclemen          #+#    #+#             */
/*   Updated: 2023/10/31 15:22:41 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void ft_putchar(char c, size_t *index)
{
	write(1, &c, 1);
	(*index)++;
}

void ft_putstr(char *str, size_t *index)
{
	int i;

	i = 0;
	while(str[i])
	{
		ft_putchar(str[i], index);
		i++;
		(*index)++;
	}
}