/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:37:17 by brclemen          #+#    #+#             */
/*   Updated: 2023/10/19 15:37:19 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include  "libft.h"

char    *ft_strjoin(const char *s1, const char *s2)
{
    if (s1 == NULL && s2 == NULL)
        return NULL;

    size_t total_len;

    total_len = (ft_strlen(s1) + ft_strlen(s2));
    char *result = (char *)malloc(total_len + 1);

    if (result == NULL)
    {
        return NULL;
    }

    if (s1 != NULL)
    {
        ft_memcpy(result, s1, ft_strlen(s1));
    }

    if (s2 != NULL)
    {
        ft_memcpy(result + ft_strlen(s1), s2, ft_strlen(s2));
    }

    result[total_len] = '\0';
    return result;
}