/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:26:51 by brclemen          #+#    #+#             */
/*   Updated: 2023/11/03 17:34:45 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putint(int nb, size_t *index)
{
	char	*temp;

	temp = ft_itoa(nb);
	ft_putstr(temp, index);
	free(temp);
}

void	ft_putunsigned(unsigned int nb, size_t *index)
{
	char	*temp;

	if (nb == 0)
	{
		write(1, "0", 1);
		(*index)++;
	}
	else
	{
		temp = ft_utoa(nb);
		ft_putstr(temp, index);
		free(temp);
	}
}
