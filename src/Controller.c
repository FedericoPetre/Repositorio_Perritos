#include "Controller.h"
#include "parser.h"


/** \brief Carga los datos de los perritos desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPerrito LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPerrito)
{
	FILE* pFile = NULL;
	pFile = fopen(path, "r");

	int estado = 1;
	int retornoParser;

	if(pFile != NULL && pArrayListPerrito != NULL)
	{
		retornoParser = parser_EmployeeFromText(pFile , pArrayListPerrito);
	}

	fclose(pFile);

	if(retornoParser == 0)
	{
		printf("Se cargaron los datos exitosamente desde el archivo, en modo texto\n");
		estado = 0;
	}
	else
	{
		printf("Error al cargar los datos desde el archivo en modo texto\n");
	}

    return estado;
}

/** \brief Carga los datos de los perritos desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPerrito LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPerrito)
{
	int retorno = 1;

	FILE* pFile = NULL;
	pFile = fopen(path, "rb");

	if(pFile != NULL && pArrayListPerrito != NULL)
	{
		retorno = parser_EmployeeFromBinary(pFile, pArrayListPerrito);
	}
	fclose(pFile);

	if(retorno == 0)
	{
		printf("Se cargaron los datos desde el archivo, modo binario\n");
	}


    return retorno;
}

/** \brief Alta de perritos
 *
 * \param path char*
 * \param pArrayListPerrito LinkedList*
 * \return int
 *
 */
int controller_addPerrito(LinkedList* pArrayListPerrito)
{
	int retorno = 1;

	int nuevoID;
	char nuevoIDTransformado[20];
	char nombrePerrito[30];
	int edad;
	char edadTransformada[30];
	char razaPerrito[30];
	int ultimoID;

	char* letraRespuesta = (char*) malloc(sizeof(char));

	perrito* pNuevoPerrito;

	if(pArrayListPerrito != NULL)
	{
		ultimoID = nexusEmployee_and_Ll_findLastID(pArrayListPerrito);
		nuevoID = ultimoID + 1;
		itoa(nuevoID, nuevoIDTransformado, 10);

		funciones_imput_pedirYValidarCadena("Ingrese nombre del nuevo perrito\n", "Error, reingrese nombre del nuevo perrito (solo letras, espacios o guiones)\n", 127, nombrePerrito);

		funciones_imput_pedirYValidarEntero("Ingrese edad del nuevo perrito(0-50)\n", "Error, reingrese edad del nuevo perrito (min: 0. max: 50)\n", 0, 50, &edad);
		itoa(edad, edadTransformada, 10);

		funciones_imput_pedirYValidarCadena("Ingrese raza del nuevo perrito\n", "Error, reingrese raza del nuevo perrito (solo letras, espacios o guiones)\n", 127, razaPerrito);

		pNuevoPerrito = perrito_nuevoParametros(nuevoIDTransformado, nombrePerrito, edadTransformada, razaPerrito);

		printf("Mostrando nuevo perrito:\n%-5s %-12s %-16s %-9s\n", "ID", "NOMBRE", "EDAD", "RAZA");
		employee_showEmpleado(pNuevoPerrito);
		funciones_imput_pedirYValidarCaracter("Desea agregar este perrito al sistema? (s: si, n: no)\n", "Error, esta seguro de agregar este perrito al sistema? (s: si, n: no) (ingrese una de las dos letras)\n", letraRespuesta);
		if(*letraRespuesta == 's')
		{
			ll_add(pArrayListPerrito, pNuevoPerrito);
			retorno = 0;
		}
		else
		{
			printf("Se ha cancelado el alta del perrito\n");
		}
	}

    return retorno;
}

/** \brief Modificar datos de perrito
 *
 * \param path char*
 * \param pArrayListPerrito LinkedList*
 * \return int
 *
 */
