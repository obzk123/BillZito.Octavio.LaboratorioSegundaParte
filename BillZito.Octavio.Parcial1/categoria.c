#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "categoria.h"


int hardcodearCategoria(eCategoria* categorias, int tamCategorias)
{
    int todoOk = -1;
    int id[5] = {0, 1, 2, 3, 4};
    char descripcion[5][51] = {
    {"Mesa"},
    {"Azar"},
    {"Estrategia"},
    {"Salon"},
    {"Magia"}
    };

    if(categorias != NULL && tamCategorias > 0)
    {
        for(int i = 0; i < tamCategorias; i++)
        {
            categorias[i].id = id[i];
            strcpy(categorias[i].descripcion, descripcion[i]);
        }
        todoOk = 0;
    }
    return todoOk;
}


int mostrarCategoria(eCategoria unaCategoria)
{
    printf("%d  %10s\n", unaCategoria.id, unaCategoria.descripcion);

    return 0;
}

int mostrarCategorias(eCategoria* categorias, int tamCategoria)
{
    int todoOk = -1;

    if(categorias != NULL && tamCategoria > 0)
    {
        printf("ID  Categoria\n");
        for(int i = 0; i < tamCategoria; i++)
        {
            mostrarCategoria(categorias[i]);
        }

        todoOk = 0;
    }


    return todoOk;
}
