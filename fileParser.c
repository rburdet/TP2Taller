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

void destroyALine(TFileParser* this){
	if (this->directionsBuffer != NULL)
		free(this->directionsBuffer);
}

void getSizes(TFileParser* this){
	//El archivo ya esta abierto
	uint x,y;
	char c;
	if (fscanf(this->fp, "%u%c%u", &x,&c,&y)){
		this->dimX = x; 
		this->dimY = y;
	}else{
		return;
	}
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
	if (this->directionsBuffer != NULL);
		free(this->directionsBuffer);
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
	if (fscanf(this->fp, "%s", this->directionsBuffer))
		return 0;
	else
		return 1;
}

char* getDirections(TFileParser* this){
	return (this->directionsBuffer);
}
