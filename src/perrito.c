/*
 * perrito.c
 *
 *  Created on: 25 nov. 2021
 *      Author: Federico Petre
 */

#include "perrito.h"


/**
 * @fn perrito* nuevo_perrito()
 * @brief Para retornar un puntero a una posición de memoria libre de una variable de tipo perrito
 *
 * @return
 */
perrito* nuevo_perrito()
{
	perrito* pPerrito = NULL;
	pPerrito = (perrito*) malloc(sizeof(perrito));

	return pPerrito;
}

/**
 * @fn perrito* perrito_nuevoParametros(char* id,char* nombre,char* edad, char* raza)
 * @brief Retornar un puntero a perrito con los parametros ingresados cargados en la direccion de memoria apuntada por el puntero
 *
 * @param id Parametro ID (por puntero)
 * @param nombre Parametro Nombre (por puntero)
 * @param edad Parametro horas trabajadas (por puntero)
 * @param raza Parametro raza(por puntero)
 * @return
 */
perrito* perrito_nuevoParametros(char* id,char* nombre,char* edad, char* raza)
{
	perrito* punteroAPerrito = NULL;
	punteroAPerrito = nuevo_perrito();

	int idTransformado;
	int edadTransformada;
	int retornoRaza;
	int retornoNombre;

	idTransformado = funciones_imput_transformarAEntero(id);
	retornoNombre = funciones_imput_verificarCadena(nombre);
	edadTransformada = funciones_imput_transformarAEntero(edad);
	retornoRaza = funciones_imput_verificarCadena(raza);

	if(punteroAPerrito != NULL && id != NULL && nombre != NULL && edad != NULL && raza != NULL)
	{
		if(retornoNombre == -1)
		{
			perrito_setNombre(punteroAPerrito,nombre);
		}
		else
		{
			printf("Error al cargar el nombre al nuevo perrito\n(solo letras)\n");
		}

		if(retornoRaza == -1)
		{
			perrito_setRaza(punteroAPerrito, raza);
		}
		else
		{
			printf("Error al cargar la raza al nuevo perrito\n");
		}

		if(edadTransformada != -1)
		{
			perrito_setEdad(punteroAPerrito, edadTransformada);
		}
		else
		{
			printf("Error al cargar la edad al nuevo perrito\n");
		}

		if(idTransformado != -1)
		{
			perrito_setId(punteroAPerrito, idTransformado);
		}
		else
		{
			printf("Error al cargar el ID al nuevo perrito\n");
		}

	}

	return punteroAPerrito;
}

/**
 * @fn void perrito_eliminarPerrito(perrito* this)
 * @brief Para eliminar los datos del puntero empleado ingresado (limpiar la memoria//liberarla)
 *
 * @param this parametro perrito* puntero a eliminar
 */
void perrito_eliminarPerrito(perrito* this)
{
	if(this != NULL)
	{
		free(this);
		this = NULL;
	}
}

/**
 * @fn int perrito_setId(perrito* this,int id)
 * @brief Para asignarle un ID al campo ID del parametro perrito pasado por puntero
 *
 * @param this parametro perrito pasado por puntero
 * @param id ID a asignar al parametro perrito
 * @return Retorna 0 en caso de que el parametro this sea NULL y no poder asignar ID, caso contrario retorna 1
 */
int perrito_setId(perrito* this,int id)
{
	int retorno = 0;

	if(this != NULL)
	{
		this->id = id;
		retorno = 1;
	}
	return retorno;
}

/**
 * @fn int perrito_getId(perrito* this,int* id)
 * @brief Para obtener el ID del parámetro perrito pasado por referencia (puntero)
 *
 * @param this Parametro perrito al cual se le tomara el valor ID
 * @param id puntero a ID que será retornado
 * @return Retorna 0 si this es NULL y id es NULL (parametros inválidos). Retorna 1 caso contrario, y el ID lo devolverá por el referencia id.
 */
int perrito_getId(perrito* this,int* id)
{
	int retorno = 0;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 1;
	}
	return retorno;
}

