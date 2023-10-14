#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int ft_strncpy(const char *src, char *dest, size_t length)
{
    size_t i = 0;
    while (src[i] != '\0' && i < length)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return i;

}
int main(void)
{
    char src[] = "Hello word";
    char dest[20];

    size_t length = 5;

    ft_strncpy(src, dest, length);

    printf("Voici le contenu de Dest : %s\n", dest);
    return 0;
}