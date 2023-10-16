/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:38:53 by brclemen          #+#    #+#             */
/*   Updated: 2023/10/16 15:38:55 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"
#include <string.h>

void *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char *strDestination = (unsigned char *)dest;
    unsigned char *strSource = (unsigned char *)src;

    if (strSource < strDestination && strDestination < strSource + n) {
        strDestination += n;
        strSource += n;
        while (n--) {
            *(--strDestination) = *(--strSource);
        }
    }

    else {
        while (n--) {
            *strDestination++ = *strSource++;
        }
    }

    return dest;
}

int main(void)
{
    char source[] = "Hello, world!";
    char destination[20] = "Kevin le suceur";

    printf("Contenu initial de la destination : %s\n", destination);

    size_t longueursource = strlen(source) + 1;
    ft_memmove(destination, source, longueursource);

     printf("Contenu de la destination après memcpy : %s\n", destination);

     return 0;
}
