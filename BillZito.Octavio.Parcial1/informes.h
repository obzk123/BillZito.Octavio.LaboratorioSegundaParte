#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include "juego.h"
#include "categoria.h"
#include "cliente.h"
#include "alquileres.h"

#endif // INFORMES_H_INCLUDED


/** \brief retorna un entero, si devuelve -1 algo fallo por parametro o no encontro nada y si devuelve 0 es que lo encontro.
 *
 * \param juegos eJuego*
 * \param tamJuegos int
 * \param categorias eCategoria*
 * \param tamCategorias int
 * \return int
 *
 */
int mostrarJuegosDeMesa(eJuego* juegos, int tamJuegos, eCategoria* categorias, int tamCategorias);

/** \brief retorna 0 si todo salio bien o -1 si algo fallo por parametro, al seleccionar un cliente muestra sus alquileres
 *
 * \param clientes eCliente*
 * \param tamClientes int
 * \param alquileres eAlquileres*
 * \param tamAlquileres int
 * \param juegos eJuego*
 * \param tamJuegos int
 * \param categorias eCategoria*
 * \param tamCategorias int
 * \return int
 *
 */
int mostrarAlquileresPorCliente(eCliente* clientes, int tamClientes, eAlquileres* alquileres, int tamAlquileres, eJuego* juegos, int tamJuegos, eCategoria* categorias, int tamCategorias);

/** \brief retorna -1 si algo fallo por parametro o el cliente no tiene alquileres o 0 si todo salio bien, al seleccionar un cliente muestra el total a pagar de sus alquileres
 *
 * \param clientes eCliente*
 * \param tamClientes int
 * \param alquileres eAlquileres*
 * \param tamAlquileres int
 * \param juegos eJuego*
 * \param tamJuegos int
 * \param categorias eCategoria*
 * \param tamCategorias int
 * \return int
 *
 */
int mostrarElTotalDeUnCliente(eCliente* clientes, int tamClientes, eAlquileres* alquileres, int tamAlquileres, eJuego* juegos, int tamJuegos, eCategoria* categorias, int tamCategorias);

/** \brief retorna -1 si algo fallo algo por parametro o no encontro clientes sin alquileres o 0 si encontro clientes sin alquileres y los muestra
 *
 * \param clientes eCliente*
 * \param tamClientes int
 * \param alquileres eAlquileres*
 * \param tamAlquileres int
 * \return int
 *
 */
int mostrarClientesSinAlquileres(eCliente* clientes, int tamClientes, eAlquileres* alquileres, int tamAlquileres);

/** \brief retorna -1 si no encontro un juego no alquilado o fallo algo, o retorna 1 si encontro algun juego no alquilado
 *
 * \param juegos eJuego*
 * \param tamJuegos int
 * \param alquileres eAlquileres*
 * \param tamAlquileres int
 * \param categorias eCategoria*
 * \param tamCategorias int
 * \return int
 *
 */
int juegosNoAlquilados(eJuego* juegos, int tamJuegos, eAlquileres* alquileres, int tamAlquileres, eCategoria* categorias, int tamCategorias);

/** \brief retorna -1 si no encontro dicha fecha o si fallo algo por parametro algo o retorna 0 si salio todo bien y muestra los telefonos de los clientes que alquilaron en una determinada fecha.
 *
 * \param clientes eCliente*
 * \param tamClientes int
 * \param alquileres eAlquileres*
 * \param tamAlquileres int
 * \return int
 *
 */
int listarTelefonos(eCliente* clientes, int tamClientes, eAlquileres* alquileres, int tamAlquileres);

/** \brief retorna -1 si no encontro ninguna mujer que haya alquilado o fallo algo por parametro
 *
 * \param alquileres eAlquileres*
 * \param tamAlquileres int
 * \param clientes eCliente*
 * \param tamClientes int
 * \param juegos eJuego*
 * \param tamJuegos int
 * \param categorias eCategoria*
 * \param tamCategorias int
 * \return int
 *
 */
int juegosAlquiladosPorMujeres(eAlquileres* alquileres, int tamAlquileres, eCliente* clientes, int tamClientes, eJuego* juegos, int tamJuegos, eCategoria* categorias, int tamCategorias);

/** \brief retorna -1 si no encontro ningun juego alquilado por hombres o fallo algo por parametro, o 0 si encontro un juego y muestra el juego mas alquilado por hombres, si hay empate muestra varios
 *
 * \param clientes eCliente*
 * \param tamClientes int
 * \param alquileres eAlquileres*
 * \param tamAlquileres int
 * \param juegos eJuego*
 * \param tamJuegos int
 * \param categorias eCategoria*
 * \param tamCategorias int
 * \return int
 *
 */
int mostrarJuegoMasAlquiladoPorHombres(eCliente* clientes, int tamClientes, eAlquileres* alquileres, int tamAlquileres, eJuego* juegos, int tamJuegos, eCategoria* categorias, int tamCategorias);

int listarClientesPorUnJuego(eCliente* clientes, int tamClientes, eAlquileres* alquileres, int tamAlquileres, eJuego* juegos, int tamJuegos, eCategoria* categorias, int tamCategorias);

/** \brief retorna -1 si no encontro esa fecha con un alquiler o fallo algo por parametro o 0 si encontro esa fecha y devuelve el total recaudado para ese dia
 *
 * \param alquileres eAlquileres*
 * \param tamAlquileres int
 * \param juegos eJuego*
 * \param tamJuegos int
 * \return int
 *
 */
int mostrarLaRecaudacionDeUnaFecha(eAlquileres* alquileres, int tamAlquileres, eJuego* juegos, int tamJuegos);


