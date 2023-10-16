/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:43:56 by brclemen          #+#    #+#             */
/*   Updated: 2023/10/16 16:29:06 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strlcpy(char *destination, const char *source, size_t taille)
{
	int	indexdest;
	int	index;

	indexdest = ft_strlen(destination);
	index = 0;
	while (source[index] != '\0'
		&& destination[indexdest + index + 1] < taille)
	{
		destination[indexdest + index] = source[index];
	}
	destination[indexdest + index] = '\0';
	return (*destination);
}

/*
int main(void) {
    char destination[10] = "This and ";
    char source[5] = "that";
    size_t taille = 15;

    printf("Avant destination : %s\n", destination);
    printf("Avant source : %s\n", source);

    char result[15];
    *result = ft_strlcpy(destination, source, taille);

    printf("Apres utilisation de la fonction : %s\n", result);

    return (0);
}
*/
