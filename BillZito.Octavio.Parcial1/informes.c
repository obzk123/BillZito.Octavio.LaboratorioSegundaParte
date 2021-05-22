#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "informes.h"
#include "utn.h"



// 1- Mostrar Juegos de categoría de mesa
int mostrarJuegosDeMesa(eJuego* juegos, int tamJuegos, eCategoria* categorias, int tamCategorias)
{
    int todoOk = -1;
    int indiceMesa = -1;

    if(juegos != NULL && tamJuegos > 0 && categorias != NULL && tamCategorias > 0)
    {
        //Buscar indice de la categoria mesa
        for(int i = 0; i < tamCategorias; i++)
        {
            if(strcmpi(categorias[i].descripcion, "Mesa") == 0 )
            {
                indiceMesa = i;

                break;
            }
        }

        if(indiceMesa > -1)
        {
            printf("Codigo Juego        Juego      Categoria     Importe\n");
            for(int i = 0; i < tamJuegos; i++)
            {
                if(categorias[indiceMesa].id == juegos[i].idCategoria)
                {
                    mostrarJuego(juegos[i], categorias, tamCategorias);
                    todoOk = 0;
                }
            }
        }else
        {
            printf("No hay juegos con la categoria %10s\n", categorias[indiceMesa].descripcion);
        }
    }

    return todoOk;
}

//2- Mostrar los alquileres efectuados por algún cliente seleccionado

int mostrarAlquileresPorCliente(eCliente* clientes, int tamClientes, eAlquileres* alquileres, int tamAlquileres, eJuego* juegos, int tamJuegos, eCategoria* categorias, int tamCategorias)
{
    int codigoCliente;
    int index = -1;
    int flag = 0;
    if(clientes != NULL && tamClientes > 0 && alquileres != NULL && tamAlquileres > 0 && juegos != NULL && tamJuegos > 0 && categorias != NULL && tamCategorias > 0)
    {
        mostrarClientes(clientes, tamClientes);
        getInt("Seleccione el Codigo de cliente para mostrar sus alquileres: ", &codigoCliente, 10000, 32767);
        index = buscarClientePorID(clientes, tamClientes, codigoCliente);
        while(index == -1)
        {
            getInt("El cliente no existe, Ingrese nuevamente: ", &codigoCliente, 10000, 32767);
            index = buscarClientePorID(clientes, tamClientes, codigoCliente);
        }
        if(index > -1)
        {
            system("cls");
            printf("Codigo    Nombre  Apellido   Codigo      Juego    Importe   Categoria      Fecha(D/M/A)\n");
            for(int i = 0; i < tamAlquileres; i++)
            {
                if(alquileres[i].isEmpty == 0 && alquileres[i].codigoCliente == clientes[index].codigo)
                {
                    listarAlquiler(alquileres[i], juegos, tamJuegos, clientes, tamClientes, categorias, tamCategorias);
                    flag = 1;
                }
            }
            if(flag == 0)
            {
                printf("Este cliente no tiene alquileres\n");
            }
        }
    }
    return index;
}


//3- Mostrar el total de todos los importes pagados por el cliente seleccionado
int mostrarElTotalDeUnCliente(eCliente* clientes, int tamClientes, eAlquileres* alquileres, int tamAlquileres, eJuego* juegos, int tamJuegos, eCategoria* categorias, int tamCategorias)
{
    int todoOk = -1;
    int index;
    float importeTotal = 0;

    if(clientes != NULL && tamClientes > 0 && alquileres != NULL && tamAlquileres > 0 && juegos != NULL && tamJuegos > 0 && categorias != NULL && tamCategorias > 0)
    {
        index = mostrarAlquileresPorCliente(clientes, tamClientes, alquileres, tamAlquileres, juegos, tamJuegos, categorias, tamCategorias);
        if(index > -1)
        {
            for(int i = 0; i < tamAlquileres; i++)
            {
                if(alquileres[i].isEmpty == 0 && alquileres[i].codigoCliente == clientes[index].codigo)
                {
                    for(int j = 0; j < tamJuegos; j++)
                    {
                        if(juegos[j].codigo == alquileres[i].codigoJuego)
                        {
                            importeTotal += juegos[j].importe;
                            todoOk = 0;
                        }
                    }
                }
            }
            if(!todoOk)
            {
                printf("El total a pagar es $%5.2f\n", importeTotal);
            }
        }
    }

    return todoOk;
}

