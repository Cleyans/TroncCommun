
#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *destination, const char *source, size_t taille)
{
	size_t destinationLongueur; // taille de dest
	size_t sourceIndex; // index de source

	if (taille <= ft_strlen(destination)) // si taille est plus petit ou est égale a la taille de dest, bah on return juste la taille de dest plus source pour par la suite pouvoir allouer le bon nombre de mémoire //
		return (taille + ft_strlen(source));
	destinationLongueur = ft_strlen(destination); // on donne la taille de dest
	sourceIndex = 0;
	while (source[sourceIndex] != '\0' && destinationLongueur + 1 < taille) // tant que source[j] n'est pas au caractère NULL et que i(destination) + 1 (caractère NULL) sont inférueur a taille (donc assez de place) on copie source dans destination
	{
		destination[destinationLongueur] = source[sourceIndex]; // on incrémente ensuite le i et le j
		destinationLongueur++;
		sourceIndex++;
	}
	destination[destinationLongueur] = '\0'; // on remet le caracètre NULL
	return (ft_strlen(destination) + ft_strlen(&source[sourceIndex])); // puis on return la longueur totale le (&source[sourceIndex]) permet en gros de dire donne moi la valeur a partir de l'index j donc le reste de source, plus du coup tout se qui a été copié dans destination
}