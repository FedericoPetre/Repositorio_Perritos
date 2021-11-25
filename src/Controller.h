#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "perrito.h"
#include "funciones_imput.h"
#include "nexusEmployee_and_Ll.h"


int controller_loadFromText(char* path , LinkedList* pArrayListPerrito);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPerrito);
int controller_addPerrito(LinkedList* pArrayListPerrito);
int controller_editPerrito(LinkedList* pArrayListPerrito);
int controller_removeEmployee(LinkedList* pArrayListPerrito);
int controller_ListEmployee(LinkedList* pArrayListPerrito);
int controller_sortEmployee(LinkedList* pArrayListPerrito);
int controller_saveAsText(char* path , LinkedList* pArrayListPerrito);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPerrito);

#endif
