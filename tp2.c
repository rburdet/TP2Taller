#include <stdio.h>
#include "fileParser.h"
#include "myList.h"
#include "myMatrix.h"

int main(int argc, char *argv[]){
	TList* aList;
	createList(&aList);
	TMatrix* aMatrix;
	TFileParser* aFileParser = createFileParser(argv[2],argc);
	rintMovements(aList);
	while (!readALine(aFileParser)){
		aList = createList();
		aMatrix =createMatrix(getX(aFileParser),getY(aFileParser));
		fillMatrix(aMatrix,argv[1]);
		printf("%u ",moveThrough(aMatrix,aList,aFileParser));
		printMovements(aList);
		destroyMatrix(aMatrix);
		destroyList(aList);
		printf("\n");
	}
	destroyFileParser(aFileParser);
return 0;
}
