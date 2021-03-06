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



/** \brief Muestra la lista(modo texto).
 *
 * \param pArrayListBook LinkedList*
 * \param pArrayListEditorial LinkedList*
 * \return int (-1) Error: Si algun puntero es NULL
 *              (0) Si esta ok
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
	        printf("\n\nID\t                       TITULO \t             AUTOR   \t           PRECIO            \t EDITORIAL \n\n");


	        for(int i=0; i < ll_len(pArrayListBook); i++) {
	        	pLibro = ll_get(pArrayListBook,i);
	        	book_getId(pLibro,&id);
	            book_getTitulo(pLibro, titulo);
	            book_getAutor(pLibro, autor);
	            book_getPrecio(pLibro,&precio);
	            book_getIdEditorial(pLibro,&idEditorial);

	            retorno = controller_getEditorialNameById(pArrayListEditorial,idEditorial,nombre);

	            printf("%d  %30s  %25s  %15.2f %25s \n\n", id, titulo, autor, precio,nombre);
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

/** \brief Obtiene el nombre de la edotorial a trav?s del id(modo texto).
 *
 * \param pArrayListBook LinkedList*
 * \param id int
 * \param nombreEditorial char*
 * \return int (-1) Error: Si algun puntero es NULL
 *              (0) Si esta ok
 *
 */
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
/** \brief Obtiene el nombre de la edotorial a trav?s del id(modo texto).
 *
 * \param pArrayListBook LinkedList*
 * \param id int
 * \param nombreEditorial char*
 * \return int (-1) Error: Si algun puntero es NULL
 *              (0) Si esta ok
 *
 */
int controller_FindMinotauro( void* element ){

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
//----------------------------------------------------------------------------------------
int controller_listEditorialMinotauro(LinkedList* pArrayBookList, LinkedList* pArrayEditorialList){

	LinkedList* nuevaLista;

	int retorno = -1;

	if(pArrayBookList != NULL && pArrayEditorialList != NULL){
		nuevaLista = ll_newLinkedList();

		nuevaLista = ll_filter(pArrayBookList, controller_FindMinotauro);
		if(nuevaLista != NULL){
			retorno = controller_List(nuevaLista,pArrayEditorialList);
		}
	}

	return retorno;
}

//----------------------------------------------------------------------------------------

void* controller_buscarPosicionDescuento( void* element ){

    eLibro* newElement;

    int idObtenido;
    float precio;

    if(element != NULL){
       newElement = element;

		if(newElement!= NULL ){

			book_getIdEditorial(newElement, &idObtenido);
            book_getPrecio(newElement,&precio);
			if(idObtenido == 1 && precio > 300){

			   precio = precio - (precio*20/100);
			   book_setPrecio(newElement, precio);
			}
			if(idObtenido == 2 && precio <= 200){
				precio = precio - (precio*10/100);
				book_setPrecio(newElement, precio);
			}
		}

    }

    return newElement;
}
//----------------------------------------------------------------------------------------

int controller_descuento(LinkedList* pArrayListLibro, LinkedList* pArrayListEditorial){

    int retorno = -1;

    LinkedList* NuevaLista;

    NuevaLista = ll_newLinkedList();

    if(NuevaLista != NULL){


        NuevaLista = ll_map( pArrayListLibro, controller_buscarPosicionDescuento);

            if(NuevaLista != NULL){
            	controller_saveBookAsText("mapeado.csv", NuevaLista);
                retorno = controller_List(NuevaLista,pArrayListEditorial);
            }

    }

    return retorno;
}

//----------------------------------------------------------------------------------------
int controller_saveBookAsText(char* path, LinkedList* pArrayListLibro){
	    FILE* pArchivo;
	    eLibro* pLibro;

	    int retorno = -1;
	    int id;
	    int i;
	    char titulo[128];
	    char autor[128];
	    float precio;
	    int idEditorial;

	    if(path != NULL && pArrayListLibro != NULL && ll_isEmpty(pArrayListLibro) == 0){

	    	pArchivo = fopen(path, "w");

	        fprintf(pArchivo,"id,titulo,autor,precio,idEditorial\n");}
	        for(i=0; i< ll_len(pArrayListLibro); i++) {
	        	pLibro = ll_get(pArrayListLibro,i);
	        	if(pLibro == NULL){
	        		break;
	        	}
	            book_getId(pLibro,&id);
	            book_getAutor(pLibro, autor);
	            book_getTitulo(pLibro, titulo);
	            book_getPrecio(pLibro, &precio);
	            book_getIdEditorial(pLibro, &idEditorial);
	            fprintf(pArchivo,"%d,%s,%s,%f,%d\n",id,autor,titulo,precio,idEditorial);
	        }

	        fclose(pArchivo);
	        if(ll_len(pArrayListLibro) == i ){
	        	retorno = 0;
	        }
	    return retorno;
}


//----------------------------------------------------------------------------------------
int controller_saveEditorialAsText(char* path, LinkedList* pArrayListEditorial){
	    FILE* pArchivo;
	    eEditorial* pEditorial;

	    int retorno = -1;
	    int id;
	    int i;
	    char nombre[128];


	    if(path != NULL && pArrayListEditorial != NULL && ll_isEmpty(pArrayListEditorial) == 0){

	    	pArchivo = fopen(path, "w");

	        fprintf(pArchivo,"idEditorial,nombre\n");}
	        for(i=0; i< ll_len(pArrayListEditorial); i++) {
	        	pEditorial = ll_get(pArrayListEditorial,i);
	        	if(pEditorial == NULL){
	        		break;
	        	}
	            editorial_getId(pEditorial, &id);
	            editorial_getNombre(pEditorial, nombre);
	            fprintf(pArchivo,"%d,%s\n",id,nombre);
	        }

	        fclose(pArchivo);
	        if(ll_len(pArrayListEditorial) == i ){
	        	retorno = 0;
	        }
	    return retorno;
}

int controller_countMayorA500( void* element){
	 eLibro* pLibro;

	 int retorno = 0;
	 float precio;
	 pLibro = element;

    if(pLibro != NULL){
        book_getPrecio(pLibro, &precio);
        if(precio > 500){
			retorno = 1;
		}
    }
    return retorno;

}

int controller_mostrarMayorA500(LinkedList* pArrayBookList){

	int retorno = -1;
    int minotauro;
	if(pArrayBookList != NULL){

		minotauro = ll_count(pArrayBookList, controller_countMayorA500);
		if(minotauro != -1){
			 retorno = 0;
			 printf("La cantidad de editoriales de precio mayor a 500 es de: %d\n",minotauro);
		}else{
			puts("Error en el controller");
		}


    }
	return retorno;
}
float controller_buscarPrecioPearson( void* element ){

    eLibro* nuevalista;
    float retorno = -1;
    float precio;
    int idEditorial;
	nuevalista = element;
	if( nuevalista != NULL ){
    retorno = 0;
	book_getIdEditorial(nuevalista, &idEditorial);
		if(idEditorial == 3 ){
		  book_getPrecio(nuevalista, &precio);
		  retorno = precio;
		}
	}

    return retorno;
}

float controller_SumaPearson(LinkedList* pArrayBookList ){
	float retorno;
	retorno = ll_countFloat(pArrayBookList, controller_buscarPrecioPearson);
	printf("La suma de los precios de los libros de la editorial Pearson es de : %.2f\n",retorno);
	return retorno;

}
