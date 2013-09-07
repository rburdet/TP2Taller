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
	}else{
		//Tuve que usar snprintf porque el CppLint me lo recomendaba en lugar
		//del strcpy
		//Tuve que crear la variable auxiliar para dejar conforme al compilador
		//Usando el mismo dato para los primeros dos parametros de snprintf
		//generaba un warning [-Wsizeof-pointer-memaccess] 
		unsigned aux = sizeof(char)*4;
		this->info=malloc(sizeof(char)*4);
		const char* error="[E]";
		if (!snprintf(this->info,aux,"%s",error))
			return NULL;
	}
	this->next=NULL;
	return this;
}

TNode* getNext(TNode* this){
	return (this->next);
}

void destroyNode(TNode* this){
		free(this->info);
		free(this);
}
