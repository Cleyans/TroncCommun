#include <string.h>
#include <stdio.h>

char    *ft_strcat( char *dest, const char *src)
{
    int     lenght;
    int     i = 0;

    lenght = 0;
    while (dest[lenght] != '\0')
            lenght++;

    while (src[i] != '\0')
    {
        dest[lenght + i] = src[i];
        i++;
    }
    dest[lenght + i] = '\0';

    return dest;
}

int main(void)
{
    char str1[50] = "Helloeezeze, ";
    char str2[] = "biatchhhhhs!";

    ft_strcat(str1, str2);

    printf("Concatenated string: %s\n", str1);

    return 0;
}