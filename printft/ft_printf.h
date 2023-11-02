/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:12:58 by brclemen          #+#    #+#             */
/*   Updated: 2023/10/31 16:05:38 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

void ft_putchar(char c, size_t *index);
int ft_printf(const char *str, ...);
void ft_format(va_list va, char *str, size_t *index);
void ft_putstr(char *str, size_t *index);
void ft_putint(int nb, size_t *index);
void ft_putpercent(size_t *index);
int	nbdigit(int n);
size_t	ft_strlcpy(char *destination, const char *source, size_t taille);
char	*ft_itoa(int n);

#endif
