#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
#endif // UTN_H_INCLUDED


/** \brief obtiene un int y valida entre el maximo y el minimo colocado en parametros y lo guarda en pResultado
 *
 * \param mensaje char*
 * \param pResultado int*
 * \param minimo int
 * \param maximo int
 * \return int
 *
 */
int getInt(char* mensaje, int* pResultado, int minimo, int maximo);


/** \brief Obtiene un float valida entre el maximo y el minimo colocado en parametros y lo guarda en pResultado
 *
 * \param mensaje char*
 * \param pResultado float*
 * \param minimo float
 * \param maximo float
 * \return int
 *
 */
int getFloat(char* mensaje, float* pResultado, float minimo, float maximo);


/** \brief obtiene un char y lo guarda en pResultado con un tamaño maximo pasado en tam
 *
 * \param mensaje char*
 * \param pResultado[] char
 * \param tam int
 * \return int
 *
 */
int getString(char* mensaje, char pResultado[], int tam);
