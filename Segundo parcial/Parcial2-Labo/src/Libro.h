#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct{
	int id;
	char titulo[128];
	char autor[128];
	float precio;
	int idEditorial;
}eLibro;

eLibro* book_new();
eLibro* book_newParametros(char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* idEditorialStr);
void book_delete(eLibro* this);

int book_setId(eLibro* this,int id);
int book_getId(eLibro* this,int* id);

int book_setTitulo(eLibro* this,char* titulo);
int book_getTitulo(eLibro* this,char* titulo);

int book_setAutor(eLibro* this,char* autor);
int book_getAutor(eLibro* this,char* autor);

int book_setPrecio(eLibro* this,float precio);
int book_getPrecio(eLibro* this,float* precio);

int book_setIdEditorial(eLibro* this,int idEditorial);
int book_getIdEditorial(eLibro* this,int* idEditorial);

int book_orderByAutor(void* firstAutor, void* secondAutor);

#endif // employee_H_INCLUDED