int controller_editPerrito(LinkedList* pArrayListPerrito)
{
	int estado = 1;
	int opcion = -1;

	char* nombreAux = (char*) malloc(sizeof(char)*128);
	int* edadAux = (int*) malloc(sizeof(int));
	char* razaAux = (char*) malloc(sizeof(char)*128);

	char* letraRespuesta = (char*) malloc(sizeof(char));
	int* pNumeroPedido = (int*) malloc(sizeof(int));

	perrito* pPerritoAux = (perrito*) malloc(sizeof(perrito));
	int indexPerrito;

	funciones_imput_pedirYValidarEntero("Ingrese el id del perrito a modificar datos", "Error, ingrese el id del perrito a modificar datos (solo numeros)", 1, 999999, pNumeroPedido);

	indexPerrito = nexusEmployee_and_Ll_findEmployeeByID(pArrayListPerrito, *pNumeroPedido);

		if(indexPerrito != -1)
		{
			perrito* pPerrito = ll_get(pArrayListPerrito, indexPerrito);
			printf("Se encontro el perrito\nMostrando datos...\n");
			printf("%-5s %-12s %-16s %-9s\n", "ID", "NOMBRE", "EDAD", "RAZA");
			perrito_mostrarPerrito(pPerritoAux);
			perrito_setId(pPerritoAux,*pNumeroPedido);
			perrito_setNombre(pPerritoAux, pPerrito->nombre);
			perrito_setEdad(pPerritoAux, pPerrito->edad);
			perrito_setRaza(pPerritoAux, pPerrito->raza);


			funciones_imput_pedirYValidarEntero("Que dato desea modificar?\n1- Nombre\n2- Edad\n3- Raza\n4- Atras\n", "Error al elejir opcion, reingrese (opc: 1, opc: 2, opc: 3, opc: 4):\n1- Nombre\n2- Edad\n3- Raza\n4- Atras\n", 1, 4, &opcion);
			switch(opcion)
			{
			case 1:
				printf("Elejiste modificar nombre\n");
				funciones_imput_pedirYValidarCadena("Ingrese nuevo nombre\n", "Error, reingrese nuevo nombre (letras, espacios y guiones solamente)\n", 128, nombreAux);
				perrito_setNombre(pPerritoAux, nombreAux);
				printf("Mostrando Datos modificados:\n%-5s %-12s %-16s %-9s\n", "ID", "NOMBRE", "EDAD", "RAZA");
				perrito_mostrarPerrito(pPerritoAux);
				funciones_imput_pedirYValidarCaracter("Desea guardar la modificacion? (s: si, n: no)\n", "Error, desea guardar la modificacion anterior al perrito? (s: si, n: no) (ingrese una de las dos letras)\n", letraRespuesta);
				if(*letraRespuesta == 's')
				{
					ll_set(pArrayListPerrito, indexPerrito, pPerritoAux);
					printf("Modificacion guardada con exito\n");
					estado = 0;
				}
				else
				{
					printf("Se ha cancelado la modificacion\n");
				}
				break;
			case 2:
				printf("Elejiste modificar edad del perrito\n");
				funciones_imput_pedirYValidarEntero("Ingrese nueva edad del perrito (min: 0 max: 50)\n","Error. reingrese nueva edad (min: 0 max: 50)\n", 0, 50, edadAux);
				employee_setHorasTrabajadas(pPerritoAux,*edadAux);
				printf("Mostrando Datos modificados:\n%-5s %-12s %-16s %-9s\n", "ID", "NOMBRE", "EDAD", "RAZA");
				perrito_mostrarPerrito(pPerritoAux);
				funciones_imput_pedirYValidarCaracter("Desea guardar la modificacion? (s: si, n: no)\n", "Error, desea guardar la modificacion anterior al perrito? (s: si, n: no) (ingrese una de las dos letras)\n", letraRespuesta);
				if(*letraRespuesta == 's')
				{
					ll_set(pArrayListPerrito, indexPerrito, pPerritoAux);
					printf("Modificacion guardada con exito\n");
					estado = 0;
				}
				else
				{
					printf("Se ha cancelado la modificacion\n");
				}

				break;
			case 3:
				printf("Elejiste modificar raza\n");
				funciones_imput_pedirYValidarCadena("Ingrese nueva raza\n", "Error, reingrese nueva raza (letras, espacios y guiones solamente)\n", 128, razaAux);
				perrito_setRaza(pPerritoAux, razaAux);
				printf("Mostrando Datos modificados:\n%-5s %-12s %-16s %-9s\n", "ID", "NOMBRE", "EDAD", "RAZA");
				perrito_mostrarPerrito(pPerritoAux);
				funciones_imput_pedirYValidarCaracter("Desea guardar la modificacion? (s: si, n: no)\n", "Error, desea guardar la modificacion anterior al perrito? (s: si, n: no) (ingrese una de las dos letras)\n", letraRespuesta);
				if(*letraRespuesta == 's')
				{
					ll_set(pArrayListPerrito, indexPerrito, pPerritoAux);
					printf("Modificacion guardada con exito\n");
					estado = 0;
				}
				else
				{
					printf("Se ha cancelado la modificacion\n");
				}

				break;
			case 4:
				printf("Elejiste volver al menu principal\n");
				break;
			}
		}
		else
		{
			printf("Error, no se ha encontrado ningun perrito con ese id\n");
		}
	return estado;
}



/** \brief Baja de perrito
 *
 * \param path char*
 * \param pArrayListPerrito LinkedList*
 * \return int
 *
 */
