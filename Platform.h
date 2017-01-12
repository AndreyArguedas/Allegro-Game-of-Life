#pragma once
#include "Cell.h"
class Platform
{
private:
	Cell *** matrix;
	int rows;
	int columns;
public:
	Platform(int,int);
	int getRows();
	int getColumns();
	int getPoupulation();
	void setRows(int);
	void setColumns(int);
	void activateCell(int,int);
	void disactivateCell(int,int);
	void setNextState(int,int,bool);
	bool getState(int,int);
	void update();
	string toString();
	~Platform(void);
};

