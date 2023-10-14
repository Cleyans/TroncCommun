#include <stdio.h>

char *ft_strchr(const char *string, int caractereRecherche) {
    while (*string != '\0') {
        if (*string == caractereRecherche) {
            return (char *)string; //char * permet en gros de renvoyer une chaine modifiable, mais faut faire gaffe si vous utiliser cette fonction que de base votre variable et modifiable ou pas
        }
        string++;
    }
    if (caractereRecherche == '\0') {
        return (char *)string; 
    }
    return NULL;
}

/*
int main() {
    const char *str = "Hello, World!";
    char c = 'o';
    char *result = my_strchr(str, c);

    if (result != NULL) {
        printf("'%c' a été trouvé à la position : %ld\n", c, result - str);
    } else {
        printf("'%c' n'a pas été trouvé dans la chaine.\n", c);
    }

    return 0;
}
*/