int controller_removePerrito(LinkedList* pArrayListPerrito)
{
	int* idPerrito = (int*)malloc(sizeof(int));
	int indexPerrito;
	int retorno = 1;

	char* respuesta = (char*)malloc(sizeof(char));

	perrito* pPerritoBuscado = NULL;

	if(pArrayListPerrito != NULL)
	{
		funciones_imput_pedirYValidarEntero("Ingrese el id del perrito a eliminar del sistema\n", "Error, reingrese el id del perrito a eliminar del sistema\n", 1, 999999, idPerrito);

		indexPerrito = nexusEmployee_and_Ll_findEmployeeByID(pArrayListPerrito, *idPerrito);

		if(indexPerrito != -1)
		{
			printf("Perrito encontrado\n");
			pPerritoBuscado = ll_get(pArrayListPerrito, indexPerrito);

			printf("%-5s %-12s %-16s %-9s\n", "ID", "NOMBRE", "EDAD", "RAZA");
			employee_showEmpleado(pPerritoBuscado);

			funciones_imput_pedirYValidarCaracter("Esta seguro que desea eliminar este perrito del sistema? (s: si, n: no)\n", "Error, esta seguro que desea eliminar este perrito del sistema? (s: si, n: no) (ingrese una de las dos letras)\n", respuesta);

			if(*respuesta == 's')
			{
				ll_remove(pArrayListPerrito, indexPerrito);
				printf("Perrito dado de baja del sistema exitosamente\n");
				retorno = 0;
			}
			else
			{
				printf("Se ha cancelado la baja del perrito del sistema\n");
			}
		}
		else
		{
			printf("Error, no se ha encontrado ningun perrito con ese id\n");
		}
	}
    return retorno;
}

/** \brief Listar perritos
 *
 * \param path char*
 * \param pArrayListPerrito LinkedList*
 * \return int
 *
 */
int controller_ListPerrito(LinkedList* pArrayListPerrito)
{
	int tamArrayPerritos;
	tamArrayPerritos = ll_len(pArrayListPerrito);

	perrito* pPerritos = NULL;
	pPerritos = (perrito*) malloc (sizeof(perrito)*tamArrayPerritos);

	if(pArrayListPerrito != NULL && tamArrayPerritos > 0)
	{
		pPerritos = nexusEmployee_and_Ll_getEmployees(pArrayListPerrito);

		for(int j=0; j<tamArrayPerritos; j++)
		{
			if(j==0)
			{
				printf("%-5s %-12s %-16s %-9s\n", "ID", "NOMBRE", "EDAD", "RAZA");
			}
			perrito_mostrarPerrito((pPerritos + j));
		}
	}

    return 1;
}

/** \brief Ordenar perritos
 *
 * \param path char*
 * \param pArrayListPerrito LinkedList*
 * \return int
 *
 */
