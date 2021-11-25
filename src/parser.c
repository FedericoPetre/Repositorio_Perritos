#include "parser.h"

/** \brief Parsea los datos de los perritos desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPerrito LinkedList*
 * \return int
 *
 */
int parser_PerritoFromText(FILE* pFile , LinkedList* pArrayListPerrito)
{
	int estado = 1;

	char id[20];
	char nombre[30];
	char edad[20];
	char raza[30];

	if(pFile != NULL)
	{
		fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^\n]", id, nombre, edad, raza);
		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^\n]", id, nombre, edad, raza);
			if(feof(pFile) != 0)
			{
				break;
			}

			perrito* pPerrito = perrito_nuevoParametros(id, nombre, edad, raza);

			ll_add(pArrayListPerrito, pPerrito);
			pPerrito = NULL;
		}
		estado = 0;
		fclose(pFile);
	}

	return estado;
}

/** \brief Parsea los datos de los perritos desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_PerritoFromBinary(FILE* pFile , LinkedList* pArrayListPerrito)
{
	int estado = 1;

	if(pFile != NULL)
	{
		while(!feof(pFile))
		{
			perrito* punteroAPerrito = nuevo_perrito();
			fread(punteroAPerrito, sizeof(perrito), 1, pFile);

			if(feof(pFile) == 0)
			{
				ll_add(pArrayListPerrito, punteroAPerrito);
			}
			punteroAPerrito = NULL;
		}
		estado = 0;
		fclose(pFile);
	}

	return estado;
}
