/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:38:30 by brclemen          #+#    #+#             */
/*   Updated: 2023/10/23 17:18:52 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
 // AHAH j'ai hâte.. //

#include <stdio.h>
#include <string.h>

static int digit(int n)
{
    int count;
    
    count = 0;
    if (n < 0 && n > -2147483647)
    {
        count++;
        n = -n;
    }
    else if (n == 0)
        return (1);
    while (n >= 1)
    {
        n /= 10;
        count++;
    }
    return (count);
}
static char *convertion(int n, int count)
{
    char *string;
    int index;
    int index2;
    
    index = 0;
    index2 = count - 1;
    string = (char *)malloc(sizeof(char) * (count + 1));
    if (!string)
        return (NULL);
    string[count] = '\0';
    if (n < 0)
    {
      n = -n;
      string[0] = '-';
      count = count -1;
    }
    while (count > 0)
    {
        if (n >= 0)
        {
            string[index2 - index] = n % 10 + 48;
            n = n / 10;
        }
        else
            string[index2 - index] = n + 48;
        count--;
        index++;
    }
    return (string);
}

char *ft_itoa(int n) 
{
    int nlen;
    char *resultat;

    if (n == -2147483648)
    {
        resultat = malloc(12);
        if (resultat)
            ft_strlcpy(resultat, "-2147483648", 12);
    }
    else
    {
        nlen = digit(n);
        resultat = convertion(n, nlen);
    }
    
    return resultat;
}