int controller_sortPerritos(LinkedList* pArrayListPerrito)
{
	int retorno = 1;
	int opcion = -1;
	int opcionOrden = 1;
	int orden = -1;

	int (*funcionQueCompara)(void* this1, void* this2);

	if(pArrayListPerrito != NULL)
	{
		funciones_imput_pedirYValidarEntero("Ingrese opcion de ordenamiento:\n1-Ordenar por ID\n2-Ordenar por nombre\n3-Ordenar por edad\n4-Ordenar por raza\n", "Error, reongrese opcion de ordenamiento (1-4):\n1-Ordenar por ID\n2-Ordenar por nombre\n3-Ordenar por edad\n4-Ordenar por raza\n", 1, 4, &opcion);

		switch(opcion)
		{
		case 1:
			printf("Has elejido la opcion 1-Ordenar por ID\n");
			funciones_imput_pedirYValidarEntero("Ingrese modo de ordenar:\n1-Ordenar ascendentemente (menor ID a mayor ID)\n2-Ordenar descendentemente (mayor ID a menor ID)\n","Error, reingrese modo de ordenar (1 o 2):\n1-Ordenar ascendentemente (menor ID a mayor ID)\n2-Ordenar descendentemente (mayor ID a menor ID)\n", 1, 2, &opcionOrden);
			funcionQueCompara = perrito_comparateByID;
			switch(opcionOrden)
			{
			case 1:
				printf("Has elejido la opcion 1-Ordenar por ID ascendentemente (menor ID a mayor ID)\n");
				orden = 0;
				break;
			case 2:
				printf("Has elejido la opcion 2-Ordenar por ID descendentemente (mayor ID a menor ID)\n");
				orden = 1;
				break;
			}
			break;
		case 2:
			printf("Has elejido la opcion 2-Ordenar por nombre\n");
			funciones_imput_pedirYValidarEntero("Ingrese modo de ordenar:\n1-Ordenar ascendentemente (A-Z)\n2-Ordenar descendentemente (Z-A)\n","Error, reingrese modo de ordenar (1 o 2):\n1-Ordenar ascendentemente (A-Z)\n2-Ordenar descendentemente (Z-A)\n", 1, 2, &opcionOrden);
			funcionQueCompara = perrito_comparateByNombre;
			switch(opcionOrden)
			{
			case 1:
				printf("Has elejido la opcion 1-Ordenar por nombre ascendentemente (A-Z)\n");
				orden = 0;
				break;
			case 2:
				printf("Has elejido la opcion 2-Ordenar por nombre descendentemente (Z-A)\n");
				orden = 1;
				break;
			}
			break;
		case 3:
			printf("Has elejido la opcion 3-Ordenar por edad\n");
			funciones_imput_pedirYValidarEntero("Ingrese modo de ordenar:\n1-Ordenar ascendentemente (menor edad a mayor edad)\n2-Ordenar descendentemente (mayor edad a menor edad)\n","Error, reingrese modo de ordenar (1 o 2):\n1-Ordenar ascendentemente (menor edad a mayor edad)\n2-Ordenar descendentemente (mayor edad a menor edad)\n", 1, 2, &opcionOrden);
			funcionQueCompara = perrito_comparateByEdad;
			switch(opcionOrden)
			{
			case 1:
				printf("Has elejido la opcion 1-Ordenar ascendentemente (menor edad a mayor edad)\n");
				orden = 0;
				break;
			case 2:
				printf("Has elejido la opcion 2-Ordenar descendentemente (mayor edad a menor edad)\n");
				orden = 1;
				break;
			}
			break;
		case 4:
			printf("Has elejido la opcion 4-Ordenar por raza\n");
			funciones_imput_pedirYValidarEntero("Ingrese modo de ordenar:\n1-Ordenar ascendentemente (raza A-Z)\n2-Ordenar descendentemente (raza Z-A)\n","Error, reingrese modo de ordenar (1 o 2):\n1-Ordenar ascendentemente (raza A-Z)\n2-Ordenar descendentemente (raza Z-A)\n", 1, 2, &opcionOrden);
			funcionQueCompara = perrito_comparateByRaza;
			switch(opcionOrden)
			{
			case 1:
				printf("Has elejido la opcion 1-Ordenar por raza ascendentemente (A-Z)\n");
				orden = 0;
				break;
			case 2:
				printf("Has elejido la opcion 2-Ordenar por raza descendentemente (Z-A)\n");
				orden = 1;
				break;
			}
			break;
		}
		printf("Ordenando empleados...\nPor favor, espere mientras se ordena: este proceso puede demorar algunos segundos\n");

		ll_sort(pArrayListPerrito, funcionQueCompara, orden);
		printf("Empleados ordenados con exito\n");
		retorno = 0;
	}

    return retorno;
}

/** \brief Guarda los datos de los perritos en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPerrito LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPerrito)
{
	FILE* pFile = NULL;
	pFile = fopen(path, "w");

	if(pFile != NULL)
	{
		fprintf(pFile,"%s,%s,%s,%s\n", "ID", "NOMBRE", "EDAD", "RAZA");
		fclose(pFile);
	}

	FILE* pFile1 = NULL;
	pFile1 = fopen(path, "a");
	int i;
	int tamLinkedList;

	if(pFile1 != NULL && pArrayListPerrito != NULL)
	{

		tamLinkedList = ll_len(pArrayListPerrito);

		for(i=0; i<tamLinkedList; i++)
		{
			perrito* pPerrito = ll_get(pArrayListPerrito, i);

			if(pPerrito != NULL)
			{
				fprintf(pFile,"%d,%s,%d,%s\n", pPerrito->id, pPerrito->nombre, pPerrito->edad, pPerrito->raza);
			}
			pPerrito = NULL;

		}
		fclose(pFile1);
		printf("El archivo fue guardado exitosamente\n");
	}
    return 1;
}

/** \brief Guarda los datos de los perritos en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPerrito LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPerrito)
{
	int retorno = 1;

	FILE* pFile = NULL;
	pFile = fopen(path, "wb");

	int tamLinkedList;

	if(pFile != NULL && pArrayListPerrito != NULL)
	{
		tamLinkedList = ll_len(pArrayListPerrito);

		for(int i=0; i<tamLinkedList; i++)
		{
			perrito* pPerrito = ll_get(pArrayListPerrito, i);

			if(pPerrito != NULL)
			{
				fwrite(pPerrito, sizeof(perrito), 1, pFile);
				retorno = 0;
			}
			pPerrito = NULL;

		}
		fclose(pFile);
		printf("El archivo fue guardado exitosamente\n");
	}
    return retorno;
}

