/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:12:58 by brclemen          #+#    #+#             */
/*   Updated: 2023/11/07 10:49:30 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

void	ft_putnbr(int n, size_t *index);
void	ft_unsignedputnbr(unsigned int n, size_t *index);
void	ft_putchar(char c, size_t *index);
void	ft_format(va_list args, char *str, size_t *index);
void	ft_putstr(char *str, size_t *index);
void	ft_putpercent(size_t *index);
void	ft_printstr(char *str, size_t *index);
void	ft_print_hex(unsigned long long nb, char format, size_t *index);
void	ft_print_ptr(void *nb, size_t *index);
int		nbdigit(int n);
int		ft_printf(const char *str, ...);

#endif
