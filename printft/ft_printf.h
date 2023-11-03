/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:12:58 by brclemen          #+#    #+#             */
/*   Updated: 2023/11/03 21:41:26 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);
void	ft_putchar(char c, size_t *index);
void	ft_format(va_list args, char *str, size_t *index);
void	ft_putstr(char *str, size_t *index);
void	ft_putint(int nb, size_t *index);
void	ft_putpercent(size_t *index);
void	ft_printstr(char *str, size_t *index);
void	ft_putunsigned(unsigned int nb, size_t *index);
void	ft_print_hex(unsigned int nb, char format, size_t *index);
void	ft_print_ptr(unsigned long nb, size_t *index);
int		nbdigit(int n);
int		ft_printf(const char *str, ...);

#endif