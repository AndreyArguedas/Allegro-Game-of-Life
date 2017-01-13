#include "Control.h"

int main(){
	Control * c = new Control();
	c->generateLife();
	delete c;
}