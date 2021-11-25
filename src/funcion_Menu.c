/*
 * funcion_Menu.c
 *
 *  Created on: 13 nov. 2021
 *      Author: Federico Petre
 */

#include "funcion_Menu.h"

void funcionMenu(void)
{
	setbuf(stdout, NULL);
    int option = 0;

    LinkedList* listaPerritos = ll_newLinkedList();

    int banderaPerritosModoTexto = 0;
    int banderaPerritosModoBinario = 0;
    int cantidadPerritos = 0;
    int flagCambiarionDatos = 0;
    char respuesta;


    do{
    	funciones_imput_pedirYValidarEntero("Ingrese opcion:\n1-Cargar los datos de los perritos(modo texto)\n2-Cargar los datos de los perritos(modo binario)\n3-Alta perrito\n4-Modificar datos de perrito\n5-Baja de perrito\n6-Listar perritos\n7-Ordenar perritos\n8-Guardar los datos de los perritos(modo texto)\n9-Guardar los datos de los perritos(modo binario)\n10-Salir\n", "Error, opcion no valida, reingrese opcion:\n1-Cargar los datos de los perritos(modo texto)\n2-Cargar los datos de los perritos(modo binario)\n3-Alta perrito\n4-Modificar datos de perrito\n5-Baja de perrito\n6-Listar perritos\n7-Ordenar perritos\n8-Guardar los datos de los perritos(modo texto)\n9-Guardar los datos de los perritos(modo binario)\n10-Salir\n", 1, 10, &option);

    	switch(option)
        {
            case 1:
            	printf("Elejiste la opcion 1-Cargar los datos de los perritos(modo texto)\n");
            	if(banderaPerritosModoBinario == 1)
            	{
            		printf("Error al cargar los datos modo texto: los datos de los perritos ya estan cargados en modo binario\n");
            	}
            	else
            	{
                    controller_loadFromText("data.csv",listaPerritos);
                    cantidadPerritos = ll_len(listaPerritos);
                    banderaPerritosModoTexto = 1;
            	}
                break;
            case 2:
            	printf("Elejiste la opcion 2-Cargar los datos de los perritos(modo binario)\n");
            	if(banderaPerritosModoTexto == 1)
            	{
            		printf("Error al cargar los datos modo binario: los datos de los perritos ya estan cargados en modo texto\n");
            	}
            	else
            	{
            		controller_loadFromBinary("dataBinario.csv",listaPerritos);
            		cantidadPerritos = ll_len(listaPerritos);
            		banderaPerritosModoBinario = 1;
            	}
                break;
            case 3:
            	printf("Elejiste la opcion 3-Alta perrito\n");
            	if(banderaPerritosModoTexto != 1 && banderaPerritosModoBinario != 1)
            	{
            		printf("Error al elegir alta perrito, lista de perritos sin cargar en texto ni binario\n");
            	}
            	else
            	{
            		if(controller_addEmployee(listaPerritos) == 0)
            		{
            			printf("perrito dado de alta con exito\n");
            			flagCambiarionDatos = 1;
            			cantidadPerritos++;
            		}
            		else
            		{
            			printf("Error al dar de alta al nuevo perrito\n");
            		}
            	}

                break;
            case 4:
            	printf("Elejiste la opcion 4-Modificar datos de perrito\n");
            	if(banderaPerritosModoTexto != 1 && banderaPerritosModoBinario != 1)
            	{
            		printf("Error al elegir modificación, no hay perritos cargados en el sistema\n");
            	}
            	else
            	{
            		controller_editEmployee(listaPerritos);
            		flagCambiarionDatos = 1;
            	}
                break;
            case 5:
            	printf("Elejiste la opcion 5-Baja de perrito\n");
            	if(banderaPerritosModoTexto == 1 || banderaPerritosModoBinario == 1)
            	{
            		controller_removeEmployee(listaPerritos);
            		cantidadPerritos--;
            		flagCambiarionDatos = 1;
            	}
            	else
            	{
            		printf("Error al elegir baja perrito, lista vacia\n");
            	}
                break;
            case 6:
            	printf("Elejiste la opcion 6-Listar perritos\n");
            	if((banderaPerritosModoTexto == 1 && cantidadPerritos != 0)|| (banderaPerritosModoBinario == 1 && cantidadPerritos != 0))
            	{
            		printf("Mostrando lista de perritos...\n");
                	controller_ListEmployee(listaPerritos);
            	}
            	else
            	{
            		printf("Error al listar los perritos, lista vacia\n");
            	}
                break;
            case 7:
            	printf("Elejiste la opcion 7-Ordenar perritos\n");
            	if(banderaPerritosModoTexto != 1 && banderaPerritosModoBinario != 1)
            	{
            		printf("Error al ordenar, no hay perritos cargados en el sistema\n");
            	}
            	else
            	{
            		controller_sortEmployee(listaPerritos);
            		flagCambiarionDatos = 1;
            	}


                break;
            case 8:
            	printf("Elejiste la opcion 8-Guardar los datos de los perritos(modo texto)\n");
            	if(banderaPerritosModoTexto != 1 && banderaPerritosModoBinario != 1)
            	{
            		printf("Error, no hay perritos cargados en el sistema\n");
            	}
            	else
            	{
            		if(banderaPerritosModoTexto != 1 && banderaPerritosModoBinario == 1)
            		{
            			printf("Error al guardar modo texto: los datos de los perritos estan cargados en modo binario\n");
            		}
            		else
            		{
            			if(banderaPerritosModoTexto == 1 && banderaPerritosModoBinario != 1)
            			{
                    		controller_saveAsText("data.csv",listaPerritos);
            			}
            		}
            	}
                break;
            case 9:
            	printf("Elejiste la opcion 9-Guardar los datos de los perritos(modo binario)\n");
            	if(banderaPerritosModoTexto != 1 && banderaPerritosModoBinario != 1)
            	{
            		printf("Error, no hay perritos cargados en el sistema\n");
            	}
            	else
            	{
            		if(banderaPerritosModoTexto == 1 && banderaPerritosModoBinario != 1)
            		{
            			printf("Error al guardar en modo binario: los datos de los perritos estan cargados en modo texto\n");
            		}
            		else
            		{
            			if(banderaPerritosModoTexto != 1 && banderaPerritosModoBinario == 1)
            			{
                    		controller_saveAsBinary("dataBinario.csv",listaPerritos);
            			}
            		}
            	}
                break;
            case 10:
            	printf("Elejiste la opcion 10-Salir\n");

            	if(flagCambiarionDatos == 1)
            	{
            		funciones_imput_pedirYValidarCaracter("Esta seguro de que desea salir? (s: si, n: no)\nTodos los cambios que no fueron guardados se perderan\n", "Error, esta seguro de que desea salir? (opc 's': si, opc 'n': no)\nTodos los cambios que no fueron guardados se perderan\n", &respuesta);
            		if(respuesta == 's')
            		{
            			printf("Saliendo del sistema...\n");
            			ll_deleteLinkedList(listaPerritos);
            			printf("Has salido del sistema\n");
            		}
            		else
            		{
            			option = 0;
            			printf("Elejiste no salir\nVolviendo al menu principal...\n");
            		}
            	}
            	else
            	{
            		printf("Saliendo del sistema...\nHas salido del sistema\n");
            	}
                break;
            default:
            	printf("Error - Opcion no válida, reingrese opcion\n");
            	break;
        }

        if(option!=10)
        {
        	system("pause");
        }

    }while(option != 10);

}

