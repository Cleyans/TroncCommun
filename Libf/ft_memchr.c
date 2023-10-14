#include <stdio.h>
#include "libft.h"

void *ft_memchr(const void *source, int caractere, size_t nb)
{
    unsigned const char *strSource = (unsigned const char *)source;

    int parcourir;
    parcourir = 0;

    while (parcourir < nb)
    {
        if (strSource[parcourir] == caractere) {
            return (void *)(strSource + parcourir);
        }
        parcourir++;
    }

    return NULL;
}

int main(void) {
    char source[25] = "Bonjour tout le monde";

    printf("%s\n", source);

    void *resultat = ft_memchr(source, 'v', 10);

    if (resultat != NULL) {
        size_t index = (size_t)((unsigned char *)resultat - (unsigned char *)source);
        printf("Le caractère 'v' a été trouvé a la position %zu\n", index);
    }
    else {
        printf("Le caractère 'v' n'a pas été trouvé dans la chaîne.\n");
    }
}