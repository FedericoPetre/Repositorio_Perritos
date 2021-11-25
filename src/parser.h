/*
 * parser.h
 *
 *  Created on: 9 nov. 2021
 *      Author: Federico Petre
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "perrito.h"

int parser_PerritoFromText(FILE* pFile , LinkedList* pArrayListPerrito);
int parser_PerritoFromBinary(FILE* pFile , LinkedList* pArrayListPerrito);



#endif /* PARSER_H_ */
