/*
 * funciones_imput.c
 *
 *  Created on: 7 nov. 2021
 *      Author: Federico Petre
 */

#include "funciones_imput.h"

/**
 * @fn int funciones_imput_cargarEntero(int*, char*, int, int)
 * @brief Pide el ingreso de un numero entero a traves de un puntero, en un rango determinado, y avisa si se pudo cargar o no. En caso de poder cargarlo lo muestra.
 *
 * @param pNumero puntero al numero que se ingresa
 * @param mensaje Mensaje mostrado para ingresar el numero
 * @param min valor minimo del rango
 * @param max valor maximo del rango
 * @return Retorna 0 en caso de no poder cargar el numero, caso contrario devuelve 1
 */
int funciones_imput_cargarEntero(int* pNumero, char* mensaje, int min, int max)
{
	int retorno = 0;
	int numeroValidacion;

	if(pNumero != NULL && mensaje != NULL && min < max)
	{

		printf("%s\n", mensaje);
		fflush(stdin);
		numeroValidacion = scanf("%d", pNumero);

		if(numeroValidacion == 1 && *pNumero>min-1 && *pNumero<max+1)
		{
			retorno= 1;
		}
	}

	return retorno;
}

/**
 * @fn void funciones_imput_pedirYValidarCadena(char*, char*, int, char*)
 * @brief Pide, valida y retorna una cadena de caracteres
 *
 * @param mensaje Mensaje que se muestra para pedir la cadena de caracteres
 * @param mensajeError Mensaje que se muestra en caso de que la cadena de caracteres ingresada no es válida
 * @param max Cantidad máxima de caracteres que puede poseer la cadena
 * @param cadenaDeRetorno Cadena de caracteres que retorna la funcion (a través de un puntero)
 */
void funciones_imput_pedirYValidarCadena(char* mensaje, char* mensajeError, int max, char* cadenaDeRetorno)
{
	char cadenaAux[300];
	int numeroValidacion1;
	int largoCadena;
	int numeroDeValidacion2;

	if(mensaje != NULL && mensajeError != NULL && cadenaDeRetorno != NULL && max>0)
	{
		printf("%s",mensaje);
		fflush(stdin);

		numeroValidacion1 = scanf("%[^\n]", cadenaAux);
		largoCadena = strlen(cadenaAux);
		numeroDeValidacion2 = funciones_imput_verificarCadena(cadenaAux);
		strlwr(cadenaAux);
		cadenaAux[0] = toupper(cadenaAux[0]);

		while(numeroValidacion1 == 0 || largoCadena > max || numeroDeValidacion2 != -1)
		{
			printf("%s",mensajeError);
			fflush(stdin);

			numeroValidacion1 = scanf("%[^\n]", cadenaAux);
			largoCadena = strlen(cadenaAux);
			numeroDeValidacion2 = funciones_imput_verificarCadena(cadenaAux);
			strlwr(cadenaAux);
			cadenaAux[0] = toupper(cadenaAux[0]);
		}
		strcpy(cadenaDeRetorno, cadenaAux);
	}
}

/**
 * @fn int funciones_imput_verificarCadena(char*)
 * @brief Verifica que en todas las posiciones de la cadena no haya ningun caracter no valido (es se verifica que todas sean letra)
 *
 * @param cadena Cadena que se verifica toda sus posiciones
 * @return Si la cadena tiene alguna posicion cargada con un elemento que no sea un caracter, la funcion retorna esa posicion. De lo contrario retorna -1 (OK).
 */
int funciones_imput_verificarCadena(char* cadena)
{
	int index = -1;
	int longitudCadena;
	int i;

	if(cadena != NULL)
	{
		longitudCadena = strlen(cadena);

		for(i=0; i<longitudCadena; i++)
		{
			if(isalpha(cadena[i]) == 0 && cadena[i] != ' ' && cadena[i] != '-')
			{
				index = i;
				break;
			}

		}
	}

	return index;
}

/**
 * @fn int funciones_imput_pedirYValidarEntero(char*, char*, int, int, int*)
 * @brief  pide, valida y retorna un numero entero, en un rango determinado
 *
 * @param mensaje Mensaje mostrado al usuario para pedir el ingreso de un número entero
 * @param mensajeError Mensaje mostrado al usuario para avisar que el número ingresado no es válido
 * @param min Valor mínimo del rango en el que se debe encontrar el número
 * @param max Valor máximo del rango en el que se debe encontrar el número
 * @param pNumero número que retorna la función (a través de un puntero)
 * @return retorna -1 en caso de error (algun parametro Nulo , max menor a min o no poder cargar el numero). Retorna 0 caso contrario
 */
int funciones_imput_pedirYValidarEntero(char* mensaje, char* mensajeError, int min, int max, int* pNumero)
{
	int numeroAux;
	int* pNumeroAux = &numeroAux;
	int retorno = -1;
	int numeroValidacion;

	if(mensaje != NULL && mensajeError != NULL && pNumero != NULL && min < max)
	{
		printf("%s\n",mensaje);
		fflush(stdin);

		numeroValidacion = scanf("%d", pNumeroAux);

		while(numeroValidacion == 0 || *pNumeroAux < min || *pNumeroAux > max)
		{
			printf("%s\n",mensajeError);
			fflush(stdin);

			numeroValidacion = scanf("%d", pNumeroAux);
		}
		*pNumero = *pNumeroAux;
		retorno = 0;
	}
	return retorno;
}

