#include <string.h>
#include <stdio.h>

int ft_strcmp(const char *first, const char *second)
{

    while (*first && *second && *first == *second)
    {
        first++;
        second++;
    }

    return (*first - *second);
}

int main() 
{
    const char *str1 = "Bonjourrr";
    const char *str2 = "Bonjour";

    int result1 = ft_strcmp(str1, str2);
    
    if (result1 == 0) {
        printf("%s et %s sont identiques.\n", str1, str2);
    } else if (result1 < 0) {
        printf("%s est inférieure à %s.\n", str1, str2);
    } else {
        printf("%s est supérieure à %s.\n", str1, str2);
    }
    return 0;
}
