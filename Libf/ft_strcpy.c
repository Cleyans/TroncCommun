#include <stdio.h>

int *ft_strcpy(const char *src, char *dest)
{
    int i;

    i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (*dest);
}

int main(void)
{
    char src[] = "1234567891011121314151617";
    char dest[20];

    ft_strcpy(src, dest);

    printf("La chaîne copiée est : %s\n", dest);
    return 0;
}