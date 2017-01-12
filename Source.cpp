#include "Control.h"

int main(){
	Control * c = new Control();
	c->generateLife();
	cin.get();
	delete c;
}