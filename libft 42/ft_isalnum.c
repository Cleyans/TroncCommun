/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:08:55 by brclemen          #+#    #+#             */
/*   Updated: 2023/10/16 14:09:02 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_isalnum(int character)
{
	if (character >= 48 && character <= 57 || character >= 65 && character <= 90
		|| character >= 97 && character <= 122)
		return (1);
	return (0);
}
