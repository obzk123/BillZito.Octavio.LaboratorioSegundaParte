#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "juego.h"



int hardcodearJuego(eJuego* juegos, int tamJuegos)
{
    int todoOk = -1;
    int codigo[10] = {1000, 1001, 1002, 1003, 1004, 1005, 1006, 1008, 1009, 1010};
    char descripcion[10][25] = {
    {"Monopoly"},
    {"Ruleta"},
    {"StarCraft"},
    {"Ajedrez"},
    {"Magics"},
    {"Jenga"},
    {"Civilization VI"},
    {"Age of Empires III"},
    {"Harry potter"},
    {"Metegol"}
    };

    float importe[10] = {1550, 2000, 1000, 500, 400, 300, 1800.50, 975.50, 825.25, 775};
    int idCategoria[10] = {0, 1, 2, 3, 4, 0, 2, 2, 4, 3};

    if(juegos != NULL && tamJuegos > 0)
    {
        for(int i = 0; i < tamJuegos; i++)
        {
            juegos[i].codigo = codigo[i];
            strcpy(juegos[i].descripcion, descripcion[i]);
            juegos[i].importe = importe[i];
            juegos[i].idCategoria = idCategoria[i];
        }

        todoOk = 0;
    }
    return todoOk;
}


int mostrarJuego(eJuego unJuego, eCategoria* categorias, int tamCategorias)
{
    char categoriaDescripcion[25];
    for(int i = 0; i < tamCategorias; i++)
    {
        if(unJuego.idCategoria == categorias[i].id)
        {
            strcpy(categoriaDescripcion, categorias[i].descripcion);
            break;
        }
    }
    printf("%d %20s     %10s     %5.2f\n",
            unJuego.codigo,
            unJuego.descripcion,
            categoriaDescripcion,
            unJuego.importe);

    return 0;
}

int mostrarJuegos(eJuego* juegos, int tamJuegos, eCategoria* categorias, int tamCategorias)
{
    int todoOk = -1;

    if(juegos != NULL && tamJuegos > 0 && categorias != NULL && tamCategorias > 0)
    {
        printf(" ID                 Juego      Categoria      Precio\n");
        for(int i = 0; i < tamJuegos; i++)
        {
            for(int j = 0; j < tamCategorias; j++)
            {
                if(juegos[i].idCategoria == categorias[j].id)
                {
                    mostrarJuego(juegos[i], categorias, tamCategorias);
                }
            }
        }
        todoOk = 0;
    }

    return todoOk;
}
