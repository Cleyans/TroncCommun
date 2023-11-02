#include "libft.h"
#include <string.h>
#include <stdio.h>

void main(void)
{
    char str[21] = "Wallah c'est pas moi";
    char dest[21];

    strncpy(str + 1, str, 10);

    printf("%s\n", str);
}