/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:26:10 by brclemen          #+#    #+#             */
/*   Updated: 2023/12/05 14:57:53 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strchr_gnl(const char *s, char c)
{
    unsigned int    i;
    if (!s)
        return (-1);
    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
            return (i);
        i++;
    }
    if (s[i] == c)
        return (i);
    return (-1);
}

unsigned int    ft_strlen_gnl(const char *str)
{
    unsigned int    num;
    if (!str)
        return (0);
    num = 0;
    while (str[num] != '\0')
        num++;
    return (num);
}

char    *ft_strdup_gnl(const char *s1)
{
    unsigned int    size;
    char            *ptr;
    int             i;
    size = ft_strlen_gnl(s1);
    ptr = malloc((size + 1) * sizeof(char));
    if (!ptr)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        ptr[i] = s1[i];
        i++;
    }
    ptr[i] = '\0';
    return (ptr);
}

char    *ft_strjoin_gnl(char *s1, char const *s2)
{
    char    *string;
    size_t  i;
    size_t  x;
    if (!s1)
        s1 = ft_strdup("");
    string = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
    if (!string)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        string[i] = s1[i];
        i++;
    }
    x = 0;
    while (s2[x])
        string[i++] = s2[x++];
    string[i] = 0;
    free(s1);
    return (string);
}
