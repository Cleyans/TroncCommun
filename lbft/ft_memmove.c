// La fonction memmove() copie n octets depuis la zone mémoire src vers la zone mémoire dest. Les deux zones peuvent se chevaucher : la copie se passe comme si les octets de src étaient d'abord copiés dans une zone temporaire qui ne chevauche ni src ni dest, et les octets sont ensuite copiés de la zone temporaire vers dest.  

#include <stdio.h>
#include "libft.h"
#include <string.h>

void *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char *strDestination = (unsigned char *)dest;
    unsigned char *strSource = (unsigned char *)src;

    if (strSource < strDestination && strDestination < strSource + n) {
        strDestination += n;
        strSource += n;
        while (n--) {
            *(--strDestination) = *(--strSource);
        }
    }

    else {
        while (n--) {
            *strDestination++ = *strSource++;
        }
    }

    return dest;
}

int main(void)
{
    char source[] = "Hello, world!";
    char destination[20] = {' '};

    printf("Contenu initial de la destination : %s\n", destination);

    size_t longueursource = strlen(source) + 1;
    ft_memmove(destination, source, longueursource);

     printf("Contenu de la destination après memcpy : %s\n", destination);

     return 0;
}