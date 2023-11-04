/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:26:09 by brclemen          #+#    #+#             */
/*   Updated: 2023/11/02 22:26:09 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//HEX

static void	ft_hex_conversion(unsigned long nb, char *hex_base, size_t *index)
{
	if (nb / 16)
		ft_hex_conversion(nb / 16, hex_base, index);
	ft_putchar(hex_base[nb % 16], index);
}

void	ft_print_hex(unsigned int nb, char format, size_t *index)
{
	char	*hex_base;

	hex_base = "0123456789abcdef";
	if (format == 'X')
		hex_base = "0123456789ABCDEF";
	ft_hex_conversion(nb, hex_base, index);
}
//PTR

static void	ft_ptr_conversion(unsigned long nb, char *hex_base, size_t *index)
{
	if (nb / 16)
		ft_hex_conversion(nb / 16, hex_base, index);
	ft_putchar(hex_base[nb % 16], index);
}

void	ft_print_ptr(void *nb, size_t *index)
{
	char				*hex_base;
	unsigned long		nb2;

	nb2 = (unsigned long)nb;
	if (nb == 0)
		ft_putstr("(nil)", index);
	else
	{
		hex_base = "0123456789abcdef";
		ft_putstr("0x", index);
		ft_ptr_conversion(nb2, hex_base, index);
	}
}
