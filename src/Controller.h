#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "perrito.h"
#include "funciones_imput.h"
#include "nexusPerrito_and_Ll.h"


int controller_loadFromText(char* path , LinkedList* pArrayListPerrito);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPerrito);
int controller_addPerrito(LinkedList* pArrayListPerrito);
int controller_editPerrito(LinkedList* pArrayListPerrito);
int controller_removePerrito(LinkedList* pArrayListPerrito);
int controller_ListPerrito(LinkedList* pArrayListPerrito);
int controller_sortPerritos(LinkedList* pArrayListPerrito);
int controller_saveAsText(char* path , LinkedList* pArrayListPerrito);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPerrito);

#endif
