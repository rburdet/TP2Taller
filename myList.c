#include "myList.h"
#include <stdlib.h>

TList* createList(){
	TList* this=(TList*)malloc(sizeof(TNode));
	this->actual=NULL;
	this->first=NULL;
	return this;
}

void destroyList(TList* this){
	TNode* nodeToDestroy;
	this->actual=this->first;
	nodeToDestroy=getNext(this->actual);
	while(nodeToDestroy != NULL){
		this->actual=getNext(nodeToDestroy);
		destroyNode(nodeToDestroy);
		nodeToDestroy=this->actual;
	}
	destroyNode(this->first);
	free(this);
}

TNode* getActual(TList* this){
	return (this->actual);
}

void addNode(TList* this, TNode* node){
	if (this->first == NULL){
		this->first=node;
		this->actual=node;
	}else{
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
