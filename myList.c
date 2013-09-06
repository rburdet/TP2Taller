#include "myList.h"
#include <stdlib.h>

TList* createList(){
	TList* this=(TList*)malloc(sizeof(TNode));
	this->actual=NULL;
	this->first=NULL;
	return this;
}

void destroyList(TList* this){
	//Llamo al destruir del nodo para luego destruir todos los nodos
	destroyNode(this->first);
	free(this->first);
}

TNode* getActual(TList* this){
	return (this->actual);
}

//NO SE QUE CARAJOS HACER ACA !!
void addNode(TList* this, TNode* node){
	if (this->first == NULL){
		this->first=node;
		this->actual=node;
	}
	else{
		(this->actual)->next = node;
		this->actual = node;
	}
}
