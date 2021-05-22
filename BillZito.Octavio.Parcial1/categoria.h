#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED

typedef struct{
    int id;
    char descripcion[51];
}eCategoria;

#endif // CATEGORIA_H_INCLUDED


/** \brief sirve para cargar los datos de categoria antes que inicie el programa devuelve -1 si algo salio mal y 0 si todo salio bien
 *
 * \param categorias eCategoria*
 * \param tamCategorias int
 * \return int
 *
 */
int hardcodearCategoria(eCategoria* categorias, int tamCategorias);

/** \brief muestra una categoria retorna 0
 *
 * \param unaCategoria eCategoria
 * \return int
 *
 */
int mostrarCategoria(eCategoria unaCategoria);


/** \brief muestra varias categorias retorna -1 si algo salio mal o 0 si todo salio bien
 *
 * \param categorias eCategoria*
 * \param tamCategoria int
 * \return int
 *
 */
int mostrarCategorias(eCategoria* categorias, int tamCategoria);
