/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:46:38 by brclemen          #+#    #+#             */
/*   Updated: 2023/10/17 13:46:42 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	tolower( int character)
{
	if (character > 'a' && character < 'z')
		return (character - 32);
	return (character);
}