/**
 * @fn int perrito_setNombre(perrito* this,char* nombre)
 * @brief Para asignar un nombre al parámetro perrito ingresado (con el parámetro nombre)
 *
 * @param this parametro perrito ingresado
 * @param nombre Nombre a asignar al perrito ingresado
 * @return Retorna 0 si this es NULL o Nombre es NULL (o ambos). Caso contrario pudo asignar el nombre y retorna 1.
 */
int perrito_setNombre(perrito* this,char* nombre)
{
	int retorno = 0;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 1;
	}
	return retorno;
}

/**
 * @fn int perrito_getNombre(perrito* this,char* nombre)
 * @brief Para retornar el nombre del perrito this a través del puntero nombre
 *
 * @param this perrito* perrito al cual se obtiene el nombre
 * @param nombre char* se retorna por este puntero el nombre del perrito
 * @return Retorna 0 si hay error (this NULL). Caso contrario retorna 1 y devuelve el nombre por puntero nombre
 */
int perrito_getNombre(perrito* this,char* nombre)
{
	int retorno = 0;

	if(this != NULL)
	{
		nombre = this->nombre;
		retorno = 1;
	}
	return retorno;
}

/**
 * @fn int perrito_setEdad(perrito* this,int edad)
 * @brief Para asignarle edad a un perrito
 *
 * @param this perrito* perrito al cual se le asignan la edad
 * @param edad int, edad a asignar
 * @return Retorna 0 si hay error (this NULL o edad inválida). Retorna 1 si la pudo asignar.
 */
int perrito_setEdad(perrito* this,int edad)
{
	int retorno = 0;

	if(this != NULL && edad > -1)
	{
		this->edad = edad;
		retorno = 1;
	}
	return retorno;
}

/**
 * @fn int perrito_getEdad(perrito* this,int* edad)
 * @brief Para retornar la edad de un perrito
 *
 * @param this *perrito perrito al cual se obtienen su edad
 * @param edad int* puntero, a través de el se retornan la edad del empleado
 * @return Retorna 0 si hay algun parametro invalido (this NULL). Si pudo devolver la edad retorna 1.
 */
int perrito_getEdad(perrito* this,int* edad)
{
	int retorno = 0;

	if(this != NULL)
	{
		*edad = this->edad;
		retorno = 1;
	}
	return retorno;
}

/**
 * @fn int perrito_setRaza(perrito* this,char* raza)
 * @brief Para asignarle la raza al perrito ingresado como parametro.
 *
 * @param this perrito* perrito ingresado
 * @param raza char*. raza a asignar
 * @return Retorna 0 si hay algun parametro invalido (this NULL o raza NULL). Caso contrario asigna la raza y retorna 1.
 */
int perrito_setRaza(perrito* this,char* raza)
{
	int retorno = 0;

	if(this != NULL && raza != NULL)
	{
		strcpy(this->raza, raza);
		retorno = 1;
	}
	return retorno;
}

/**
 * @fn int perrito_getRaza(perrito* this,char* raza)
 * @brief Para obtener la raa del perrito ingresado
 *
 * @param this perrito* perrito ingresado a traves de un puntero
 * @param raza char* se guarda la raza del perrito y se retorna por este puntero
 * @return Retorna 0 si el parametro this es NULL. Caso contrario retorna 1 y la raza a traves del puntero raza.
 */
int perrito_getRaza(perrito* this,char* raza)
{
	int retorno = 0;

	if(this != NULL)
	{
		raza = this -> raza;
		retorno = 1;
	}
	return retorno;
}

/**
 * @fn int perrito_mostrarPerrito(perrito* this)
 * @brief Para mostrar los datos de la estructura perrito ingresada
 *
 * @param this perrito* perrito ingresado a traves de un puntero
 * @return Retorna 0 si el parametro this es NULL. Caso contrario retorna 1.
 */
int perrito_mostrarPerrito(perrito* this)
{
	int retorno= 0;

	if(this != NULL)
	{
		printf("%-5d %-12s %-10d %-12s\n", this->id, this->nombre, this->edad, this->raza);
		retorno = 1;
	}
	return retorno;
}

/**
 * @fn int perrito_comparateByID(void* this1, void* this2)
 * @brief Para comparar los IDS de los perritos ingresados a traves de punteros void (se castean a perrito dentro de la funcion)
 *
 * @param this1 void*
 * @param this2 void*
 * @return Retorna -1 si el id del perrito casteado de this1 es mayor que el de this2. Retorna 0 si son iguales. Retorna 1 si el de this2 es mayor.
 */
