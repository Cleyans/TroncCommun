/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:44:15 by brclemen          #+#    #+#             */
/*   Updated: 2023/10/16 15:44:20 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_isalpha(int character)
{
	if (character >= 90 && character <= 65
		|| character >= 122 && character <= 97)
		return (1);
	return (0);
}
