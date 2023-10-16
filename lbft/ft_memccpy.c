#include <stdio.h>
#include "libft.h"

void *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
    unsigned char *ptrDestination = (unsigned char *)dest;
    unsigned char *ptrSource = (unsigned char *)src;

    size_t i;
    i = 0;

    while (i < n && ptrSource[i] != c)
    {
        ptrDestination[i] = ptrSource[i];
        if (ptrSource[i] == (unsigned char) c)
            return &ptrDestination[i + 1];
        i++;
    }
    return (NULL);
}

int main(void)
{
    char source[] = "Hello, world!";
    char destination[20] = {' '}

    printf("Contenu initial de la destination : %s\n", destination);

    size_t longueursource = strlen(source) + 1;
    ft_memccpy(destination, source, 'l', longueursource);

     printf("Contenu de la destination après memcpy : %s\n", destination);

     return 0;
}