#include <stdlib.h>
#include <stdio.h>

int ft_atoi(const char *src )
{
    int sign;
    int resultat;
    int compteur;

    compteur = 0;
    while(src[compteur] && src[compteur] >= 1 && src[compteur] <= 32)
            compteur++;

    sign = 1;
    while(src[compteur] == '-')
    {                                                   // char nb = "-9065" //
        sign *= (-1);                                   // int nb = -9065 <- char nb ="-9065" - 9006050 //
        compteur++;
    }

    resultat = 0;
    while(src[compteur] && src[compteur] >= '0' && src[compteur] <= '9')
    {
        resultat = resultat * 10 + (src[compteur] - '0'); // exemple 12345 / resultat = 1//
        compteur++;                                                       // resultat = 12 / explication : resultat = resultat(1) * 10 (donc 10) + src[compteur] (plus le chiffre se    trouvant actuellement dans cette itération a l'emplacement compteur donc 2 puis - 0, le 2 est en ascii donc 50(2) - 48(0) pour avoir le deux en integre ce qui donne le résultat escompté)//
    }
    return (resultat *= sign);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Utilisation : %s <chaine_a_convertir>\n", argv[0]);
        return 1;
    }

    const char *input = argv[1];
    int resultat = ft_atoi(input);

    printf("La conversion de \"%s\" donne : %d\n", input, resultat);

    return 0;
}