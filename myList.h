#ifndef MYLIST_H
#define MYLIST_H

#include <stdio.h>
#include "myNode.h"

typedef struct TMyList {
	TNode* first;
	TNode* actual;		//Para agregar mas facil
} TList;

TList* createList();
//TODO: pensar, primero tengo q eliminar los demas nodos
void destroyList(TList* this);
void printMovements(TList* this);
TNode* getActual(TList* this);
void addNode(TList* this,TNode* node);

#endif
