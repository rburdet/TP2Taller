#ifndef MYNODE_H
#define MYNODE_H

typedef struct TMyNode {
	struct TMyNode* next;
	char* info;
	unsigned numberOfMovs;
} TNode;

TNode* createNode(char info,char error);
void destroyNode(TNode* this);
TNode* getNext(TNode* this);
void setNext(TNode* this, TNode* anotherNode);

#endif 
