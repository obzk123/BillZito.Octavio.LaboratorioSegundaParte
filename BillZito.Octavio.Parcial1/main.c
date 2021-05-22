#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "utn.h"
#include "juego.h"
#include "categoria.h"
#include "cliente.h"
#include "alquileres.h"
#include "fecha.h"
#include "informes.h"


#define TAMJUEGOS 10
#define TAMCATEGORIAS 5
#define TAMCLIENTES 20
#define TAMALQUILERES 20


/** \brief retorna un caracter dependiendo a la opcion ingresada por el usuario
 *
 * \return char
 *
 */
char menu();

/** \brief retorna un entero dependinedo la opcion ingresada por el usuario
 *
 * \return int
 *
 */
int menuInformes();

int main()
{
    char opcion = 'N';
    int opcionInt = 0;

    int contadorClientes = 0;
    int contadorAlquileres = 0;
    int codigoCliente = 10000;
    int codigoAlquileres = 500;
    int codigo;

    eJuego juegos[TAMJUEGOS];
    eCategoria categorias[TAMCATEGORIAS];
    eCliente clientes[TAMCLIENTES];
    eAlquileres alquileres[TAMALQUILERES];

    hardcodearCategoria(categorias, TAMCATEGORIAS);
    hardcodearJuego(juegos, TAMJUEGOS);

    inicializarClientes(clientes, TAMCLIENTES);
    inicializarAlquileres(alquileres, TAMALQUILERES);

    //De prubea
    hardcodearClientes(clientes, TAMCLIENTES, &contadorClientes);
    hardcodearAlquileres(alquileres, TAMALQUILERES, &contadorAlquileres);


    do
    {
        system("cls");
        switch(menu())
        {
        case 'A':
            if(contadorClientes < TAMCLIENTES)
            {
                system("cls");
                if(altaCliente(clientes,TAMCLIENTES, &codigoCliente))
                {
                    contadorClientes++;
                }
            }else
            {
                printf("Array lleno no se pueden agregar clientes.\n");
            }
            break;
        case 'B':
            if(contadorClientes > 0)
            {
                system("cls");
                modificarCliente(clientes, TAMCLIENTES);
            }else
            {
                printf("No hay clientes cargados para modificar.\n");
            }
            break;
        case 'C':
            if(contadorClientes > 0)
            {
                system("cls");
                codigo = bajaCliente(clientes, TAMCLIENTES);
                if(codigo > -1)
                {
                    bajaAlquileres(alquileres, TAMALQUILERES, codigo, &contadorAlquileres);
                    contadorClientes--;
                }
            }
            else
            {
                printf("No hay clientes cargados para eliminar.\n");
            }
            break;
        case 'D':
            if(contadorClientes > 0)
            {
                system("cls");
                ordenarClientes(clientes, TAMCLIENTES);
                mostrarClientes(clientes, TAMCLIENTES);
            }else
            {
                printf("No hay clientes para mostrar.\n");
            }
            break;
        case 'E':
            if(contadorAlquileres < TAMALQUILERES && contadorClientes > 0)
            {
                system("cls");
                if(altaAlquiler(alquileres, TAMALQUILERES, juegos, TAMJUEGOS, clientes, TAMCLIENTES, &codigoAlquileres, categorias, TAMCATEGORIAS))
                {
                    contadorAlquileres++;
                }
            }else
            {
                printf("Array lleno no se puede cargar mas alquileres o no existen clientes.\n");
            }
            break;
        case 'F':
            if(contadorAlquileres > 0 && contadorClientes > 0)
            {
                system("cls");
                listarAlquileres(alquileres, TAMALQUILERES, juegos, TAMJUEGOS, clientes, TAMCLIENTES, categorias, TAMCATEGORIAS);
            }else
            {
                printf("No hay alquileres para mostrar.\n");
            }
            break;
        case 'G':
            if(contadorAlquileres > 0 && contadorClientes > 0)
            {
                do
                {
                    system("cls");
                    switch(menuInformes())
                    {
                    case 1:
                        system("cls");
                        mostrarJuegosDeMesa(juegos, TAMJUEGOS, categorias, TAMCATEGORIAS);
                        break;
                    case 2:
                        system("cls");
                        mostrarAlquileresPorCliente(clientes, TAMCLIENTES, alquileres, TAMALQUILERES, juegos, TAMJUEGOS, categorias, TAMCATEGORIAS);
                        break;
                    case 3:
                        system("cls");
                        mostrarElTotalDeUnCliente(clientes, TAMCLIENTES, alquileres, TAMALQUILERES, juegos, TAMJUEGOS, categorias, TAMCATEGORIAS);
                        break;
                    case 4:
                        system("cls");
                        mostrarClientesSinAlquileres(clientes, TAMCLIENTES, alquileres, TAMALQUILERES);
                        break;
                    case 5:
                        system("cls");
                        juegosNoAlquilados(juegos, TAMJUEGOS, alquileres, TAMALQUILERES, categorias, TAMCATEGORIAS);
                        break;
                    case 6:
                        system("cls");
                        listarTelefonos(clientes, TAMCLIENTES, alquileres, TAMALQUILERES);
                        break;
                    case 7:
                        system("cls");
                        juegosAlquiladosPorMujeres(alquileres, TAMALQUILERES, clientes, TAMCLIENTES, juegos, TAMJUEGOS, categorias, TAMCATEGORIAS);
                        break;
                    case 8:
                        system("cls");
                        mostrarJuegoMasAlquiladoPorHombres(clientes, TAMCLIENTES, alquileres, TAMALQUILERES, juegos, TAMJUEGOS, categorias, TAMCATEGORIAS);
                        break;
                    case 9:
                        system("cls");
                        listarClientesPorUnJuego(clientes, TAMCLIENTES, alquileres, TAMALQUILERES, juegos, TAMJUEGOS, categorias, TAMCATEGORIAS);
                        break;
                    case 10:
                        system("cls");
                        mostrarLaRecaudacionDeUnaFecha(alquileres, TAMALQUILERES, juegos, TAMJUEGOS);
                        break;
                    case 11:
                        opcionInt = 11;
                        break;
                    }
                    if(opcionInt != 11)
                    {
                        system("pause");
                    }
                }while(opcionInt != 11);
            }else{
                printf("Primero cargue alquileres y clientes para continuar.\n");
            }
            break;

        case 'H':
            printf("Seguro desea salir S/N: ");
            fflush(stdin);
            scanf("%c", &opcion);
            opcion = toupper(opcion);
            while(opcion != 'S' && opcion != 'N')
            {
                printf("Opcion incorrecta. Ingrese nuevamente: ");
                fflush(stdin);
                scanf("%c", &opcion);
                opcion = toupper(opcion);
            }

            if(opcion == 'N')
            {
                printf("Salir cancelado\n");
            }
            break;
        }

    system("pause");
    }while(opcion == 'N');

    return 0;
}


