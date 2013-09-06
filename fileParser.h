#ifndef FILEPARSER_H
#define FILEPARSER_H

typedef unsigned int uint;

typedef struct TFileParser {
        FILE* fp;
		uint dimX, dimY,bufferSize;
		char* directionsBuffer;
} TFileParser;

TFileParser* createFileParser(char* inFile, int argc);
char readALine(TFileParser* this);	//Devuelve la letra a leer, 1 si es EOF 
void getSizes(TFileParser* this);
uint getX(TFileParser* this);
uint getY(TFileParser* this);

//TODO ARREGLAR EL -1 CABEZA QUE LE PUSE
//TODO ARREGLAR EL -1 CABEZA QUE LE PUSE
//TODO ARREGLAR EL -1 CABEZA QUE LE PUSE
//TODO ARREGLAR EL -1 CABEZA QUE LE PUSE
uint getBufferSize(TFileParser* this);
char* getDirections (TFileParser* this);
//TODO: liberar memoria del directionsBUffer en el destructor
void destroyFileParser(TFileParser* this);

#endif
