#include "libft.h"

void *memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *ptrDestination = (unsigned char *)dest; // permet en grois quand une variable est un void de dire que ptr copie quand même comme ci que c'était un char//
    unsigned char *ptrSource = (unsigned char *)src;

    size_t i;
    i = 0;

    while (i < n)
    {
        ptrDestination[i] = ptrSource[i];
        i++;
    }
    return (dest);
}

#include <stdio.h>
#include <string.h>

int main() {
    char source[] = "Hello, world!";

    char destination[20];

    printf("Contenu initial de la destination : %s\n", destination);

    size_t source_size = strlen(source) + 1;
    memcpy(destination, source, source_size);

    printf("Contenu de la destination après memcpy : %s\n", destination);

    return 0;
}
