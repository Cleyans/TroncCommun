void *ft_memset(void *string, int valeur, size_t taille)
{
    unsigned char *temp = (unsigned char *)string;
    size_t compteur = 0;

    while (i < taille)
    {
        *temp = (unsigned char)valeur;
        ++temp;
        ++compteur
    }
    return string;
}

