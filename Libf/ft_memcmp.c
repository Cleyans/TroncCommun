#include <stdio.h>
#include <string.h>

int ft_memcmp(const void *s1, const void *s2, size_t nb)
{
    unsigned const char *strS1 = (unsigned const char *)s1;
    unsigned const char *strS2 = (unsigned const char *)s2;
    
    int i;
    i = 0;
    while (i < nb) {
        if (*strS1 != *strS2) {
            return (*strS1 - *strS2);
        }
        strS1++;
        strS2++;
    }
    return 0;
}

int main() {
    unsigned char bloc1[5] = {0x01, 0x02, 0x03, 0x04, 0x07};
    unsigned char bloc2[5] = {0x01, 0x02, 0x03, 0x04, 0x05};

    size_t taille = (sizeof bloc1);

    int resultat = memcmp(bloc1, bloc2, taille);

    if (resultat == 0) {
        printf("Les blocs de mémoire sont identiques.\n");
    } else if (resultat < 0) {
        printf("Le premier bloc de mémoire est inférieur au second.\n");
    } else {
        printf("Le premier bloc de mémoire est supérieur au second.\n");
    }

    return 0;
}