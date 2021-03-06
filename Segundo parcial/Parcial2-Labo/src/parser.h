/*
 * parser.h
 *
 *  Created on: 2 nov. 2021
 *      Author: Yeller
 */

#ifndef PARSER_H_
#define PARSER_H_

int parser_BookFromText(FILE* pFile, LinkedList* pArrayListBook);
int parser_EditorialFromText(FILE* pFile, LinkedList* pArrayListEditorial);
//int parserLastIdFromText(FILE* pFile);

int parser_BookFromBinary(FILE* pFile , LinkedList* pArrayListBook);
int parser_EditorialFromBinary(FILE* pFile , LinkedList* pArrayListEditorial);


#endif /* PARSER_H_ */
