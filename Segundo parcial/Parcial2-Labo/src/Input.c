#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "Input.h"


float IngresarFlotanteEntreRango(char mensaje[] ,float numMin ,float numMax){
	setbuf(stdout, NULL);

	float num;

	do{
	puts(mensaje);
	fflush(stdin);
	scanf("%f",&num);
	}while(num < numMin || num > numMax);

    return num;
}


int ObtenerString(char mensaje[], char cadena[], int tam, int reintentos) {

    int retorno = 0;
    char auxiliarString[500];
    int verificar;
        if (cadena != NULL && mensaje != NULL){
       reintentos+=1;

       do{
        	puts(mensaje);
			fflush(stdin);
			scanf("%s",auxiliarString);

			verificar = LaCadenaEsString(auxiliarString);
			if(verificar == -1){

					retorno = -1;
					reintentos--;
					if(reintentos == 0){
						printf("Se ha quedado sin intentos\n");
						break;
					}else{
						printf("Ha cometido un error, le quedan %d intentos restantes\n",reintentos);
					}



			}

		}while(verificar == -1 );

        }
        strncpy(cadena,auxiliarString,tam);

    return retorno;

}
int LaCadenaEsString(char* cadena){
	int retorno = 0;

	for(int i=0; cadena[i]!='\0';i++){

		if(cadena[i]<='9' && cadena[i]>='0'){
			retorno = -1;
			break;
		}
	}

	return retorno;
}
int ObtenerEnteroMayorACero(int* pResultado, char mensaje[], int reintentos){
	int retorno = -1;
	int auxiliarInt;
	int respuesta;

	if(pResultado!=NULL && mensaje!=NULL){
		reintentos+=1;
		do{
			printf("%s",mensaje);

			respuesta = CastearAEntero(&auxiliarInt);
			if(auxiliarInt < 0){
				respuesta = -1;
			}
			if(respuesta==0){
				*pResultado = auxiliarInt;
				retorno = 0;
			}else{

				reintentos--;
				if(reintentos == 0){
					printf("Se ha quedado sin intentos\n");
					break;
				}else{
					printf("Ha cometido un error, le quedan %d intentos restantes\n",reintentos);
				}
			}

		}while(respuesta!=0 && auxiliarInt <= 0);
	}

		return retorno;
	}
int ObtenerEntero(int* pResultado, char mensaje[], int reintentos){
	int retorno = -1;
	int auxiliarInt;
	int respuesta;

	if(pResultado!=NULL && mensaje!=NULL){
		reintentos+=1;
		do{
			printf("%s",mensaje);

			respuesta = CastearAEntero(&auxiliarInt);
			if(respuesta==0){
				*pResultado = auxiliarInt;
				retorno = 0;
			}else{

				reintentos--;
				if(reintentos == 0){
					printf("Se ha quedado sin intentos\n");
					break;
				}else{
					printf("Ha cometido un error, le quedan %d intentos restantes\n",reintentos);
				}
			}

		}while(respuesta!=0);
	}

	return retorno;
}
int ObtenerEnteroEntreRango(int* pResultado, char mensaje[], int min, int max, int reintentos){
	int retorno = -1;
	int auxiliarInt;
	int respuesta;

	if(pResultado!=NULL && mensaje!=NULL){
		reintentos+=1;
		do{
			printf("%s",mensaje);

			respuesta = CastearAEntero(&auxiliarInt);
			if(respuesta==0 && auxiliarInt >=min && auxiliarInt <=max){
				*pResultado = auxiliarInt;
				retorno = 0;
			}else{
				reintentos--;
				if(reintentos == 0){
					printf("Se ha quedado sin intentos\n");
					break;
				}else{



				printf("Ha cometido un error, le quedan %d intentos restantes\n",reintentos);
				}
			}

		}while(respuesta!=0 || auxiliarInt < min || auxiliarInt > max);
	}

	return retorno;
}

int CastearAEntero(int* pResultado){
	int retorno = -1;
	char auxiliarIngresado[1000];

	fflush(stdin);
	scanf("%s",auxiliarIngresado);

	if(LaCadenaEsNumerica(auxiliarIngresado)){
		retorno = 0;
		*pResultado = atoi(auxiliarIngresado);
	}
	return retorno;
}

int LaCadenaEsNumerica(char* cadena){
	int retorno = -1;
	int i=0;

	if(cadena[0]=='-'){
		i=1;
	}

	for(; cadena[i]!='\0';i++){

		if(cadena[i]>'9' || cadena[i]<'0'){
			retorno = 0;
			break;
		}
	}

	return retorno;
}

float ObtenerFlotante(float* pResultado, char mensaje[]){
	int retorno = -1;
	float auxiliarFloat;
	int respuesta;

	if(pResultado != NULL && mensaje != NULL){
		do{
			printf("%s",mensaje);

			respuesta = CastearAFlotante(&auxiliarFloat);
			if(respuesta==0){
				*pResultado = auxiliarFloat;
				retorno = 0;
			}
		}while(respuesta!=0);
	}
	return retorno;
}

int CastearAFlotante (float* pResultado){
	int retorno = -1;
	char auxiliarIngresado[1000];

	fflush(stdin);
	scanf("%s",auxiliarIngresado);

	if(LaCadenaEsFlotante(auxiliarIngresado)){
		retorno = 0;
		*pResultado = atof(auxiliarIngresado);
	}
	return retorno;
}

int LaCadenaEsFlotante(char* cadena){
	int retorno = -1;
	int i=0;

	if(cadena[0]=='-'){
		i=1;
	}

	for(; cadena[i]!='\0';i++){

		if(cadena[i]>'9' || cadena[i]<'0'){
			if(cadena[i]!='.'){
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}