int perrito_comparateByID(void* this1, void* this2)
{
	int retorno;

	perrito* pPerritoAux1;
	perrito* pPerritoAux2;

	if(this1 != NULL && this2 != NULL)
	{
		pPerritoAux1 = (perrito*) this1;
		pPerritoAux2 = (perrito*) this2;

		if((pPerritoAux1->id) > (pPerritoAux2->id))
		{
			retorno = -1;
		}
		else
		{
			if((pPerritoAux1->id) == (pPerritoAux2->id))
			{
				retorno = 0;
			}
			else
			{
				retorno = 1;
			}
		}
	}
	return retorno;
}


/**
 * @fn int perrito_comparateByNombre(void* this1, void* this2)
 * @brief Para comparar los nombres de los perritos ingresados a traves de punteros void (se castean a employee dentro de la funcion)
 *
 * @param this1 void*
 * @param this2 void*
 * @return Retorna 1 si el nombre de this1 casteado a perrito esta antes alfabeticamente. Retorna 0 si es igual al de this2. Retorna -1 si está despues alfabeticamente.
 */
int perrito_comparateByNombre(void* this1, void* this2)
{
	int retorno;
	int retornoComparacion;

	perrito* pPerritoAux1;
	perrito* pPerritoAux2;

	if(this1 != NULL && this2 != NULL)
	{
		pPerritoAux1 = (perrito*) this1;
		pPerritoAux2 = (perrito*) this2;

		retornoComparacion = strcmp((pPerritoAux1)->nombre, (pPerritoAux2)->nombre);

		if(retornoComparacion == -1)
		{
			retorno = 1;
		}
		else
		{
			if(retornoComparacion == 0)
			{
				retorno = 0;
			}
			else
			{
				retorno = -1;
			}
		}

	}
	return retorno;
}

/**
 * @fn int perrito_comparateByEdad(void* this1, void* this2)
 * @brief Para comparar la edad de los perritos ingresados a traves de punteros void (se castean a perrito dentro de la funcion)
 *
 * @param this1 void*
 * @param this2 void*
 * @return Retorna -1 si la edad del perrito casteado de this1 es mayor que el de this2. Retorna 0 si son iguales. Retorna 1 si la de this2 es mayor.
 */
int perrito_comparateByEdad(void* this1, void* this2)
{
	int retorno;

	perrito* pPerritoAux1;
	perrito* pPerritoAux2;

	if(this1 != NULL && this2 != NULL)
	{
		pPerritoAux1 = (perrito*) this1;
		pPerritoAux2 = (perrito*) this2;

		if((pPerritoAux1->edad) > (pPerritoAux2->edad))
		{
			retorno = -1;
		}
		else
		{
			if((pPerritoAux1->edad) == (pPerritoAux2->edad))
			{
				retorno = 0;
			}
			else
			{
				retorno = 1;
			}
		}
	}
	return retorno;
}

/**
 * @fn int perrito_comparateByRaza(void* this1, void* this2)
 * @brief Para comparar la raza de los perritos ingresados a traves de punteros void (se castean a employee dentro de la funcion)
 *
 * @param this1 void*
 * @param this2 void*
 * @return Retorna 1 si la raza de this1 casteado a perrito esta antes alfabeticamente. Retorna 0 si es igual al de this2. Retorna -1 si está despues alfabeticamente.
 */
int perrito_comparateByRaza(void* this1, void* this2)
{
	int retorno;

	perrito* pPerritoAux1;
	perrito* pPerritoAux2;

	int retornoComparacion;

	if(this1 != NULL && this2 != NULL)
	{
		pPerritoAux1 = (perrito*) this1;
		pPerritoAux2 = (perrito*) this2;

		retornoComparacion = strcmp((pPerritoAux1)->raza, (pPerritoAux2)->raza);

		if(retornoComparacion == -1)
		{
			retorno = 1;
		}
		else
		{
			if(retornoComparacion == 0)
			{
				retorno = 0;
			}
			else
			{
				retorno = -1;
			}
		}

	}
	return retorno;
}



