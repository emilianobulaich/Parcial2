#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Input.h"
#include "Libro.h"
#include "Menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main(){
		setbuf(stdout,NULL);

        LinkedList* listaLibros = ll_newLinkedList();
        LinkedList* listaEditoriales = ll_newLinkedList();

        int option;
        int opcionArchivo;

        int flagBooks = 0;
        int flagEditorial = 0;
        char archivoLibros[128];
        char archivoEditoriales[128];

        do
        {
            Menu();

            ObtenerEnteroEntreRango(&option,"\nOpcion: ",1,10,3);

            switch(option)
            {
            case 1:

                if(flagBooks== 0){
                	ObtenerString("Ingrese el archivo de libros a cargar (incluir formato ej: .csv)", archivoLibros,sizeof(archivoLibros),3);

                    if(controller_loadBookText(archivoLibros,listaLibros) == 0){
                        printf("\nArchivo cargado exitosamente.\n\n");
                        flagBooks=1;
                    }
                    else{
                        printf("\nEl archivo no ha podido ser cargado.\n\n");
                    }

                }
                else{
					ObtenerEnteroEntreRango(&opcionArchivo,"Ya hay un archivo cargado �Desea abrir este, y cerrar el otro? 1-Si 2-No.",1,2,3);

					if(opcionArchivo == 1){
						ll_clear(listaLibros);
						if(controller_loadBookText("dataLibros.csv",listaLibros) == 0){
							printf("\nArchivo cargado exitosamente.\n\n");
						}
						else{
							printf("\nEl archivo no ha podido ser cargado.\n\n");
						}
					}
				}
                break;

           case 2:

        	   if(flagEditorial == 0){

				   ObtenerString("Ingrese el archivo de editoriales a cargar (incluir formato ej: .csv)", archivoEditoriales,sizeof(archivoEditoriales),3);

				   if(controller_loadEditorialText(archivoEditoriales,listaEditoriales) == 0){

					   printf("\nArchivo cargado exitosamente.\n\n");
					   flagEditorial=1;
				   }
				   else{
					   printf("\nEl archivo no ha podido ser cargado.\n\n");
				   }

			   }
			   else{

					ObtenerEnteroEntreRango(&opcionArchivo,"Ya hay un archivo cargado �Desea abrir este, y cerrar el otro? 1-Si 2-No.",1,2,3);

					if(opcionArchivo == 1){

						ll_clear(listaEditoriales);

						if(controller_loadEditorialText("dataEditoriales.csv",listaEditoriales) == 0){

							printf("\nArchivo cargado exitosamente.\n\n");
						}
						else{

							printf("\nEl archivo no ha podido ser cargado.\n\n");
						}
					}
			   }
			   break;

           case 3:
            	if(flagBooks== 1 && flagEditorial == 1){

            		if(controller_sortBooks(listaLibros) == 0){

						printf("\nLista ordenada correctamente.\n\n");
					}
					else{

						printf("\nNo se pudo ordenar la lista.\n\n");
					}
            	}
            	else{
            		printf("\nAntes de ordenar la lista necesita cargar ambas listas. \n\n");
            	}

                break;

            case 4:
            	if(flagBooks == 1 && flagEditorial == 1 ){

				 controller_List(listaLibros,listaEditoriales);

            	}
            	else{
            		printf("\nAntes de listar, necesita cargar ambas listas \n\n");
            	}

                break;

            case 5:
            	if(flagBooks== 1 && flagEditorial == 1)
            	{
					if(controller_listEditorialMinotauro(listaLibros,listaEditoriales) != 0){

						 printf("\nNo se pudo listar los libros.\n\n");
					}
            	}
            	else{
					printf("\nAntes de listar, necesita cargar ambas listas \n\n");
				}
                break;

            case 6:

                printf("\nSaliendo...\n\n");
                break;

            default:
                printf("Error. Usted eligio una opcion invalida.\n");
            }

        }
        while(option != 6);

   return 0;
}

