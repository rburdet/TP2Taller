#include "myMatrix.h"

TMatrix* createMatrix(unsigned x,unsigned y){
	TMatrix* this = (TMatrix*) calloc(1,sizeof(TMatrix));
	this->matrix = (char**)malloc(sizeof(char*)*x);
	unsigned i;
	for (i=0; i< x ; i++)
		this->matrix[i] = malloc(sizeof(char)*y);
	this->dimX=x;
	this->dimY=y;
	return this;
}

void destroyMatrix(TMatrix* this){
	unsigned i;
	for ( i=0 ; i < this->dimX ; i++)
		free(this->matrix[i]);
	free(this->matrix);
	free(this);
}

void fillMatrix(TMatrix* this,char* fileName){
	FILE* fp = fopen(fileName,"r");
	unsigned i,j,fileSize;
	char c;
	fseek(fp,0L,SEEK_END);
	fileSize = ftell(fp);
	fseek(fp,0L,SEEK_SET);
	if (fileSize+1 >= (this->dimX * this->dimY)){
		for (i=0 ; i < this->dimX ; i++){
			for ( j = 0 ; j < this->dimY ; j++){
				fscanf(fp,"%c",&c);
				this->matrix[i][j] = c;
			}
		}
	}else{
		roundRobin(this,fp);
	}
	fclose(fp);
	//Imprimo matrizz
	//for (i=0 ; i < this->dimX ; i++){
	//	for ( j = 0 ; j < this->dimY ; j++){
	//		printf(" %c",this->matrix[i][j]);
	//	}
	//	printf("\n");
	//}
}

void roundRobin(TMatrix* this,FILE* fp){
	unsigned i,j,count;
	char c;
	for(count=0; count < (this->dimX * this->dimY); count++){
		for (i=0 ; i < this->dimX ; i++){
			for ( j = 0 ; j < this->dimY ; j++){
				c = this->matrix[i][j];
				if ( (fscanf(fp,"%c",&c)) !=1 );
					fseek(fp,0L,SEEK_SET);
			}
		}	
	}
}

unsigned moveThrough(TMatrix* this,TList* movements,TFileParser* parser){
	unsigned it,movesMade=0,i=0,j=0;
	char c,error,aux;
	for (it=0 ; it<(parser->bufferSize) ; it++){
	c=0;
	error=0;
	aux=parser->directionsBuffer[it];
		switch(aux){
			case 'R':{
				if (j == (this->dimY)-1)
					error = 1;
				else{
					j++; 
					movesMade++;
					c = this->matrix[i][j];
				}
				break;}
			case 'L':{
				if (j == 0)
					error = 1;
				else{
					j--;
					movesMade++;
					c = this->matrix[i][j];
				}
				break;}
			case 'U':{
				if (i==0)
					error = 1;
				else{
					i--;
					movesMade++;
					c = this->matrix[i][j];
				}
				break;}
			case 'D':{
				if (i== (this->dimX)-1)
					error = 1;
				else{
					i++;
					movesMade++;
					c = this->matrix[i][j];
				}
				break;}
		}
		if ( (aux=='D') || (aux == 'U') || (aux == 'R') || (aux == 'L')){
			TNode* auxNode = createNode(c,error);
			addNode(movements,auxNode);
		}
	}
	return movesMade;
}
