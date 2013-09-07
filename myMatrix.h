#ifndef MYMATRIX_H
#define MYMATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include "fileParser.h"
#include "myList.h"

typedef struct TMyMatrix{
	char** matrix;
	unsigned dimX,dimY;
}TMatrix;

TMatrix* createMatrix(unsigned x,unsigned y);
void destroyMatrix(TMatrix* this);
void roundRobin(TMatrix* this,FILE* fp);
void fillMatrix(TMatrix* this,char* fileName);
unsigned moveThrough(TMatrix* this,TList* movements,TFileParser* parser);

#endif
