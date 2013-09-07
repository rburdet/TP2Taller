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
	TNode* nodeToDestroy;
	this->actual=this->first;
	while(getNext(this->actual) != NULL){
		nodeToDestroy=this->actual;
		destroyNode(nodeToDestroy);
		this->actual=getNext(this->actual);
	}
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

void printMovements(TList* this){
	//El primero
	this->actual=this->first;
	printf("%s",this->actual->info);
	//Los del medio
	while ((this->actual=getNext(this->actual))!=NULL){
		printf("%s",this->actual->info);
	}
}
