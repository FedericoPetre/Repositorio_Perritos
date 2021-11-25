/*
 * nexusEmployee_and_Ll.c
 *
 *  Created on: 12 nov. 2021
 *      Author: Federico Petre
 */

#include "nexusEmployee_and_Ll.h"

/**
 * @fn int nexusEmployee_and_Ll_findEmployeeByID(LinkedList*)
 * @brief Para retorna el indice del linkedlist donde se encuentra el empleado con el id ingresado por parametro(si existe).
 *
 * @param this LinkedList*
 * @param id int
 * @return Retorna -1 si no encuentra un empleado registrado con el id ingresado (o parametro this NULL). Caso contrario retorna el indice en el que se encuentra el empleado con ese id dentro del LinkedList.
 */
int nexusEmployee_and_Ll_findEmployeeByID(LinkedList* this, int id)
{
	int indexEmpleado = -1;
	int tamListEmployee = -1;

	if(this != NULL)
	{
		tamListEmployee = ll_len(this);
		for(int j =0; j< tamListEmployee; j++)
		{
			Employee* pEmpleadoABuscar = ll_get(this, j);

			if(pEmpleadoABuscar->id == id)
			{
				indexEmpleado = j;
				break;
			}
			pEmpleadoABuscar = NULL;
		}
	}

	return indexEmpleado;
}

/**
 * @fn int nexusEmployee_and_Ll_findLastID(LinkedList* this)
 * @brief Para retornar el ultimo id que se encuentra en el LinkedList (del ultimo empleado)
 *
 * @param this LinkedList*
 * @return Retorna -1 si el LinkedList está vacio (NULL) o no encuentra ultimo ID. Caso contrario retorna el ultimo ID escrito en la lista.
 */
int nexusEmployee_and_Ll_findLastID(LinkedList* this)
{
	int ultimoID;
	int tamList;

	int mayorId;

	if(this != NULL)
	{
		tamList = ll_len(this);
		for(int i=0; i<tamList; i++)
		{
			Employee* pEmpleado = ll_get(this, i);
			if(pEmpleado != NULL)
			{
				employee_getId(pEmpleado, &ultimoID);
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
 * @fn Employee* nexusEmployee_and_Ll_getEmployees(LinkedList* this)
 * @brief Para retornar un puntero a empleados que contenga los empleados que posee el linkedlist
 *
 * @param this LinkedList*
 * @return Retorna un puntero empleados cargado con los empleados del linkedlist (si el linkedList esta vacio retorna un puntero vacio)
 */
Employee* nexusEmployee_and_Ll_getEmployees(LinkedList* this)
{
	int tamLinkedList;
	int i;

	tamLinkedList = ll_len(this);
	Employee* pEmpleadosRetorno = NULL;

	if(this != NULL)
	{
		Employee* pEmpleados = NULL;
		pEmpleados = (Employee*) malloc(sizeof(Employee)*tamLinkedList);

		for(i=0; i<tamLinkedList; i++)
		{
			Employee* pEmpleado = ll_get(this, i);
			if(pEmpleado != NULL)
			{
				*(pEmpleados + i) = *pEmpleado;
			}
			pEmpleado = NULL;
		}
		pEmpleadosRetorno = pEmpleados;
	}
	return pEmpleadosRetorno;
}