//4- Listar los clientes que no alquilaron juegos
int mostrarClientesSinAlquileres(eCliente* clientes, int tamClientes, eAlquileres* alquileres, int tamAlquileres)
{
    int todoOk = -1;
    int flagAlquilo = 0;
    int contadorClientes = 0;

    if(clientes != NULL && tamClientes > 0 && alquileres != NULL && tamAlquileres > 0)
    {
            printf("Lista de clientes que no tienen alquileres\n\n");
            printf("Codigo   Nombre  Apellido      Telefono   Sexo\n");
            for(int i = 0; i < tamClientes; i++)
            {
                flagAlquilo = 0;
                for(int j = 0; j < tamAlquileres; j++)
                {
                    //Busca si esta en la lista de alquileres el cliente recorrido por el indice i
                    if(alquileres[j].codigoCliente == clientes[i].codigo && clientes[i].isEmpty == 0 && alquileres[j].isEmpty == 0)
                    {
                        flagAlquilo = 1;
                    }
                }
                //Si el cliente no esta en la lista de alquileres lo muestro
                if(!flagAlquilo)
                {
                    mostrarCliente(clientes[i]);
                    contadorClientes++;
                }
            }

            if(contadorClientes == 0)
            {
                printf("No hay ningun cliente sin que haya alquilado\n");
            }
            printf("\n");
    }

    return todoOk;
}

//5- Listar los juegos que no han sido alquilados

int juegosNoAlquilados(eJuego* juegos, int tamJuegos, eAlquileres* alquileres, int tamAlquileres, eCategoria* categorias, int tamCategorias)
{
    int todoOk = -1;
    int flagJuegoAlquilado;
    int contadorJuegos = 0;
    if(juegos != NULL && tamJuegos > 0 && alquileres != NULL && tamAlquileres > 0)
    {
        printf("Lista de juegos no alquilados\n\n");
        printf(" ID                 Juego      Categoria      Precio\n");
        for(int i = 0; i < tamJuegos; i++)
        {
            flagJuegoAlquilado = 0;
            for(int j = 0; j < tamAlquileres; j++)
            {
                if(alquileres[j].isEmpty == 0 && alquileres[j].codigoJuego == juegos[i].codigo)
                {
                    flagJuegoAlquilado = 1;
                }
            }

            if(!flagJuegoAlquilado)
            {
                mostrarJuego(juegos[i], categorias, tamCategorias);
                contadorJuegos++;
                todoOk = 0;
            }
        }

        if(!contadorJuegos)
        {
            printf("No hay ningun juego que no haya alquilado\n");
        }

        printf("\n");
    }

    return todoOk;
}

//6- Listar los teléfonos de los clientes que alquilaron juegos en una determinada fecha
int listarTelefonos(eCliente* clientes, int tamClientes, eAlquileres* alquileres, int tamAlquileres)
{
    int todoOk = -1;
    int codigoCliente;
    int flag = 0;
    eFecha fecha;

    if(clientes != NULL && tamClientes > 0 && alquileres != NULL && tamAlquileres > 0)
    {
        printf("Ingrese la fecha (DD/MM/AAA) que desee para ver los telefonos de dichos clientes:\n");
        getInt("Dia: ", &fecha.dia, 1, 31);
        getInt("Mes: ", &fecha.mes, 1, 12);
        getInt("Anio: ", &fecha.anio, 1900, 2021);
        system("cls");
        printf("Codigo   Nombre  Apellido      Telefono   Sexo\n");
        for(int i = 0; i < tamAlquileres; i++)
        {
            if(fecha.dia == alquileres[i].fecha.dia && fecha.mes == alquileres[i].fecha.mes && fecha.anio == alquileres[i].fecha.anio && alquileres[i].isEmpty == 0)
            {
                codigoCliente = alquileres[i].codigoCliente;
                for(int j = 0; j < tamClientes; j++)
                {
                    if(codigoCliente == clientes[j].codigo && clientes[j].isEmpty == 0)
                    {
                        flag = 1;
                        mostrarCliente(clientes[j]);
                        break;
                    }
                }
            }
        }

        if(!flag)
        {
            printf("\nNo hay ningun alquiler con esa fecha  %2d/%d/%4d\n\n", fecha.dia, fecha.mes, fecha.anio);
        }
    }

    return todoOk;
}


