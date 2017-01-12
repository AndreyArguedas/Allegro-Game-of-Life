#include "Control.h"

int main(){
	Control * c = new Control();
	//c->gi->header();
	c->generateLife();
	cin.get();
	delete c;
}