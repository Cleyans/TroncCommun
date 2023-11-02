/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:22:29 by brclemen          #+#    #+#             */
/*   Updated: 2023/11/02 17:04:47 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(va_list va, char *str, size_t *index)
{
	if (*str == 'c')
		ft_putchar(va_arg(va, int), index);
	else if (*str == 's')
		ft_putstr(va_arg(va, char *), index);
	else if (*str == 'i' || *str == 'd')
		ft_putint(va_arg(va, int), index);
	else if (*str == '%')
		ft_putpercent(index);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	index;

	index = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_format(args, (char *)str, &index);
		}
		else
			ft_putchar(*str, &index);
		str++;
	}
	va_end(args);
	return (index);
}