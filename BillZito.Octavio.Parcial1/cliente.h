#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED


typedef struct
{
    int codigo;
    char nombre[51];
    char apellido[51];
    char sexo;
    char telefono[21];
    int isEmpty;
}eCliente;


#endif // CLIENTE_H_INCLUDED


/** \brief pre cargo los datos del cliente antes de empezar el programa retorna -1 si algo fallo o 0 si todo salio bien
 *
 * \param clientes eCliente*
 * \param tamClientes int
 * \param contadorClientes int*
 * \return int
 *
 */
int hardcodearClientes(eCliente* clientes, int tamClientes, int* contadorClientes);

/** \brief inicializa la bandera de los clientes en 1, retorna -1 si algo salio mal y 0 si toda esta bien
 *
 * \param clientes eCliente*
 * \param tamClientes int
 * \return int
 *
 */
int inicializarClientes(eCliente* clientes, int tamClientes);


/** \brief busca si hay alguna bandera de isEmpty en 1 del array clientes y retorna el indice de donde lo encontre o -1 si algo salio mal o no la encuentra
 *
 * \param clientes eCliente*
 * \param tamClientes int
 * \return int
 *
 */
int buscarLibreCliente(eCliente* clientes, int tamClientes);

/** \brief da de alta un cliente asignadole un codigo pasado por referencia retorna 1 si salio todo bien y -1 si salio algo mal
 *
 * \param clientes eCliente*
 * \param tamClientes int
 * \param codigoCliente int*
 * \return int
 *
 */
int altaCliente(eCliente* clientes, int tamClientes, int* codigoCliente);


/** \brief sirve para modificar un cliente retorna -1 si algo salio mal y 0 si todo salio bien
 *
 * \param clientes eCliente*
 * \param tamClientes int
 * \return int
 *
 */
int modificarCliente(eCliente* clientes, int tamClientes);

/** \brief busca un cliente por el id pasado por valor retorna el indice donde lo encontre devuelve -1 si no encontro o algo salio mal
 *
 * \param clientes eCliente*
 * \param tamClientes int
 * \param codigoCliente int
 * \return int
 *
 */
int buscarClientePorID(eCliente* clientes, int tamClientes, int codigoCliente);


/** \brief muestra un cliente
 *
 * \param unCliente eCliente
 * \return int
 *
 */
int mostrarCliente(eCliente unCliente);

/** \brief muestra varios clientes
 *
 * \param clientes eCliente*
 * \param tamClientes int
 * \return int
 *
 */
int mostrarClientes(eCliente* clientes, int tamClientes);

/** \brief da de baja un cliente colocando el isEmpty de este en 1
 *
 * \param clientes eCliente*
 * \param tamClientes int
 * \return int
 *
 */
int bajaCliente(eCliente* clientes, int tamClientes);

/** \brief ordena los cliente primero por apellido y luego por nombre retorna -1 si algo salio mal y 0 si todo salio bien
 *
 * \param clientes eCliente*
 * \param tamClientes int
 * \return int
 *
 */
int ordenarClientes(eCliente* clientes, int tamClientes);
