#include <stdio.h>
#include "fileParser.h"
#include "myList.h"
#include "myMatrix.h"
/*
 *  al parecer llena bien la matriz
 *  TODO: Recorridos
 * */
int main(int argc, char *argv[]){
	TNode aNode;
	TList* aList = createList();
	createList(&aList);
	TFileParser* aFileParser = createFileParser(argv[2],argc);
	readALine(aFileParser);
	TMatrix* aMatrix =createMatrix(getX(aFileParser),getY(aFileParser));
	fillMatrix(aMatrix,argv[1]);
	moveThrough(aMatrix,aList,aFileParser);
	destroyFileParser(aFileParser);
	//while (!readALine(&aFileParser)){
	//	printf("\n");
	//	createMatrix(&aMatrix,getX(&aFileParser),getY(&aFileParser));
	//	fillMatrix(&aMatrix,argv[1]);
	//	moveThrough(&aMatrix,&aList,&aFileParser);
	//	//for (j=0; j<getBufferSize(&aFileParser)-1 ; j++)
	//	//	printf("%c",getDirections(&aFileParser)[j]);
	//	//printf("\n");
	//	destroyMatrix(&aMatrix);
	//}
return 0;
}
