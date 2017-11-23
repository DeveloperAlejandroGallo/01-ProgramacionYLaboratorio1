/**************************************************************************************************/
//Definiciones
/**************************************************************************************************/


/** \brief  Suma 2 float
 *
 * \param Primer Operando a Sumar
 * \param Segundo Operando a Sumar
 * \return Retorna la suma de los parametros.
 *
 */
float sumar(float n1, float n2);

/** \brief  Resta 2 floats
 *
 * \param Primer Operando a restar
 * \param Segundo Operando a restar
 * \return Retorna la resta de los parametros
 *
 */
float restar(float n1, float n2);

/** \brief  Divide el Primer float por el segundo. Retorna 0 y un mensaje de error si el Divisor es 0.
 *
 * \param Primer Operando - Dividendo
 * \param Segundo Operando  - Divisor
 * \return Retorna la division (float), entre el Primer Operando y el Segundo
 *
 */
float dividir(float nro1, float nro2);

/** \brief  Multiplica 2 floats
 *
 * \param Primer Operando a multiplicar
 * \param Segundo Operando a multiplicar
 * \return Devuelve la multiplicacion entre el Primer y segundo operando
 *
 */
float multiplicar(float nro1, float nro2);

/** \brief Devuelve el Factorial de un entero.
 *
 * \param Operando a factorizar
 * \return Retorna la factorizacion del nro ingresado
 *
 */
int factorial(int nro);

/** \brief Obtiene un float por teclado.
 *
 * \return Retorna el nro obtenido por teclado.
 *
 */
float obtenerNro();

//   VECTORES  //

/** \brief Obtiene el mayor de un vector.
 *
 * \param Vector a analizar
 * \param Tamanio maximo del vector
 * \return Retorna el mayor elemento del vector.
 *
 */
 int mayorDeVectorInt(int [], int);

/** \brief Obtiene el menor de un vector.
 *
 * \param Vector a analizar
 * \param Tamanio maximo del vector
 * \return Retorna el menor elemento del vector.
 *
 */
 int menorDeVectorInt(int [], int);

 /** \brief Bubble Sort
 *
 * \param Vector de enteros a analizar
 * \param Tamanio maximo del vector
 * \param Criterio de orden: 0: Mayor a menor - 1: Menor a mayor.
 * \return Void
 *
 */
 void bubbleSortInt(int [], int, int);
