#include <stdio.h>

char *ft_strchr(const char *string, int caractereRecherche) {
    char *resultat = NULL;
    while (*string != '\0') {
        if (*string == caractereRecherche) {
            resultat = (char *)string; //char * permet en gros de renvoyer une chaine modifiable, mais faut faire gaffe si vous utiliser cette fonction que de base votre variable et modifiable ou pas
        }
        string++;
    }
    if (caractereRecherche == '\0') {
        return (char *)string; 
    }
    return resultat;
}

/*
Exemple
string [Hello]
c = 'l'

H
He
Hel : resultat = string[2];
Hell : resultat = string[3];
Hello
*/