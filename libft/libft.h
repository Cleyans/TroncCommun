/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:42:00 by brclemen          #+#    #+#             */
/*   Updated: 2023/10/23 13:40:37 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

void	ft_bzero(void *s, size_t n); // Remplit n octets de mémoire pointée par s avec des zéros. //
int		ft_isalnum(int c); // Vérifie si le caractère c est alphanumérique (lettre ou chiffre). //
int		ft_isalpha(int c); // Vérifie si le caractère c est une lettre de l'alphabet. //
int		ft_isascii(int c); // Vérifie si le code ASCII de c est compris entre 0 et 127 (caractère ASCII valide). //
int		ft_isdigit(int c); // Vérifie si le caractère c est un chiffre. //
int		ft_isprint(int c); // Vérifie si le caractère c est imprimable (affichable à l'écran). //
int		ft_atoi(const char *nptr); // Convertit une chaîne de caractères en un entier (int). //
char	*strdup(const char *s); // Crée une copie allouée dynamiquement de la chaîne s. //
char **ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);  // Renvoie une sous-chaîne extraite de s, à partir de l'indice start et d'une longueur len. //
void	*ft_calloc(size_t nmemb, size_t size); // Alloue de la mémoire pour un tableau de nmemb éléments, chacun de taille size octets, et initialise la mémoire allouée à zéro. //
void	*ft_memcpy( void *dest, const void *src, size_t n); // Copie n octets de mémoire source src vers la mémoire de destination dest. //
void	*ft_memmove(void *dest, const void *src, size_t n); // Copie n octets depuis la mémoire source src vers la mémoire de destination dest, gérant les chevauchements. //
void	*ft_memset(void *s, int c, size_t n); // Remplit n octets de mémoire pointée par s avec la valeur c. //
void	*ft_memchr(const void *s, int c, size_t n); // Recherche le caractère c dans les n premiers octets de la mémoire pointée par s et renvoie un pointeur vers la première occurrence. //
int		ft_memcmp(const void *s1, const void *s2, size_t n);  // Compare les n premiers octets des mémoires pointées par s1 et s2. //
char	*ft_strchr(const char *s, int c); // Recherche la première occurrence du caractère c dans la chaîne s. //
char	*ft_strnstr(const char *big, const char *little, size_t len); // Recherche la première occurrence de la sous-chaîne little dans la chaîne big, limitée aux premiers len caractères. //
size_t	ft_strlcat(char *dst, const char *src, size_t size); // Concatène la chaîne src à la fin de la chaîne dst, garantissant que la chaîne résultante tient dans une zone mémoire de taille size. //
size_t	ft_strlcpy(char *dst, const char *src, size_t size);  // Copie au plus size - 1 caractères de la chaîne src dans la chaîne dst, en s'assurant que dst est null-terminée. //
size_t		ft_strlen(const char *s); // Calcule la longueur de la chaîne de caractères s. //
char    *ft_strtrim(char const *s1, char const *set);
char	*ft_strdup(const char *s); // Crée une copie allouée dynamiquement de la chaîne s. //
int		ft_strncmp( const char *s1, const char *s2, size_t n); // Compare les n premiers caractères de deux chaînes s1 et s2. //
char	*ft_strrchr(const char *s, int c); // Recherche la dernière occurrence du caractère c dans la chaîne s. //
char *ft_strjoin(const char *s1, const char *s2); // Concatène les chaînes s1 et s2 pour former une nouvelle chaîne. //
int		ft_tolower( int c); // Convertit un caractère en minuscule s'il est alphabétique, en laissant les autres caractères inchangés. //
int		ft_toupper( int c); // Convertit un caractère en majuscule s'il est alphabétique, en laissant les autres caractères inchangés. //

#endif
