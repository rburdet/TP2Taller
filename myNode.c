#include "myNode.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

TNode* createNode(char inf,char error){
	TNode* this=malloc(sizeof(TNode));
	//printf("elputo inf es : %c\n",inf);
	if (!error){
		//printf(" entre en DULR\n");
		this->info=malloc(sizeof(char));
		this->info[0]=inf;
		this->numberOfMovs++;
	}
	else{
		//printf("no entre en DULR\n");
		this->info=malloc(sizeof(char)*3);
		char* error="[E]";
		strcpy(this->info,error);
	}
	this->next=NULL;
	printf(" dentro del nodo:%s\n",this->info);
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
