#include <string.h>
#include <stdio.h>

int *ft_strstr(char *src, char *recherche)
{
    int compteur_recherche;
    int compteur_src;

    compteur_src = 0;
    while (src[compteur_src])
    {
        compteur_recherche = 0;
            while (recherche[compteur_recherche] == src[compteur_src + compteur_recherche])  /* dans la source on met le compteur recherche également car sinon il n'avance pas a la même vitesse que recherche*/
            {
                if (recherche[compteur_recherche + 1] == '\0')
                    return (src + compteur_src);
                compteur_recherche++;
            }
        compteur_src++;
    }
    return recherche;
}

int main() {
    const char *haystack = "Bonjour, c'est un exemple de recherche.";
    const char *needle = "exemple";

    char *result = ft_strstr(haystack, needle);

    if (result != NULL) {
        printf("Sous-chaîne trouvée : %s\n", result);
    } else {
        printf("Sous-chaîne non trouvée.\n");
    }

    return 0;
}