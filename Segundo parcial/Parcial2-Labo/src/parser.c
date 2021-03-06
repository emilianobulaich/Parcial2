#include <stdio.h>
#include <stdlib.h>

#include "Libro.h"
#include "Editorial.h"
#include "LinkedList.h"
#include "parser.h"
/** \brief Parsea los datos los datos de los libros desde el archivo de libros (modo texto).
 *
 * \param pFile FILE*
 * \param pArrayListBook LinkedList*
 * \return int  (-1) Error: en caso de que algun puntero sea NULL o no se haya podido a?adir los elementos a la lista
 *               (0) Si esta ok
 *
 */
int parser_BookFromText(FILE* pFile, LinkedList* pArrayListBook)
{
	int retorno = -1;

	eLibro* pLibro;

	char id[128];
	char titulo[128];
	char autor[128];
	char precio[128];
	char idEditorial[128];

	if(pFile != NULL &&  pArrayListBook!= NULL){

		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, autor, precio, idEditorial);
		while(!feof(pFile)){

			fscanf(pFile,"%[^,], %[^,], %[^,],%[^,],%[^\n]\n", id, titulo, autor, precio, idEditorial);
			printf("%s - %s - %s - %s - %s\n", id, titulo, autor, precio, idEditorial);
			pLibro = book_newParametros(id, titulo, autor, precio, idEditorial);

			if(pLibro != NULL){
				if(ll_add(pArrayListBook,pLibro) == -1){
					puts("Error");

				}else{

					retorno = 0;
				}
			}
		}
	}
	return retorno;
}


/** \brief Parsea los datos los datos de las editoriales desde el archivo de editoriales (modo texto).
 *
 * \param pFile FILE*
 * \param pArrayListEditorial LinkedList*
 * \return int  (-1) Error: en caso de que algun puntero sea NULL o no se haya podido a?adir los elementos a la lista
 *               (0) Si esta ok
 *
 */
int parser_EditorialFromText(FILE* pFile, LinkedList* pArrayListEditorial)
{
	int retorno = -1;

	eEditorial* pEditorial;

	char idEditorial[128];
	char nombre[128];

	if(pFile != NULL &&  pArrayListEditorial!= NULL){
		fscanf(pFile, "%[^,],%[^\n]\n",idEditorial, nombre);
		while(!feof(pFile)){

			fscanf(pFile, "%[^,],%[^\n]\n",idEditorial, nombre);
			printf("%s - %s\n",idEditorial, nombre);
			pEditorial = editorial_newParametros(idEditorial, nombre);

			if(pEditorial != NULL){
				if(ll_add(pArrayListEditorial,pEditorial) == -1){
					puts("Error");

				}else{
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}