//7- Listar los juegos alquilados por mujeres
int juegosAlquiladosPorMujeres(eAlquileres* alquileres, int tamAlquileres, eCliente* clientes, int tamClientes, eJuego* juegos, int tamJuegos, eCategoria* categorias, int tamCategorias)
{
    int todoOk = -1;
    int flag = 0;
    if(alquileres != NULL && tamAlquileres > 0 && clientes != NULL && tamClientes > 0 && juegos != NULL && tamJuegos > 0 && categorias != NULL && tamCategorias > 0)
    {
        printf("Los juegos alquilados por mujeres son:\n");
        for(int i = 0; i < tamClientes; i++)
        {
            if(clientes[i].sexo == 'F' && clientes[i].isEmpty == 0)
            {
                for(int j = 0; j < tamAlquileres; j++)
                {
                    if(clientes[i].codigo == alquileres[i].codigoCliente && alquileres[i].isEmpty == 0)
                    {
                        for(int k = 0; k < tamJuegos; k++)
                        {
                            if(alquileres[i].codigoJuego == juegos[k].codigo)
                            {
                                mostrarJuego(juegos[k], categorias, tamCategorias);
                                flag = 1;
                                todoOk = 0;
                            }
                        }
                        break;
                    }
                }
            }
        }

        if(!flag)
        {
            printf("No hay juegos alquilados por mujeres\n");
        }

        printf("\n");
    }

    return todoOk;
}

//8- Mostrar el o los juegos más alquilados por hombres
int mostrarJuegoMasAlquiladoPorHombres(eCliente* clientes, int tamClientes, eAlquileres* alquileres, int tamAlquileres, eJuego* juegos, int tamJuegos, eCategoria* categorias, int tamCategorias)
{
    int todoOk = -1;
    int juegosCantidad[tamJuegos];
    char nombreJuego[tamJuegos][20];
    int maxDeUnJuegoAlquilado = 0;

    if(clientes != NULL && tamClientes > 0 && alquileres != NULL && tamAlquileres > 0 && juegos != NULL && tamJuegos > 0 && categorias != NULL && tamCategorias > 0)
    {
        for(int i = 0; i < tamJuegos; i++)
        {
            juegosCantidad[i] = 0;
            strcpy(nombreJuego[i], juegos[i].descripcion);
            for(int j = 0; j < tamClientes; j++)
            {
                if(clientes[j].sexo == 'M' && clientes[j].isEmpty == 0)
                {
                    for(int k = 0; k < tamAlquileres; k++)
                    {
                        if(alquileres[k].isEmpty == 0 && alquileres[k].codigoCliente == clientes[j].codigo && alquileres[k].codigoJuego == juegos[i].codigo)
                        {
                            juegosCantidad[i]++;
                            todoOk = 0;
                        }
                    }
                }
            }
        }


        for(int i = 0; i < tamJuegos; i++)
        {
            if(i == 0 || juegosCantidad[i] > maxDeUnJuegoAlquilado)
            {
                maxDeUnJuegoAlquilado = juegosCantidad[i];
            }
        }

        printf("El o los juegos con mas cantidad de alquileres por hombres son:\n");
        printf("              Nombre    Veces alquilado\n");
        for(int i = 0; i < tamJuegos; i++)
        {
            if(juegosCantidad[i] == maxDeUnJuegoAlquilado)
            {
                printf("%20s          %d\n", nombreJuego[i], juegosCantidad[i]);
            }
        }

        printf("\n");
    }
    return todoOk;
}


