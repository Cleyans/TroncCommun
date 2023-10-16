#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

char *ft_strdup(const char *src)
{
    char    *dest;
    int     lenght;
    int     i;

    lenght = 0;
    i = 0;
    while (src[lenght])
            lenght++;

    if (!(dest = malloc(sizeof(char) * (lenght + 1))))
        return NULL;

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}