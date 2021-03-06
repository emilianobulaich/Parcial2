#include "Editorial.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


/** \brief  Inicializa las editoriales
 * \param
 * \return int Retorna  (NULL) Si el puntero a la lista es NULL
                        (La lista inicializada) Si funciono correctamente
 *
 */
eEditorial* editorial_new()
{
	eEditorial* newEditorial;
	newEditorial = (eEditorial*)malloc(sizeof(eEditorial));

    if(newEditorial != NULL)
    {
    	newEditorial->idEditorial = 0;
        strcpy(newEditorial->nombre, " ");
    }

    return newEditorial;
}
/** \brief  Setea el Id y el nombre del editorial , recibido por parametro
 * \param idStr char*
 * \param nombreStr char*
 * \return int Retorna  (NULL) Si algun puntero es NULL
                        (La lista seteada) Si funciono correctamente
 *
 */

eEditorial* editorial_newParametros(char* idStr, char* nombreStr)
{
	eEditorial* newEditorial;
	newEditorial = editorial_new();

    int id;

    if(idStr != NULL &&  nombreStr != NULL && newEditorial != NULL ){
		id= atoi(idStr);

		editorial_setId(newEditorial, id);
		editorial_setNombre(newEditorial, nombreStr);
    }

    return newEditorial;
}
/** \brief  Elimina la lista de la memoria
 * \param this eEditorialr*
 * \return
 *
 */

void editorial_delete(eEditorial* this){

	if(this!=NULL){
		free(this);
	}

}
/** \brief Setea el id en la lista
 * \param this eEditorialr*
 * \param id int
 * \return (-1) Error: Si el puntero a la lista es NULL
 *         (0) Si se pudo setear correctamente el id
 *
 */

int editorial_setId(eEditorial* this,int id){
	int retorno;
	retorno = -1;
	if(this!= NULL && id>=0){
		this->idEditorial = id;
		retorno = 0;
	}
	return retorno;
}

/** \brief Obtiene el id de la lista
 * \param this eEditorialr*
 * \param id int*
 * \return (-1) Error: Si el puntero a la lista es NULL
 *         (0) Si se pudo obtener correctamente el id
 *
 */
int editorial_getId(eEditorial* this,int* id){
    int retorno;
	retorno = -1;
	if(this!= NULL){
		*id  = this->idEditorial;
		retorno = 0;
	}
	return retorno;
}

/** \brief Setea el nombre en la lista
 * \param this eEditorialr*
 * \param nombre char*
 * \return (-1) Error: Si el puntero a la lista es NULL
 *         (0) Si se pudo setear correctamente el nombre
 *
 */

int editorial_setNombre(eEditorial* this,char* nombre){
	int retorno;
	retorno = -1;
	if(this!= NULL){

	  strcpy(this->nombre , nombre);
	  this->nombre[0] = toupper(this->nombre[0]);

	  retorno = 0;
	}
	return retorno;
}

/** \brief Obtiene el nombre de la lista
 * \param this eEditorialr*
 * \param nombre char*
 * \return (-1) Error: Si el puntero a la lista es NULL
 *         (0) Si se pudo obtener correctamente el nombre
 *
 */
int editorial_getNombre(eEditorial* this,char* nombre){
	int retorno;
	retorno = -1;
	if(this!= NULL && nombre != NULL){

	  strcpy(nombre, this->nombre);

	  retorno = 0;
	}
	return retorno;
}

