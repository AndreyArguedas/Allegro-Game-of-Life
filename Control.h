#pragma once
#include "Platform.h"
#include "GraphicInterface.h"
#include <time.h>
class Control
{
private:
	Platform * plat;
public:
	Control(void);
	void level1();
	void level2();
	void initializePlatform(int,int);
	void generateLife();
	void evolve();
	int lateralNeighbords(int,int);
	int diagonalNeighbords(int,int);
	~Control(void);
};

