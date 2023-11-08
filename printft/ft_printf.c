/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:22:29 by brclemen          #+#    #+#             */
/*   Updated: 2023/11/08 14:02:56 by brclemen         ###   ########.fr       */
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
		ft_putnbr(va_arg(args, int), index);
	else if (*str == '%')
		ft_putpercent(index);
	else if (*str == 'u')
		ft_unsignedputnbr(va_arg(args, unsigned int), index);
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
int main(void)
{
    char c = 'A';
    char string[] = "Bonjour";
    int integer = 42;
    unsigned int unsignedInteger = 12345;
    int hexadecimal = 12345;
    void *pointer = &integer;

	int res1;
	int res2;

    res1 = printf("string normal %c frer  %s rerer %i  rere %d  rer %u  rer %xre%X re %p ff'%%\n", c, string, integer, integer, unsignedInteger, hexadecimal, hexadecimal, pointer);
	res2 = ft_printf("string normal %c frer  %s rerer %i  rere %d  rer %u  rer %xre%X re %p ff'%%\n", c, string, integer, integer, unsignedInteger, hexadecimal, hexadecimal, pointer);

	printf("printf normal %d \n le mien %d\n", res1, res2);
}