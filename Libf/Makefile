#include <string.h>
#include <stdio.h>

int strcmp(const char *first, const char *second)
{

    while (*first && *second && *first == *second)
    {
        first++;
        second++;
    }

    return (first - second);
}


#include <string.h>


int strcmp(const char *first, const char *second)
{
    int compteur_first;
    int compteur_second;
    int resultat;

    compteur_first = 0;
    compteur_second = 0;
    while (first[compteur_first] || second[compteur_second])
    {
        compteur_first++;
        compteur_second++;
    }

    int resultat = (compteur_first - compteur_second);

    if (resultat == 0)
        return NULL;
    return (resultat);
}