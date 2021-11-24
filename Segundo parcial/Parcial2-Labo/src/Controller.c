#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "Input.h"
#include "Libro.h"
#include "Editorial.h"
#include "Controller.h"

/** \brief Carga los datos de los libros desde el archivo de libros(modo texto).
 *
 * \param path char*
 * \param pArrayListBook LinkedList*
 * \return int (-1) Error: Si algun puntero es NULL
 *              (0) Si esta ok
 *
 */
int controller_loadBookText(char* path , LinkedList* pArrayListBook)
{
       int retorno = -1;
       FILE* pArchivo;
       if(path!= NULL && pArrayListBook != NULL){
			pArchivo = fopen(path,"r");
			if(pArchivo!=NULL){

				if(parser_BookFromText(pArchivo, pArrayListBook) == 0){

					retorno = 0;
				}
			}else{
				puts("Archivo no encontrado");
			}
			fclose(pArchivo);
       }
       return retorno;

}
/** \brief Carga los datos de las editoriales desde el archivo de editoriales(modo texto).
 *
 * \param path char*
 * \param pArrayListEditorial LinkedList*
 * \return int (-1) Error: Si algun puntero es NULL
 *              (0) Si esta ok
 *
 */
int controller_loadEditorialText(char* path , LinkedList* pArrayListEditorial)
{
       int retorno = -1;
       FILE* pArchivo;
       if(path!= NULL && pArrayListEditorial != NULL){

			pArchivo = fopen(path,"r");
			if(pArchivo!=NULL){

				if(parser_EditorialFromText(pArchivo, pArrayListEditorial) == 0){

					retorno = 0;
				}
			}else{
				puts("Archivo no encontrado");
			}
			fclose(pArchivo);
       }
       return retorno;

}

/** \brief Listar libros
 *
 * \param path char*
 * \param pArrayListBook LinkedList*
 * \param pArrayListEditorial LinkedList*
 * \return int (-1) Error: Si algun puntero es NULL
 *  o el IdEditoriales de editoriales no son los mismos que el IdEditoriales del archivo de libros
 *             (0) Si esta ok
 *
 */
int controller_List(LinkedList* pArrayListBook, LinkedList* pArrayListEditorial)
{

		int retorno = -1;
		eLibro* pLibro;


	    int id;
	    char titulo[128];
	    char autor[128];
	    float precio;
	    int idEditorial;

        char nombre[128];

	    if(pArrayListBook != NULL && ll_len(pArrayListBook) > 0  &&
	       pArrayListEditorial != NULL && ll_len(pArrayListEditorial) > 0)
	    {
	        printf("\n\nID\t TITULO \t AUTOR   \t PRECIO      \t EDITORIAL \n\n");


	        for(int i=0; i < ll_len(pArrayListBook); i++) {
	        	pLibro = ll_get(pArrayListBook,i);
	        	book_getId(pLibro,&id);
	            book_getTitulo(pLibro, titulo);
	            book_getAutor(pLibro, autor);
	            book_getPrecio(pLibro,&precio);
	            book_getIdEditorial(pLibro,&idEditorial);

	            retorno = controller_getEditorialNameById(pArrayListEditorial,idEditorial,nombre);

	            printf("%d  %10s  %15s  %15.2f %25s \n\n", id, titulo, autor, precio,nombre);
	        }
	    }
	    return retorno;

}

/** \brief Ordenar libros por autores
 *
 * \param pArrayListBook LinkedList*
 * \return int (-1) Error: Si el puntero a la lista es NULL o si no se pudo ordenar
 *             (0) Si esta ok
 *
 */
int controller_sortBooks(LinkedList* pArrayListBook)
{
   int retorno = -1;


   if(pArrayListBook != NULL){

		   if(ll_sort(pArrayListBook,book_orderByAutor,1) == 0){
			   retorno = 0;
		   }
   }
	return retorno;

}