char menu()
{
    char opcion;

    printf("Menu de opciones\n\n");
    printf("A.Altas Clientes\n");
    printf("B.Modificar Clientes\n");
    printf("C.Baja Clientes\n");
    printf("D.Listar Clientes\n");
    printf("E.Alta alquiler\n");
    printf("F.Lista alquiler\n");
    printf("G.Menu de informes\n");
    printf("H.Salir\n\n");
    printf("Escoja su opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion = toupper(opcion);
    while(opcion != 'A' && opcion != 'B' && opcion != 'C' && opcion != 'D' && opcion != 'E' && opcion != 'F' && opcion != 'G' && opcion != 'H')
    {
        printf("Opcion incorrecta, Ingrese nuevamente:");
        fflush(stdin);
        scanf("%c", &opcion);
        opcion = toupper(opcion);
    }

    return opcion;
}


int menuInformes()
{
    int opcion;
    printf("Menu de Informes\n\n");
    printf("1.Mostrar Juegos de categoria de mesa\n");
    printf("2.Mostrar los alquileres efectuados por algun cliente seleccionado\n");
    printf("3.Mostrar el total de todos los importes pagados por el cliente seleccionado\n");
    printf("4.Listar los clientes que no alquilaron juegos\n");
    printf("5.Listar los juegos que no han sido alquilados\n");
    printf("6.Listar los telefonos de los clientes que alquilaron juegos en una determinada fecha\n");
    printf("7.Listar los juegos alquilados por mujeres\n");
    printf("8.Mostrar el o los juegos mas alquilados por hombres\n");
    printf("9.Listar los clientes que alquilaron un determinado juego\n");
    printf("10.Mostrar la recaudacion de una fecha en particular\n");
    printf("11.Volver\n");
    getInt("Escoja su opcion: ", &opcion, 1, 11);
    return opcion;
}
