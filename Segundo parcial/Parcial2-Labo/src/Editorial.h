#ifndef EDITORIAL_H_
#define EDITORIAL_H_

typedef struct{
	int idEditorial;
	char nombre[128];
}eEditorial;

eEditorial* editorial_new();
eEditorial* editorial_newParametros(char* idStr, char* nombreStr);

void editorial_delete(eEditorial* this);

int editorial_setId(eEditorial* this,int id);
int editorial_getId(eEditorial* this,int* id);

int editorial_setNombre(eEditorial* this,char* nombre);
int editorial_getNombre(eEditorial* this,char* nombre);


#endif /* EDITORIAL_H_ */
