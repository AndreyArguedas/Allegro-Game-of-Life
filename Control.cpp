#include "Control.h"


Control::Control(void)
{
}

void Control::initializePlatform(int r, int c){
	plat = new Platform(r,c);
}

void Control::generateLife(){
	initializePlatform(10,10);
	plat->activateCell(0,0);
	plat->activateCell(0,1);
	plat->activateCell(0,2);
	evolve();
}

void Control::evolve(){
	for(int i = 0; i < plat->getRows() ; i++)
		for(int j = 0; j < plat->getColumns(); j++){
			int neighbords = lateralNeighbords(i,j) + diagonalNeighbords(i,j);
			if(neighbords < 2)
				plat->disactivateCell(i,j);
			if(neighbords == 3)
				plat->activateCell(i,j);
			if(neighbords >= 4)
				plat->disactivateCell(i,j);
		}
		cout<<plat->getPoupulation()<<endl;
}

int Control::lateralNeighbords(int i, int j){
	int result = 0;
	if(j - 1 >= 0)
		result += plat->getState(i,j-1);
	if(j + 1 < plat->getColumns())
		result += plat->getState(i,j+1);
	if(i - 1 >= 0)
		result += plat->getState(i-1,j);
	if(i + 1 < plat->getRows())
		result += plat->getState(i + 1,j);
	return result;
}

int Control::diagonalNeighbords(int i,int j){
	int result = 0;
	if(j - 1 >= 0 && i - 1 >= 0)
		result += plat->getState(i-1,j-1);
	if(j + 1 < plat->getColumns() && i - 1 >= 0)
		result += plat->getState(i-1,j+1);
	if(j - 1 >= 0 && i + 1 < plat->getRows())
		result += plat->getState(i+1,j-1);
	if(j + 1 < plat->getColumns() && i + 1 < plat->getRows())
		result += plat->getState(i+1,j+1);
	return result;
}

Control::~Control(void)
{
}
