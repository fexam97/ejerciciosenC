#include <stdio.h>
#include <stdlib.h>
#include <string.h>


size_t mstrlen(const char *cadena);
char *mstrcpy(char *destino, const char *origen);
char *mstrchr(char *cadena, int c);
char *mstrcat(char *destino, const char *origen);


int main()
{
    char cadena1[] = "Hola mundo";
    char cadena2[] = "boquita el mas grande";

    printf("\n ******** SIN USAR LA BIBLIOTECA STRING ***********");

    printf("\n %d", mstrlen(cadena1));
    printf("\n %s", mstrcpy(cadena1, cadena2));
    printf("\n %d", mstrchr(cadena1, 7));
    printf("\n %s", mstrcat(cadena1, cadena2));

    printf("\n\n ******** USANDO LA BIBLIOTECA STRING *************");

    printf("\n %d", strlen(cadena1));
    printf("\n %s", strcpy(cadena1, cadena2));
    printf("\n %d", strchr(cadena1, 7));
    printf("\n %s", strcat(cadena1, cadena2));


    puts("");
    system("pause");
    return 0;
}


size_t mstrlen(const char *cadena)
{
    size_t contador;

    while(*cadena != '\0')
    {
        contador++;
        cadena++;
    }

    return contador;
}

char *mstrcpy(char *destino, const char *origen)
{
    char *aux = destino;

    while(*origen != '\0')
    {
        *(destino++) = *(origen++);
    }

    return aux;

}

char *mstrchr(char *cadena, int c)
{
    while(*(int*)cadena != c && *cadena != '\0')
    {
        cadena++;
    }

    return *cadena != '\0' ? cadena : NULL;
}

char *mstrcat(char *destino, const char *origen)
{
    char *aux = destino;

    while(*destino != '\0')
    {
        destino++;
    }

    while(*origen != '\0')
    {
        *(destino++) =* (origen++);
    }
    *destino = '\0';

    return aux;
}

