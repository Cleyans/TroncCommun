/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:26:51 by brclemen          #+#    #+#             */
/*   Updated: 2023/10/31 15:45:50 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putint(int nb, size_t *index)
{
    char *temp;
    temp = ft_itoa(nb);
    ft_putstr(temp, index);
}

//%u