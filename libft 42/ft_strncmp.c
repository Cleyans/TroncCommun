/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:41:05 by brclemen          #+#    #+#             */
/*   Updated: 2023/10/16 15:41:10 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strcmp(const char *chaine1, const char *chaine2)
{
	while (chaine1 && chaine2 && chaine1 == chaine2)
	{
		chaine1++;
		chaine2++;
	}
	return (chaine1 - chaine2);
}
