/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:31:26 by brclemen          #+#    #+#             */
/*   Updated: 2023/10/16 15:31:29 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	*ft_memcpy( void *destination, const void *source, size_t taille)
{
	unsigned char	*tempdest;
	unsigned char	*tempsource;
	size_t			index;

	tempDest = (unsigned char *)destination;
	tempSource = (unsigned char *)source;
	index = 0;
	while (taille > i)
	{
		tempDest[index] = tempSource[index];
		i++;
	}
	return (*tempDest);
}
