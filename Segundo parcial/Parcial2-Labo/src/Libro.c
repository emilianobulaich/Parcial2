#include "Libro.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
eLibro* book_new()
{
	eLibro* newBook;
    newBook = (eLibro*)malloc(sizeof(eLibro));

    if(newBook != NULL)
    {
    	newBook->id = 0;
        strcpy(newBook->titulo, " ");
        strcpy(newBook->autor, " ");
        newBook->precio = 0;
        newBook->idEditorial = 0;
    }

    return newBook;
}
eLibro* book_newParametros(char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* idEditorialStr)
{
	eLibro* newBook;
	newBook = book_new();

    int id;
    float precio;
    int idEditorial;

    if(idStr != NULL && tituloStr != NULL && autorStr != NULL && precioStr != NULL && idEditorialStr != NULL  && newBook != NULL ){
		id= atoi(idStr);
		precio= atof(precioStr);
		idEditorial= atoi(idEditorialStr);

		book_setId(newBook, id);
		book_setAutor(newBook, autorStr);
		book_setTitulo(newBook, tituloStr);
		book_setPrecio(newBook, precio);
		book_setIdEditorial(newBook, idEditorial);

    }

    return newBook;
}
void book_delete(eLibro* this){

	if(this!=NULL){
		free(this);
	}

}
int book_setId(eLibro* this,int id){
	int retorno;
	retorno = -1;
	if(this!= NULL && id>=0){
        this->id = id;
        retorno = 0;
	}
	return retorno;
}

int book_getId(eLibro* this,int* id){
	int retorno;
	retorno = -1;
	if(this!= NULL && id!= NULL){
	       *id = this->id;
	        retorno = 0;
		}
	return retorno;
}
int book_setTitulo(eLibro* this,char* titulo){
	int retorno;
	retorno = -1;
	if(this!= NULL){

	      strcpy(this->titulo , titulo);
	      this->titulo[0] = toupper(this->titulo[0]);

	      retorno = 0;
	}
	return retorno;
}
int book_getTitulo(eLibro* this,char* titulo){
	int retorno;
	retorno = -1;
	if(this!= NULL && titulo!= NULL){

		  strcpy(titulo,this->titulo);


		  retorno = 0;
	}
	return retorno;
}
int book_setAutor(eLibro* this,char* autor){
	int retorno;
	retorno = -1;
	if(this!= NULL){

	      strcpy(this->autor , autor);
	      this->autor[0] = toupper(this->autor[0]);

	      retorno = 0;
	}
	return retorno;
}
int book_getAutor(eLibro* this,char* autor){
	int retorno;
	retorno = -1;
	if(this!= NULL && autor!= NULL){
		  strcpy(autor, this->autor);
		  retorno = 0;
		}
	return retorno;
}

int book_setPrecio(eLibro* this,float precio){
	int retorno;
	retorno = -1;
	if(this!= NULL){
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}
int book_getPrecio(eLibro* this,float* precio){
	int retorno;
	retorno = -1;
	if(this!= NULL && precio!= NULL){
		   *precio = this->precio;
			retorno = 0;
		}
	return retorno;
}
int book_setIdEditorial(eLibro* this, int idEditorial){
	int retorno;
		retorno = -1;
		if(this!= NULL){
	        this->idEditorial=idEditorial;
	        retorno = 0;
		}
		return retorno;
}
int book_getIdEditorial(eLibro* this, int* idEditorial){
	int retorno;
		retorno = -1;
		if(this!= NULL && idEditorial!= NULL){
	        *idEditorial=this->idEditorial;
	        retorno = 0;
		}
		return retorno;
}
int book_orderByAutor(void* firstAutor, void* secondAutor){
	int retorno = -1;
	char primerNombre[128];
    char segundoNombre[128];

    if(firstAutor != NULL && secondAutor != NULL){
    	book_getAutor(firstAutor,  primerNombre);
    	book_getAutor(secondAutor, segundoNombre);
		retorno = strcmp(primerNombre, segundoNombre);
    }

    return retorno;
}

