/*
 * parser.h
 *
 *  Created on: 2 nov. 2021
 *      Author: Yeller
 */

#ifndef PARSER_H_
#define PARSER_H_

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
int parserLastIdFromText(FILE* pFile);

#endif /* PARSER_H_ */
