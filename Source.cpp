#include "Control.h"

int main(){
	FreeConsole();
	Control * c = new Control();
	c->generateLife();
	delete c;
}