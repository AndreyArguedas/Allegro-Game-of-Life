#include "Platform.h"


Platform::Platform(int r, int c)
{
	matrix = new Cell**[rows=r];
	for(int i = 0; i < rows; i++)
		matrix[i]=new Cell * [columns=c];
	for(int i=0; i < rows; i++)
		for(int j = 0; j < c; j++)
			matrix[i][j] = new Cell();
}

int Platform::getRows(){return rows;}

int Platform::getColumns(){return columns;}

void Platform::setRows(int nr){rows = nr;}

void Platform::setColumns(int nc){columns = nc;}

void Platform::activateCell(int r, int c){
	matrix[r][c]->setState(true);
}

void Platform::disactivateCell(int r, int c){
	matrix[r][c]->setState(false);
}

bool Platform::getState(int r, int c){
	return matrix[r][c]->getState();
}

string Platform::toString(){
	stringstream s;
	for(int i = 0; i < rows ; i++){
		for(int j = 0; j < columns; j++)
			if(matrix[i][j] != NULL)
				s<<matrix[i][j]->toString()<<" ";
		s<<endl;
	}
	return s.str();
}

int Platform::getPoupulation(){
	int result = 0;
	for(int i = 0; i < rows ; i++)
		for(int j = 0; j < columns; j++)
			if(matrix[i][j]->getState())
				result++;
	return result;
}


Platform::~Platform(void)
{
	for(int i = 0; i < rows; i++)
	for(int j = 0; j < columns; j++)
		if(matrix[i][j])
			delete matrix[i][j];
	for(int i = 0;i < rows; i++)
		if(matrix[i])
			delete [] matrix[i];
	if(matrix)
		delete []matrix;
}
