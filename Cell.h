#pragma once
#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;
class Cell
{
private:
	bool state;
public:
	Cell(void);
	bool getState();
	void setState(bool);
	string toString();
	~Cell(void);
};

