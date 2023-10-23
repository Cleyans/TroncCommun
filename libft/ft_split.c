/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:38:05 by brclemen          #+#    #+#             */
/*   Updated: 2023/10/23 11:31:27 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"   // l'enfer sur terre //

static char *extrairemots(const char *s, char c, size_t *start);
static size_t nbmots(const char *s, char c);
char **ft_split(char const *s, char c)  //  Cette fonction divise une chaîne s en un tableau de pointeurs vers des mots en utilisant le caractère c comme délimiteur //
{
    char **tab;
    size_t mots = 0;
    size_t start = 0;

    tab = (char **)malloc(sizeof(char *) * (nbmots(s, c) + 1));
    if (!tab)
        return (NULL);

    while (s[start] != '\0')
    {
        if (s[start] == c)
        {
            start++;
        }
        else
        {
            tab[mots] = extrairemots(s, c, &start);
            if (!tab[mots])
                return (NULL);
            mots++;
        }
    }
    tab[mots] = NULL;
    return tab;
}

static size_t nbmots(const char *s, char c) //  Cette fonction compte le nombre de mots dans une chaîne s en utilisant le caractère c comme délimiteur //
{
    size_t count;
    size_t index;

    count = 0;
    index = 0;
    while (s[index] != '\0')
    {
        if (s[index] != c)
        {
            count++;
            while (s[index] != '\0' && s[index] != c)
                index++;
        }
        else
            index++;
    }

    return count;
}

static char *extrairemots(const char *s, char c, size_t *start) // Cette fonction extrait un mot de la chaîne s en utilisant le caractère c comme délimiteur et renvoie un pointeur vers ce mot //
{
    size_t index;

    index = 0;
    while (s[*start + index] != '\0' && s[*start + index] != c)
        index++;
    char *word = (char *)malloc(index + 1);
    if (!word)
        return NULL;
    ft_strlcpy(word, s + *start, index + 1);
    *start += index;
    return word;
}