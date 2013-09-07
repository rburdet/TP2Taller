#include <stdio.h>
#include <stdlib.h>
#include "fileParser.h"

TFileParser* createFileParser(char* inFile,int argc){
	TFileParser* this = (TFileParser*)calloc(1,sizeof(TFileParser));
	this->directionsBuffer = NULL;
	if (argc!=3)
		this->fp = stdin;
	else
		this->fp = fopen(inFile, "r");
	return this;
}

void destroyFileParser(TFileParser* this){
	fclose(this->fp);
	free(this);
}

void getSizes(TFileParser* this){
	//El archivo ya esta abierto
	uint x,y;
	char c;
	fscanf(this->fp, "%u%c%u", &x,&c,&y);
	this->dimX = x; 
	this->dimY = y;
}
uint getX(TFileParser* this){
	return (this->dimX);
}

uint getY(TFileParser* this){
	return (this->dimY);
}

uint getBufferSize(TFileParser* this){
	return (this->bufferSize);
}

char readALine(TFileParser* this){
	unsigned char c;
	getSizes(this);
	uint i=0;
	uint endOfSizes = ftell(this->fp)+1;	//Me paro en la primer letra
	while ( (c = fgetc(this->fp)) != '\n' ){
		if (feof(this->fp))
			return 1;
		else
			i++;
	}
	this->bufferSize=i-1;
	this->directionsBuffer=malloc(sizeof(char)*i);
	fseek(this->fp, endOfSizes, SEEK_SET);
	fscanf(this->fp, "%s", this->directionsBuffer);
	return 0;
}

char* getDirections(TFileParser* this){
	return (this->directionsBuffer);
}