int controller_getEditorialNameById(LinkedList* pArrayEditorial, int id, char* nombreEditorial){
	eEditorial* pEditorial;
	int retorno = -1;
    int idObtenido;

    if(pArrayEditorial != NULL && id >=0 && nombreEditorial != NULL){
    	for(int i = 0; i< ll_len(pArrayEditorial); i++){
    			pEditorial = ll_get(pArrayEditorial, i);
    			editorial_getId(pEditorial ,&idObtenido);
    			if(idObtenido == id){
    				editorial_getNombre(pEditorial,nombreEditorial);
    				retorno = 0;
    			}
    	}

    }
		return retorno;
}

int FindMinotauro( void* element ){

    eLibro* pLibro;

    pLibro = element;


    int retorno = -1;
    int idObtenido;

	if(pLibro!= NULL ){

		book_getIdEditorial(pLibro, &idObtenido);

		if(idObtenido == 4){
			retorno = 0;
		}
    }
    return retorno;
}
int controller_listEditorialMinotauro(LinkedList* pArrayBookList, LinkedList* pArrayEditorialList){

	LinkedList* nuevaLista;

	int retorno = -1;

	if(pArrayBookList != NULL && pArrayEditorialList != NULL){
		nuevaLista = ll_newLinkedList();

		nuevaLista = ll_filter(pArrayBookList, FindMinotauro);
		if(nuevaLista != NULL){
			retorno = controller_List(nuevaLista,pArrayEditorialList);
		}
	}

	return retorno;
}

/*
int controller_LastIdSaved(char* path){

	 int retorno = -1;
	 FILE* pArchivo;
	 pArchivo = fopen(path,"r");
		if(path!= NULL){
		if(pArchivo != NULL ){

				 retorno = parserLastIdFromText(pArchivo);

			 }
		}


     fclose(pArchivo);
	 return retorno;

}
int controller_LoadNextId(LinkedList* pArrayListBook){
    eLibro* pLibro;

    int id = -1;
    int idController;
    int aux;
    int len;
    int flag = 1;

    if(pArrayListBook != NULL){
        len = ll_len(pArrayListBook);
        if(len > 0){
            for(int i = 0; i<len; i++){
            	pLibro = (eLibro*)ll_get(pArrayListBook,i);
            	if(pLibro!= NULL){
            		book_getId(pLibro,&aux);

					if(aux > id || flag == 1){
						flag = 0;
						id = aux;
					}
            	}

            }
        }

    }
    idController =  controller_LastIdSaved("dataId.csv");
    if(id < idController){
    	id = idController;
    }
    return id;
}

int controller_saveLastIdAsText(char* path, int id){
	int retorno = -1;
	FILE* pFile;


	   if(path != NULL){

	        pFile = fopen(path,"w");

			fprintf(pFile,"%d\n",id);

	    	fclose(pFile);
	    	retorno = 0;

	    }
	return retorno;
}

*/

/** \brief Guarda los datos de los libros en el archivo (modo texto).
 *
 * \param path char*
 * \param pArrayListBook LinkedList*
 * \return int
 *
 */
/*
int controller_saveAsText(char* path, LinkedList* pArrayListBook){
	    FILE* pArchivo;
	    eLibro* pLibro;


	    int retorno = -1;
	    int i;
	    int id;
	    char autor[128];
	    char titulo[128];
	    float precio;
	    int idEditorial;

	    if(path != NULL && pArrayListBook != NULL && ll_isEmpty(pArrayListBook) == 0){

	    	pArchivo = fopen(path, "w");

	        fprintf(pArchivo,"id,nombre,horasTrabajadas,sueldo\n");

	        for(i=0; i< ll_len(pArrayListBook); i++) {
	        	pLibro = ll_get(pArrayListBook,i);
	        	if(pLibro == NULL){
	        		break;
	        	}

	            book_getId(pLibro,&id);
	            book_getTitulo(pLibro,titulo);
	            book_getAutor(pLibro, autor);
	            book_getPrecio(pLibro,&precio);
	            book_getIdEditorial(pLibro,&idEditorial);
	            fprintf(pArchivo,"%d,%s,%s,%f,%d\n",id,titulo,autor,precio,idEditorial);
	        }

	        fclose(pArchivo);
	        if(ll_len(pArrayListBook) == i ){
	        	retorno = 0;
	        }
	    }
	    return retorno;
}
*/