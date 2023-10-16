/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:02:01 by brclemen          #+#    #+#             */
/*   Updated: 2023/10/16 15:02:06 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	*ft_memset(void *string, int valeur, size_t nombre)
{
	char	*temp;
	int		index;

	temp = (unsigned char *)string;
	index = 0;
	while (nombre > index)
	{
		*temp = (unsigned char)valeur;
		temp++;
		index++;
	}
	return (*temp);
}