//9- Listar los clientes que alquilaron un determinado juego
int listarClientesPorUnJuego(eCliente* clientes, int tamClientes, eAlquileres* alquileres, int tamAlquileres, eJuego* juegos, int tamJuegos, eCategoria* categorias, int tamCategorias)
{
    int todoOk = -1;
    int codigoJuego;
    int indiceJuego = -1;
    int flagAlquilaron = 0;

    if(clientes != NULL && tamClientes > 0 && alquileres != NULL && tamAlquileres > 0 && juegos != NULL && tamJuegos > 0 && categorias != NULL && tamCategorias > 0)
    {
        mostrarJuegos(juegos, tamJuegos, categorias, tamCategorias);
        getInt("Ingrese el Codigo de juego para ver los clientes que lo alquilaron: ", &codigoJuego, 1000, 1010);
        for(int i = 0; i < tamJuegos; i++)
        {
            if(codigoJuego == juegos[i].codigo)
            {
                indiceJuego = i;
                break;
            }
        }

        system("cls");
        printf("Los clientes que alquilaron %s son:\n", juegos[indiceJuego].descripcion);
        printf("Codigo   Nombre  Apellido      Telefono   Sexo\n");
        for(int i = 0; i < tamClientes; i++)
        {
            if(clientes[i].isEmpty == 0)
            {
                for(int j = 0; j < tamAlquileres; j++)
                {
                    if(alquileres[j].isEmpty == 0 && alquileres[j].codigoJuego == codigoJuego && alquileres[j].codigoCliente == clientes[i].codigo)
                    {
                        mostrarCliente(clientes[i]);
                        flagAlquilaron = 1;
                        todoOk = 0;
                    }
                }
            }
        }

        if(!flagAlquilaron)
        {
            printf("No hay clientes que hayan alquilado %s\n", juegos[indiceJuego].descripcion);
        }

        printf("\n");
    }

    return todoOk;
}

//10-Mostrar la recaudación de una fecha en particular
int mostrarLaRecaudacionDeUnaFecha(eAlquileres* alquileres, int tamAlquileres, eJuego* juegos, int tamJuegos)
{
    int todoOk = -1;
    eFecha fecha;
    int flag = 0;
    float totalRecaudado = 0;
    if(alquileres != NULL && tamAlquileres > 0 && juegos != NULL && tamJuegos > 0)
    {
        printf("Ingrese la fecha (DD/MM/AAA) que desee ver su recaudacion:\n");
        getInt("Dia: ", &fecha.dia, 1, 31);
        getInt("Mes: ", &fecha.mes, 1, 12);
        getInt("Anio: ", &fecha.anio, 1900, 2021);

        for(int i = 0; i < tamJuegos; i++)
        {
            for(int j = 0; j < tamAlquileres; j++)
            {
                if(fecha.dia == alquileres[j].fecha.dia && fecha.mes == alquileres[j].fecha.mes && fecha.anio == alquileres[j].fecha.anio && alquileres[j].isEmpty == 0 && alquileres[j].codigoJuego == juegos[i].codigo)
                {
                    flag = 1;
                    totalRecaudado += juegos[i].importe;
                }
            }
        }
        if(flag)
        {
            system("cls");
            printf("   DD/MM/AAAA       Total recaudado\n");
            printf("  %2d/%d/%4d         $%5.2f\n\n", fecha.dia, fecha.mes, fecha.anio, totalRecaudado);
        }else
        {
            printf("\n\nNo hay ningun alquiler cargado con esa fecha\n\n");
        }

    }

    return todoOk;
}
