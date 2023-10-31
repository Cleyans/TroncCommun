/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:22:29 by brclemen          #+#    #+#             */
/*   Updated: 2023/10/31 16:08:14 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_format(va_list va, char *str, size_t *index)
{
	if (*str == 'c')
		ft_putchar(va_arg(va, int), index);
	else if (*str == 's')
		ft_putstr(va_arg(va, char *), index);
	else if (*str == 'i')
		ft_putint(va_arg(va, int), index);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	index;

	index = 0;
	va_start(args, *str);

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

int	main(void)
{
	char temp = 'a';
	char temp2[10] = "petit test";
	int bitch = 5555555;
	ft_printf("salut'%c'abc'%s'qqqq%i", temp, temp2, bitch);
	write(1, "\n", 1);
	printf("salut'%c'abc'%s'qqqq%i", temp, temp2, bitch);
	write(1, "\n", 1);
	return (0);
}
