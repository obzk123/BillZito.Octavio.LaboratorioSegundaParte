#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alquileres.h"
#include "utn.h"



int hardcodearAlquileres(eAlquileres* alquileres, int tamAlquileres, int* contadorAlquileres)
{
    int todoOk = -1;

    eAlquileres auxAlquileres[20] =
    {
        {500, 1000, 10000, {26,9,2001}, 0},
        {501, 1001, 10001, {27,9,2001}, 0},
        {502, 1002, 10002, {28,9,2001}, 0},
        {503, 1003, 10003, {29,9,2001}, 0},
        {504, 1004, 10004, {30,9,2001}, 0},
        {505, 1005, 10005, {22,9,2001}, 0},
        {506, 1006, 10006, {24,9,2001}, 0},
        {507, 1007, 10007, {21,9,2001}, 0},
        {508, 1008, 10008, {23,9,2001}, 0},
        {509, 1009, 10009, {25,9,2001}, 0},
        {510, 1010, 10010, {25,9,2001}, 0},
        {511, 1010, 10011, {25,9,2001}, 0},
        {512, 1009, 10012, {25,9,2001}, 0},
        {513, 1008, 10013, {25,9,2001}, 0},
        {514, 1007, 10014, {25,9,2001}, 0},
        {515, 1006, 10015, {25,9,2001}, 0},
        {516, 1005, 10016, {25,9,2001}, 0},
        {517, 1004, 10017, {25,9,2001}, 0},
        {518, 1003, 10018, {25,9,2001}, 0},
        {519, 1002, 10019, {30,9,2001}, 0}};

    if(alquileres != NULL && tamAlquileres > 0 && contadorAlquileres != NULL)
    {
        for(int i = 0; i < tamAlquileres; i++)
        {
            alquileres[i] = auxAlquileres[i];
            (*contadorAlquileres)++;
        }

        todoOk = 0;
    }

    return todoOk;
}


int inicializarAlquileres(eAlquileres* alquileres, int tamAlquileres)
{
    int todoOk = -1;
    if(alquileres != NULL && tamAlquileres > 0)
    {
        for(int i = 0; i < tamAlquileres; i++)
        {
            alquileres[i].isEmpty = 1;
        }
        todoOk = 0;
    }

    return todoOk;
}


int altaAlquiler(eAlquileres* alquileres, int tamAlquileres, eJuego* juegos, int tamJuegos, eCliente* clientes, int tamClientes, int* codigoAlquiler, eCategoria* categorias, int tamCategorias)
{
    int todoOk = -1;
    int indiceAlquiler;
    int indiceCliente;
    eAlquileres nuevoAlquiler;

    if(alquileres != NULL && tamAlquileres > 0 && juegos != NULL && tamJuegos > 0 && clientes != NULL && tamClientes > 0 && codigoAlquiler != NULL && categorias != NULL && tamCategorias > 0)
    {
        indiceAlquiler = buscarLibreAlquiler(alquileres, tamAlquileres);
        if(indiceAlquiler != -1)
        {
            nuevoAlquiler.codigoAlquiler = *codigoAlquiler;
            (*codigoAlquiler)++;

            printf("Alta nuevo alquiler\n\n");

            printf("Lista de juegos\n");
            mostrarJuegos(juegos, tamJuegos, categorias, tamCategorias);
            getInt("Ingrese el ID del juego: ", &nuevoAlquiler.codigoJuego, 1000, 1010);
            mostrarClientes(clientes, tamClientes);
            getInt("Ingrese el codigo del Cliente: ", &nuevoAlquiler.codigoCliente, 10000, 32767);
            indiceCliente = buscarClientePorID(clientes, tamClientes, nuevoAlquiler.codigoCliente);
            while(indiceCliente == -1)
            {
                getInt("Cliente no encontrado. Ingrese el codigo del Cliente nuevamente: ", &nuevoAlquiler.codigoCliente, 10000, 32767);
                indiceCliente = buscarClientePorID(clientes, tamClientes, nuevoAlquiler.codigoCliente);
            }

            printf("Ingresa la fecha\n");
            getInt("Ingrese el Dia: ", &nuevoAlquiler.fecha.dia, 1, 31);
            getInt("Ingrese el Mes: ", &nuevoAlquiler.fecha.mes, 1, 12);
            getInt("Ingrese el Anio: ", &nuevoAlquiler.fecha.anio, 1900, 2022);

            nuevoAlquiler.isEmpty = 0;
            alquileres[indiceAlquiler] = nuevoAlquiler;

            printf("Alquiler dado de alta con exito\n");
            todoOk = 1;
        }
    }

    return todoOk;
}


