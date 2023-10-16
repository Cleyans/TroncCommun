/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:20:39 by brclemen          #+#    #+#             */
/*   Updated: 2023/10/16 15:20:42 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_bzero(void *source, size_t nombre)
{
	char	*temp;
	int		index;

	temp = (unsigned char *)source;
	index = 0;
	while (nombre > index)
	{
		*temp = 0;
		temp++;
		index++;
	}
}
