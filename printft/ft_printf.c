/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:22:29 by brclemen          #+#    #+#             */
/*   Updated: 2023/11/04 10:36:13 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(va_list args, char *str, size_t *index)
{
	if (*str == 'c')
		ft_putchar(va_arg(args, int), index);
	else if (*str == 's')
		ft_printstr(va_arg(args, char *), index);
	else if (*str == 'i' || *str == 'd')
		ft_putint(va_arg(args, int), index);
	else if (*str == '%')
		ft_putpercent(index);
	else if (*str == 'u')
		ft_putunsigned(va_arg(args, unsigned int), index);
	else if (*str == 'x')
		ft_print_hex(va_arg(args, unsigned int), *str, index);
	else if (*str == 'X')
		ft_print_hex(va_arg(args, unsigned int), *str, index);
	else if (*str == 'p')
		ft_print_ptr(va_arg(args, void *), index);
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
