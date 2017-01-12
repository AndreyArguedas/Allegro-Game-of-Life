#include "Control.h"


Control::Control(void)
{
}

void Control::initializePlatform(int r, int c){
	plat = new Platform(r,c);
}

void Control::generateLife(){
	initializePlatform(5,5);
	plat->activateCell(2,2);
	plat->activateCell(3,1);
	plat->activateCell(3,2);
	evolve();
}

void Control::evolve(){
	for(int i = 0; i < plat->getRows() ; i++)
		for(int j = 0; j < plat->getColumns(); j++){
			int neighbords = lateralNeighbords(i,j) + diagonalNeighbords(i,j);
			if(neighbords < 2)
				plat->setNextState(i,j,false);
			if(neighbords > 3)
				plat->setNextState(i,j,false);
			if(plat->getState(i,j)){
				if(neighbords == 3 || neighbords == 2)
					plat->setNextState(i,j,true);
			}
			else if(!plat->getState(i,j) && neighbords == 3)
					plat->setNextState(i,j,true);
				
			}
		plat->update();
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
