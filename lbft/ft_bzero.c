#include <stdio.h>

void ft_bzero(void *source, size_t taille) {

    unsigned char *ptr;
    ptr = (unsigned char *)source;

    int i;
    i = 0;
    while( i < taille) {
        ptr[i] = 0;
        i++;
    }
}

int main() {

    unsigned char buffer[10];

    printf("Contenu initial du tableau :\n");
    for (int i = 0; i < 10; i++) {
        printf("%02X ", buffer[i]);
    }
    printf("\n\n");

    size_t n = sizeof(buffer);
    ft_bzero(buffer, n);

    printf("Contenu après l'initialisation avec des zéros :\n");
    for (int i = 0; i < 10; i++) {
        printf("%02X ", buffer[i]);
    }
    printf("\n");

    return 0;
}