#include "Control.h"


Control::Control(void)
{
	gi = new GraphicInterface();
}

void Control::initializePlatform(int r, int c){
	plat = new Platform(r,c);
}

void Control::generateLife(){
	initializePlatform(18,20);
	int fila,columna = 0;
	bool quit = false;
	bool evolving = false;
	bool activated = false;
	gi->start();
	ALLEGRO_EVENT_QUEUE *evento =al_create_event_queue();
	al_register_event_source(evento,al_get_mouse_event_source());
	al_register_event_source(evento,al_get_display_event_source(gi->display));
	ALLEGRO_EVENT_QUEUE *evento2 =al_create_event_queue();
	al_register_event_source(evento2,al_get_mouse_event_source());
	al_register_event_source(evento2,al_get_display_event_source(gi->display));
	ALLEGRO_MOUSE_STATE mouseState;
	gi->printPlatform(plat->toString());
	ALLEGRO_EVENT e;
	while(!quit){

	al_wait_for_event(evento,&e);
	
		if(e.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
			if(e.mouse.button&1){
				fila=e.mouse.y;
				columna=e.mouse.x;
				fila = mapping(fila,0,700,0,18);
				columna = mapping(columna,0,800,0,20);
				if(fila < 18 && columna < 20)
					plat->changeState(fila,columna);
				gi->printPlatform(plat->toString());
			}
			if(e.mouse.button&2){
				evolve();
			}
			
		}
		else if(e.type==ALLEGRO_EVENT_DISPLAY_CLOSE){quit = true;}
	}
}

void Control::evolve(){

for(int x = 0; x <= 20; x++){
	for(int i = 0; i < plat->getRows() ; i++)
		for(int j = 0; j < plat->getColumns(); j++){
			int neighbords = lateralNeighbords(i,j) + diagonalNeighbords(i,j);
			if(neighbords < 2)
				plat->setNextState(i,j,false);
			if(neighbords > 3)
				plat->setNextState(i,j,false);
			if(plat->getState(i,j)){
				if(neighbords == 3 || neighbords == 2)
					plat->setNextState(i,j,true);
			}
			else if(!plat->getState(i,j) && neighbords == 3)
					plat->setNextState(i,j,true);
				
			}
		gi->timesLeft(20 -x );
		gi->printPlatform(plat->toString());
		Sleep(400);
		plat->update();
		gi->printPlatform(plat->toString());
}
	gi->start();
	al_flip_display();
}

int Control::lateralNeighbords(int i, int j){
	int result = 0;
	if(j - 1 >= 0)
		result += plat->getState(i,j-1);
	if(j + 1 < plat->getColumns())
		result += plat->getState(i,j+1);
	if(i - 1 >= 0)
		result += plat->getState(i-1,j);
	if(i + 1 < plat->getRows())
		result += plat->getState(i + 1,j);
	return result;
}

int Control::diagonalNeighbords(int i,int j){
	int result = 0;
	if(j - 1 >= 0 && i - 1 >= 0)
		result += plat->getState(i-1,j-1);
	if(j + 1 < plat->getColumns() && i - 1 >= 0)
		result += plat->getState(i-1,j+1);
	if(j - 1 >= 0 && i + 1 < plat->getRows())
		result += plat->getState(i+1,j-1);
	if(j + 1 < plat->getColumns() && i + 1 < plat->getRows())
		result += plat->getState(i+1,j+1);
	return result;
}

void Control::level1(){
	for(int i = 0; i < plat->getColumns(); i++){
		plat->activateCell(10,i);
		plat->activateCell(11,i);
	}
	for(int i = 0; i < 40; i++){
		evolve();
	}
}

void Control::level2(){
	int r,c = 0;

	srand(unsigned(time(0)));
	for(int i = 0; i < 35; i++){
		r = rand() % plat->getRows();
		c = rand() % plat->getColumns();
		plat->activateCell(r,c);
	}
	for(int i = 0; i < 40; i++){
		evolve();
	}
}

int Control::mapping(int num,int minin,int maxin,int minout,int maxout){
	 return (num - minin) * (maxout - minout) / (maxin - minin) + minout;
}


Control::~Control(void)
{
	delete plat;
	delete gi;
}
