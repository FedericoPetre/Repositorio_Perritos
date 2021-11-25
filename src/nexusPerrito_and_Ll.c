/*
 * nexusEmployee_and_Ll.c
 *
 *  Created on: 12 nov. 2021
 *      Author: Federico Petre
 */

#include "nexusPerrito_and_Ll.h"

/**
 * @fn int nexusPerrito_and_Ll_findPerritoByID(LinkedList*)
 * @brief Para retorna el indice del linkedlist donde se encuentra el perrito con el id ingresado por parametro(si existe).
 *
 * @param this LinkedList*
 * @param id int
 * @return Retorna -1 si no encuentra un perrito registrado con el id ingresado (o parametro this NULL). Caso contrario retorna el indice en el que se encuentra el perrito con ese id dentro del LinkedList.
 */
int nexusPerrito_and_Ll_findPerritoByID(LinkedList* this, int id)
{
	int indexPerrito = -1;
	int tamList = -1;

	if(this != NULL)
	{
		tamList = ll_len(this);
		for(int j =0; j< tamList; j++)
		{
			perrito* pPerritoABuscar = ll_get(this, j);

			if(pPerritoABuscar->id == id)
			{
				indexPerrito = j;
				break;
			}
			pPerritoABuscar = NULL;
		}
	}

	return indexPerrito;
}

/**
 * @fn int nexusPerrito_and_Ll_findLastID(LinkedList* this)
 * @brief Para retornar el ultimo id que se encuentra en el LinkedList (del ultimo perrito registrado)
 *
 * @param this LinkedList*
 * @return Retorna -1 si el LinkedList está vacio (NULL) o no encuentra ultimo ID. Caso contrario retorna el mayor ID escrito en la lista.
 */
int nexusPerrito_and_Ll_findLastID(LinkedList* this)
{
	int ultimoID;
	int tamList;

	int mayorId;

	if(this != NULL)
	{
		tamList = ll_len(this);
		for(int i=0; i<tamList; i++)
		{
			perrito* pPerrito = ll_get(this, i);
			if(pPerrito != NULL)
			{
				perrito_getId(pPerrito, &ultimoID);
			}

			if(i==0 || ultimoID > mayorId)
			{
				mayorId = ultimoID;
			}

		}
	}
	return mayorId;
}

/**
 * @fn perrito* nexusPerrito_and_Ll_getPerritos(LinkedList* this)
 * @brief Para retornar un puntero a perritos que contenga los perritos que posee el linkedlist
 *
 * @param this LinkedList*
 * @return Retorna un puntero perrito cargado con los perritos del linkedlist (si el linkedList esta vacio retorna un puntero vacio)
 */
perrito* nexusPerrito_and_Ll_getPerritos(LinkedList* this)
{
	int tamLinkedList;
	int i;

	tamLinkedList = ll_len(this);
	perrito* pPerritosRetorno = NULL;

	if(this != NULL)
	{
		perrito* pPerritos = NULL;
		pPerritos = (perrito*) malloc(sizeof(perrito)*tamLinkedList);

		for(i=0; i<tamLinkedList; i++)
		{
			perrito* pPerrito = ll_get(this, i);
			if(pPerrito != NULL)
			{
				*(pPerritos + i) = *pPerrito;
			}
			pPerrito = NULL;
		}
		pPerritosRetorno = pPerritos;
	}
	return pPerritosRetorno;
}



