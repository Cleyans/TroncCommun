#include <string.h>

size_t ft_strlen(char *theString)
 {
    int i;

    i = 0;
    while (theString[i] != '\0')
        i++;
    return(i);
 }