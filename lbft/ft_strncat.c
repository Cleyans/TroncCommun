#include <string.h>

char *ft_strncat(const char *src, char *dest, size_t size)
{
    size_t     i;
    size_t     lenght;

    i = 0;
    lenght = 0;

    while (dest[lenght])
        lenght++;
    
    while (src[i] != '\0' && (lenght + i) <= size)
    {
        dest[lenght + i] = src[i];
        i++;
    }
    dest[lenght + i] = '\0';
    return dest;
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    char dest[20] = "Hello, ";
    const char *src = "world!";
    size_t size = 7;

    printf("Before ft_strncat: dest = \"%s\"\n", dest);

    ft_strncat(dest, src, size);

    printf("After ft_strncat: dest = \"%s\"\n", dest);

    return 0;
}
*/