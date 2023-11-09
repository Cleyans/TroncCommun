/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:43:18 by brclemen          #+#    #+#             */
/*   Updated: 2023/11/09 16:07:31 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
// read, malloc, free
size_t  ft_strlen(char *str)
{
    size_t index;

    index = 0;
    while(str[index])
        index++;
    return (index);
}

int verif_retour(char *str)
{
    size_t index;

    index = 0;
    while(str[index])
    {
        if (str[index] == '\n')
            return (1);
        index++;
    }
    return (0);
}

void    *ligne_save(char *reserve, char *ligne)
{
    size_t index;

    index = 0;
    while (reserve[index] != '\n')
    {
        ligne[index] = reserve[index];
        index++;
    }
    if (reserve[index] == '\n')
    {
        ligne[index] = reserve[index];
        index++;
    }
}

void    clean_ligne(char *str, size_t count)
{
    size_t index;

    index = 0;
    while(count > 0)
    {
        free(str[index]);
        index++;
    }
}

char    *get_next_line(int fd)
{
    static char *reserve;
    char *ligne;
    int retour;

    retour = 0;
    reserve = malloc(sizeof(char *) * BUFFER_SIZE + 1);
    while (retour < 1)
    {
        read(fd, reserve, BUFFER_SIZE);
        retour = verif_retour(reserve);
    }
    ligne_save(reserve, ligne);
    cleanligne(reserve, ft_strlen(reserve) - ft_strlen(ligne));
    return (ligne);
}
