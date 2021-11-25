/*
 * nexusEmployee_and_Ll.h
 *
 *  Created on: 12 nov. 2021
 *      Author: Federico Petre
 */

#ifndef NEXUSEMPLOYEE_AND_LL_H_
#define NEXUSEMPLOYEE_AND_LL_H_

#include "Employee.h"
#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

int nexusEmployee_and_Ll_findEmployeeByID(LinkedList* this, int id);
int nexusEmployee_and_Ll_findLastID(LinkedList* this);
Employee* nexusEmployee_and_Ll_getEmployees(LinkedList* this);

#endif /* NEXUSEMPLOYEE_AND_LL_H_ */
