#pragma once
#include "Platform.h"
class Control
{
private:
	Platform * plat;
public:
	Control(void);
	void initializePlatform(int,int);
	void generateLife();
	void evolve();
	int lateralNeighbords(int,int);
	int diagonalNeighbords(int,int);
	~Control(void);
};

