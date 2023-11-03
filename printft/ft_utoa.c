/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:38:23 by brclemen          #+#    #+#             */
/*   Updated: 2023/11/03 13:38:23 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	countunsigned(unsigned int nb)
{
	int	count;

	count = 0;
	while (nb >= 1)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

static char	*unsignedconvertion(char *resultat, unsigned int n, int nlen)
{
	int		index;
	int		index2;

	index = 0;
	index2 = nlen - 1;
	while (nlen > 0)
	{
		if (n > 9)
		{
			resultat[index2 - index] = n % 10 + 48;
			n = n / 10;
		}
		else
			resultat[index2 - index] = n + 48;
		nlen--;
		index++;
	}
	return (resultat);
}

char	*ft_utoa(unsigned int n)
{
	int		nlen;
	char	*resultat;

	nlen = countunsigned(n);
	resultat = (char *)malloc(sizeof(char) * (nlen + 1));
	if (!resultat)
		return (NULL);
	resultat[nlen] = '\0';
	resultat = unsignedconvertion(resultat, n, nlen);
	return (resultat);
}
