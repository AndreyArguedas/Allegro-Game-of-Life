#include "Control.h"


Control::Control(void)
{
}

void Control::initializePlatform(int r, int c){
	plat = new Platform(r,c);
}

void Control::generateLife(){
	initializePlatform(18,20);
	GraphicInterface::level1();
	level1();
	GraphicInterface::level2();
	level2();
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
		GraphicInterface::printPlatform(plat->toString());
		Sleep(800);
		plat->update();
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

void Control::level1(){
	for(int i = 0; i < plat->getColumns(); i++){
		plat->activateCell(10,i);
		plat->activateCell(11,i);
	}
	for(int i = 0; i < 40; i++){
		evolve();
	}
}

void Control::level2(){
	int r,c = 0;

	srand(unsigned(time(0)));
	for(int i = 0; i < 35; i++){
		r = rand() % plat->getRows();
		c = rand() % plat->getColumns();
		plat->activateCell(r,c);
	}
	for(int i = 0; i < 40; i++){
		evolve();
	}
}


Control::~Control(void)
{
	delete plat;
}
