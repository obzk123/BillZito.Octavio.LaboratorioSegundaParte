#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int getInt(char* mensaje, int* pResultado, int minimo, int maximo)
{
    int retorno = -1;
    int auxInt;
    if(mensaje != NULL && pResultado != NULL && maximo < 32768)
    {
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%d", &auxInt);
        while(auxInt < minimo || auxInt > maximo)
        {
            printf("Error. Ingrese entre (%d - %d): ", minimo, maximo);
            fflush(stdin);
            scanf("%d", &auxInt);
        }
        *pResultado = auxInt;
        retorno = 0;
    }else
    {
        printf("Error de parametros en la funcion\n");
    }
    return retorno;
}

int getFloat(char* mensaje, float* pResultado, float minimo, float maximo)
{
    int retorno = -1;
    float auxFloat;
    if(mensaje != NULL && pResultado != NULL && maximo < 32768)
    {
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%f", &auxFloat);
        while(auxFloat < minimo || auxFloat > maximo)
        {
            printf("Error. Ingrese entre (%.2f - %.2f): ", minimo, maximo);
            fflush(stdin);
            scanf("%f", &auxFloat);
        }
        *pResultado = auxFloat;

        retorno = 0;
    }else
    {
        printf("Error de parametros en la funcion\n");
    }
    return retorno;
}

int getString(char* mensaje, char pResultado[], int tam)
{
    int retorno = -1;
    char auxCad[100];
    if(mensaje != NULL && pResultado != NULL && tam < 96 && tam > 0)
    {
        printf("%s", mensaje);
        fflush(stdin);
        fgets(auxCad, (tam + 5), stdin);

        while(strlen(auxCad) > tam || strlen(auxCad) < 1)
        {
            printf("Error. Ingrese solo %d caracteres: ", tam);
            fflush(stdin);
            fgets(auxCad, tam, stdin);
        }
        if(auxCad[strlen(auxCad)- 1] == '\n')
        {
            auxCad[strlen(auxCad)- 1] = '\0';
        }
        strcpy(pResultado, auxCad);

        retorno = 0;
    }else
    {
        printf("Error de parametros en la funcion\n");
    }

    return retorno;
}
