#include "Cell.h"


Cell::Cell(void)
{
	state = false;
}

bool Cell::getState(){
	return state;
}

void Cell::setState(bool ns){
	state = ns;
}

string Cell::toString(){
	stringstream s;
	if(state)
		s<<"O";
	else
		s<<"X";
	return s.str();
}

Cell::~Cell(void)
{
	state = false;
}