int buscarLibreAlquiler(eAlquileres* alquileres, int tamAlquileres)
{
    int todoOk = -1;
    if(alquileres != NULL && tamAlquileres > 0)
    {
        for(int i = 0; i < tamAlquileres; i++)
        {
            if(alquileres[i].isEmpty == 1)
            {
                todoOk = i;
                break;
            }
        }
    }

    return todoOk;
}


int listarAlquiler(eAlquileres UnAlquiler, eJuego* juegos, int tamJuegos, eCliente* clientes, int tamClientes, eCategoria* categorias, int tamCategorias)
{
    for(int i = 0; i < tamClientes; i++)
    {
        if(UnAlquiler.codigoCliente == clientes[i].codigo)
        {
            for(int j = 0; j < tamJuegos; j++)
            {
                if(UnAlquiler.codigoJuego == juegos[j].codigo)
                {
                    for(int k = 0; k < tamCategorias; k++)
                    {
                        if(juegos[j].idCategoria == categorias[k].id)
                        {
                            printf("%5d %10s%10s     %3d  %10s    %5.2f  %10s      %2d/%d/%4d\n",
                            clientes[i].codigo,
                            clientes[i].nombre,
                            clientes[i].apellido,
                            UnAlquiler.codigoAlquiler,
                            juegos[j].descripcion,
                            juegos[j].importe,
                            categorias[k].descripcion,
                            UnAlquiler.fecha.dia,
                            UnAlquiler.fecha.mes,
                            UnAlquiler.fecha.anio);
                            //break;
                        }
                    }
                    //break;
                }
            }
            //break;
        }
    }
    return 0;
}

int listarAlquileres(eAlquileres* alquileres, int tamAlquileres, eJuego* juegos, int tamJuegos, eCliente* clientes, int tamClientes, eCategoria* categorias, int tamCategorias)
{
    int todoOk = -1;

    if(alquileres != NULL && tamAlquileres > 0 && juegos != NULL && tamJuegos > 0 && clientes != NULL && tamClientes > 0 && categorias != NULL && tamCategorias > 0)
    {
        printf("Codigo    Nombre  Apellido   Codigo      Juego    Importe   Categoria      Fecha(D/M/A)\n");
        for(int i = 0; i < tamAlquileres; i++)
        {
            if(alquileres[i].isEmpty == 0)
            {
                listarAlquiler(alquileres[i], juegos, tamJuegos, clientes, tamClientes, categorias, tamCategorias);
            }
        }
    }
        todoOk = 0;
    return todoOk;
}


int bajaAlquileres(eAlquileres* alquileres, int tamAlquileres, int codigo, int* contadorAlquileres)
{
    int todoOk = -1;
    if(alquileres != NULL && tamAlquileres > 0 && codigo > -1)
    {
        for(int i = 0; i < tamAlquileres; i++)
        {
            if( (alquileres[i].isEmpty == 0) && (alquileres[i].codigoCliente == codigo))
            {
                alquileres[i].isEmpty = 1;
                (*contadorAlquileres)--;
                todoOk = 0;
            }
        }
    }

    return todoOk;
}
