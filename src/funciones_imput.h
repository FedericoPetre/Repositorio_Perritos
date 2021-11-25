/*
 * funciones_imput.h
 *
 *  Created on: 7 nov. 2021
 *      Author: Federico Petre
 */

#ifndef FUNCIONES_IMPUT_H_
#define FUNCIONES_IMPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int funciones_imput_cargarEntero(int* pNumero, char* mensaje, int min, int max);
void funciones_imput_pedirYValidarCadena(char* mensaje, char* mensajeError, int max, char* cadenaDeRetorno);
int funciones_imput_verificarCadena(char* cadena);
int funciones_imput_pedirYValidarEntero(char* mensaje, char* mensajeError, int min, int max, int* pNumero);
int funciones_imput_pedirYValidarFlotante(char* mensaje, char* mensajeError, float min, float max, float* pNumero);
int funciones_imput_pedirYValidarCaracter(char* mensaje, char* mensajeError, char* pLetra);
int funciones_imput_pedirYValidarEnteroSinRango(char* mensaje, char* mensajeError, int* pNumero);
int funciones_imput_validarNumeroEntero(char* numero);
int funciones_imput_transformarAEntero(char* numero);



#endif /* FUNCIONES_IMPUT_H_ */
