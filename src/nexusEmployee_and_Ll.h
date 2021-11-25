/*
 * nexusEmployee_and_Ll.h
 *
 *  Created on: 12 nov. 2021
 *      Author: Federico Petre
 */

#ifndef NEXUSEMPLOYEE_AND_LL_H_
#define NEXUSEMPLOYEE_AND_LL_H_

#include "perrito.h"
#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

int nexusPerrito_and_Ll_findPerritoByID(LinkedList* this, int id);
int nexusPerrito_and_Ll_findLastID(LinkedList* this);
perrito* nexusPerrito_and_Ll_getPerritos(LinkedList* this);

#endif /* NEXUSEMPLOYEE_AND_LL_H_ */
