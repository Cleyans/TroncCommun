/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:43:56 by brclemen          #+#    #+#             */
/*   Updated: 2023/10/23 11:32:08 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *destination, const char *source, size_t taille)
{
	size_t	index;

	index = 0;
	if (taille != 0)
	{
		while (source[index] && taille > 1)
		{
			destination[index] = source[index];
			taille--;
			index++;
		}
		destination[index] = '\0';
	}
	while (source[index] != '\0')
		index++;
	return (index);
}
/*
#include <stdio.h>
#include <string.h>

size_t ft_strlcpy(char *destination, const char *source, size_t taille);

int main() {
    char destination[20];
    const char *source = "Hello, World!";

    size_t result = ft_strlcpy(destination, source, 10);

    printf("Chaîne copiée : %s\n", destination);
    printf("Nombre de caractères copiés : %zu\n", result);

    return 0;
}
*/
