#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED

#include "fecha.h"
#include "juego.h"
#include "cliente.h"
#include "categoria.h"

typedef struct
{
    int codigoAlquiler;
    int codigoJuego;
    int codigoCliente;
    eFecha fecha;
    int isEmpty;
}eAlquileres;

#endif // ALQUILERES_H_INCLUDED

/** \brief precargo alquileres antes de empezar el programa retorna 0 si esta todo bien o -1 si fallo
 *
 * \param alquileres eAlquileres*
 * \param tamAlquileres int
 * \param contadorAlquileres int*
 * \return int
 *
 */
int hardcodearAlquileres(eAlquileres* alquileres, int tamAlquileres, int* contadorAlquileres);

/** \brief inicializa la bandera isEmpty a 1 de el array de alquileres retorna 0 si todo salio bien y -1 si algo salio mal
 *
 * \param alquileres eAlquileres*
 * \param tamAlquileres int
 * \return int
 *
 */
int inicializarAlquileres(eAlquileres* alquileres, int tamAlquileres);

/** \brief da de alta un alquiler y le asigna un id pasandole un parametro por referencia retorna 1 si todo salio bien y -1 si algo salio mal
 *
 * \param alquileres eAlquileres*
 * \param tamAlquileres int
 * \param juegos eJuego*
 * \param tamJuegos int
 * \param clientes eCliente*
 * \param tamClientes int
 * \param codigoAlquiler int*
 * \param categorias eCategoria*
 * \param tamCategorias int
 * \return int
 *
 */
int altaAlquiler(eAlquileres* alquileres, int tamAlquileres, eJuego* juegos, int tamJuegos, eCliente* clientes, int tamClientes, int* codigoAlquiler, eCategoria* categorias, int tamCategorias);

/** \brief recorre todo el array de alquiler buscando la primer bandera isEmpty en 1 y retorna el indice de donde lo encontro, si no lo encontro o algo salio mal retorna -1
 *
 * \param alquileres eAlquileres*
 * \param tamAlquileres int
 * \return int
 *
 */
int buscarLibreAlquiler(eAlquileres* alquileres, int tamAlquileres);

/** \brief muestra un solo alquiler retorna 0
 *
 * \param UnAlquiler eAlquileres
 * \param Unjuego eJuego
 * \param Uncliente eCliente
 * \param unaCategoria eCategoria
 * \return int
 *
 */
int listarAlquiler(eAlquileres UnAlquiler, eJuego* juegos, int tamJuegos, eCliente* clientes, int tamClientes, eCategoria* categorias, int tamCategorias);

/** \brief muestra varios alquileres retorna 0 si todo salio bien y -1 si algo salio mal
 *
 * \param alquileres eAlquileres*
 * \param tamAlquileres int
 * \param juegos eJuego*
 * \param tamJuegos int
 * \param clientes eCliente*
 * \param tamClientes int
 * \param categorias eCategoria*
 * \param tamCategorias int
 * \return int
 *
 */
int listarAlquileres(eAlquileres* alquileres, int tamAlquileres, eJuego* juegos, int tamJuegos, eCliente* clientes, int tamClientes, eCategoria* categorias, int tamCategorias);

/** \brief retorna 0 si pudo dar de baja el alquiler o -1 si algo fallo
 *
 * \param alquileres eAlquileres*
 * \param tamAlquileres int
 * \param codigo int
 * \param contadorAlquileres int*
 * \return int
 *
 */
int bajaAlquileres(eAlquileres* alquileres, int tamAlquileres, int codigo, int* contadorAlquileres);
