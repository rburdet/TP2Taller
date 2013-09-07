#include "myNode.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

TNode* createNode(char inf,char error){
	TNode* this=malloc(sizeof(TNode));
	if (!error){
		this->info=calloc(1,sizeof(char)+1);
		this->info[0]=inf;
		this->numberOfMovs++;
	}
	else{
		this->info=malloc(sizeof(char)*4);
		char* error="[E]";
		strcpy(this->info,error);
	}
	this->next=NULL;
	return this;
}

TNode* getNext(TNode* this){
	return (this->next);
}

void destroyNode(TNode* this){
	if (getNext(this)==NULL)
		free(this);
	else{
		this->next=getNext(this);
		destroyNode(this);
	}
}