/**
 * @fn int funciones_imput_pedirYValidarFlotante(char*, char*, float, float, float*)
 * @brief  pide, valida y retorna un numero flotante, en un rango determinado
 *
 * @param mensaje Mensaje mostrado al usuario para pedir el ingreso de un número entero
 * @param mensajeError Mensaje mostrado al usuario para avisar que el número ingresado no es válido
 * @param min Valor mínimo del rango en el que se debe encontrar el número
 * @param max Valor máximo del rango en el que se debe encontrar el número
 * @param pNumero número que retorna la función (a través de un puntero)
 * @return retorna -1 en caso de error (algun parametro Nulo , max menor a min o no poder cargar el numero). Retorna 0 caso contrario
 */
int funciones_imput_pedirYValidarFlotante(char* mensaje, char* mensajeError, float min, float max, float* pNumero)
{
	float numeroAux;
	float* pNumeroAux = &numeroAux;
	int retorno = -1;
	int numeroValidacion;

	if(mensaje != NULL && mensajeError != NULL && pNumero != NULL && min < max)
	{
		printf("%s",mensaje);
		fflush(stdin);

		numeroValidacion = scanf("%f", pNumeroAux);

		while(numeroValidacion == 0 || *pNumeroAux < min || *pNumeroAux > max)
		{
			printf("%s",mensajeError);
			fflush(stdin);

			numeroValidacion = scanf("%f", pNumeroAux);
		}
		*pNumero = *pNumeroAux;
		retorno = 0;
	}
	return retorno;
}

/**
 * @fn  funciones_imput_pedirYValidarCaracter(char*, char*, char*)
 * @brief Pide un caracter, lo valida y lo retorna.
 * @param mensaje Mensaje que se muestra para pedir el ingreso del caracter (letra)
 * @param mensajeError Mensaje mostrado en caso de ser erroneo el ingreso del caracter
 * @param pLetra puntero a letra, por donde se retorna la letra pedida
 * * @return Retorna -1 si hay algún error 0 si no.
 */
int funciones_imput_pedirYValidarCaracter(char* mensaje, char* mensajeError, char* pLetra)
{
	char letraAux;
	char* pLetraAux = &letraAux;
	int numeroValidacion;
	int retorno = -1;

	if(mensaje != NULL && mensajeError != NULL && pLetra != NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		numeroValidacion = scanf("%c", pLetraAux);

		while(numeroValidacion == 0 || isalpha(*pLetraAux) == 0)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			numeroValidacion = scanf("%c", pLetraAux);
		}

		*pLetra = *pLetraAux;
		retorno = 0;
	}
	return retorno;
}

/**
 * @fn int funciones_imput_pedirYValidarEnteroSinRango(char*, char*, int*)
 * @brief Pide, valida y retorna un entero cualquiera
 *
 * @param mensaje Mensaje mostrado para pedir el ingreso del número
 * @param mensajeError Mensaje mostrado para avisar de que el numero ingresado no es valido
 * @param pNumero Puntero, por donde se retorna el numero pedido
 * @return Retorna -1 si hay algún error 0 si no.
 */
int funciones_imput_pedirYValidarEnteroSinRango(char* mensaje, char* mensajeError, int* pNumero)
{
	int numeroAux;
	int* pNumeroAux = &numeroAux;
	int retorno = -1;
	int numeroValidacion;

	if(mensaje != NULL && mensajeError != NULL && pNumero != NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		numeroValidacion = scanf("%d", pNumeroAux);

		while(numeroValidacion == 0)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			numeroValidacion = scanf("%d", pNumeroAux);
		}

		*pNumero = *pNumeroAux;
		retorno = 0;
	}
	return retorno;
}

/**
 * @fn int funciones_imput_validarNumeroEntero(char*)
 * @brief Para verificar que una cadena de caracteres esté compuesta solo por numeros enteros (entonces es un numero entero)
 *
 * @param numero Cadena a verificar
 * @return Retorna la primera posicion en la que se encuentra un caracter no numerico. Si no encuentra ninguno, retorna 0.
 */
int funciones_imput_validarNumeroEntero(char* numero)
{
    int longitud;
    int flagEsNumero;
    int i;
    if(numero != NULL)
    {
        longitud = strlen(numero);

        for(i=0; i<longitud; i++)
        {
            if(*(numero+i)>47 && *(numero+i)<58)
            {
                flagEsNumero = 0;
            }
            else
            {
              flagEsNumero = i;
              break;
            }
        }
    }

    return flagEsNumero;
}

/**
 * @fn int funciones_imput_transformarAEntero(char*)
 * @brief Para transformar y retornar, si es posible, la cadena de caracteres numérica ingresada como un número entero (int).
 *
 * @param numero Cadena a transformar y retornar como entero.
 * @return Retorna la cadena transformada a entero. En caso de no poder transformarla, retorna -1.
 */
int funciones_imput_transformarAEntero(char* numero)
{
	int cadenaTransformada = -1;

	if(funciones_imput_validarNumeroEntero(numero) == 0)
	{
		cadenaTransformada = atoi (numero);
	}
	return cadenaTransformada;
}


