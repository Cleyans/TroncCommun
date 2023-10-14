#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>

char                *ft_strcat(const char *src, char *dest);
char                *ft_strchr(const char *string, int searchedChar);
int                 *ft_strcpy(const char *src, char *dest);
char                *ft_strdup(const char *src);
size_t                  ft_strlen(const char *theString);
char                *ft_strncat(const char *src, char *dest, size_t size);
char                *ft_strncpy(const char *src, char *dest, size_t length);
char                *ft_strstr(char *src, char *recherche);
void                *ft_memset(void *string, int valeur, size_t taille);
void                ft_bzero(void *source, size_t taille);
#endif