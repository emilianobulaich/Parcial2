/*
 * Input.h
 *
 *  Created on: 27 oct. 2021
 *      Author: Yeller
 */

#ifndef INPUT_H_
#define INPUT_H_


/// \brief Se pide un numero flotante, se lo ingresa y se lo compara contra un minimo y un maximo.
/// \param mensaje[] char
/// \param numMin float
/// \param numMax float
/// \return float  Retorna el numero enviado, ya validado
float IngresarFlotanteEntreRango(char mensaje[] ,float numMin ,float numMax);

/// \brief Se pide un numero entero, se lo ingresa y se lo compara contra un minimo y un maximo.
/// \param pResultado int*
/// \param mensaje[] char
/// \param min int
/// \param max int
/// \param reintentos int
/// \return int Retorna el numero enviado, ya validado
int ObtenerEnteroEntreRango(int* pResultado, char mensaje[], int min, int max, int reintentos);

/// \brief Pide una cadena a traves de un mensaje y si no contiene numeros lo devuelve por parametro
/// \param mensaje[] char
/// \param mensajeError[] char
/// \param cadena[] char
/// \param tam int
/// \param reintentos int
/// \return int Return (-1) si la cadena contiene numero/s  - (0) si esta Ok
int ObtenerString(char mensaje[], char cadena[], int tam, int reintentos);

/// \brief Verifica que la cadena no posea numeros
/// \param cadena char*
/// \return int Return (-1) si hay la cadena tiene letras o signos, excepto el "-" - (0) si esta Ok

int LaCadenaEsString(char* cadena);

/// \brief Pide un numero a traves de un mensaje y si es entero lo devuelve por parametro
/// \param pResultado int*
/// \param mensaje[] char
/// \param reintentos int
/// \return int Return (-1) si el numero no es entero  - (0) si esta Ok
int ObtenerEntero(int* pResultado, char mensaje[], int reintentos);

/// \brief Pide un numero a traves de un mensaje y si es entero y mayor a 0 lo devuelve por parametro
/// \param pResultado int*
/// \param mensaje[] char
/// \param reintentos int
/// \return int Return (-1) si el numero no es entero  - (0) si esta Ok
int ObtenerEnteroMayorACero(int* pResultado, char mensaje[], int reintentos);
/// \brief Castea la cadena de char a int
/// \param pResultado int*
/// \return int Return (-1) si la cadena no pudo castearse con exito  - (0) si esta Ok
int CastearAEntero(int* pResultado);

/// \brief Verifica que la cadena posea solo numeros
/// \param cadena char*
/// \return int Return (-1) si hay la cadena tiene letras o signos, excepto el "-" - (0) si esta Ok
int LaCadenaEsNumerica(char* cadena);

/// \brief Pide un numero a traves de un mensaje y si es float lo devuelve por parametro
/// \param pResultado float*
/// \param mensaje[] char
/// \return int Return (-1) si el numero no es flotante  - (0) si esta Ok
float ObtenerFlotante(float* pResultado, char mensaje[]);

/// \brief Castea la cadena de char a float
/// \param pResultado float*
/// \return int Return (-1) si la cadena no pudo castearse con exito  - (0) si esta Ok
int CastearAFlotante (float* pResultado);


/// \brief Verifica que la cadena posea solo numeros y puedan ser flotantes
/// \param cadena char*
/// \return int Return (-1) si hay la cadena tiene letras o signos, excepto el "-" - (0) si esta Ok
int LaCadenaEsFlotante(char* cadena);

#endif /* INPUT_H_ */
