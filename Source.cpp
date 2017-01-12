#include "Control.h"

int main(){
	Control * c = new Control();
	GraphicInterface::header();
	c->generateLife();
	cin.get();
	delete c;
}