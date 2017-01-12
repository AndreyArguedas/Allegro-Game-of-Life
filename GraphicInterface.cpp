#include "GraphicInterface.h"


GraphicInterface::GraphicInterface(void)
{
	al_init();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_mouse();
	al_install_audio();
	al_init_acodec_addon();
	al_init_primitives_addon(); //Funcion para dibujar figuras
	al_install_keyboard();//Instalar el teclado
	al_set_new_display_flags(ALLEGRO_RESIZABLE|ALLEGRO_WINDOWED);
	display = al_create_display(800,700);
	al_set_window_title(display,"GAME OF LIFE");
	al_clear_to_color(al_map_rgb(0,0,0));
	al_flip_display();
}


void GraphicInterface::gotoXY(int x,int y){
	COORD position = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, position);
}

void GraphicInterface::header(){
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(h, FOREGROUND_GREEN| FOREGROUND_INTENSITY);
int x = 15; int y = 15;
gotoXY(x,y++);
cout<<" #####  ####### #       ### ######      #####  ####### ######  ####### ";gotoXY(x,y++);
cout<<"#     # #     # #        #  #     #    #     # #     # #     # #       ";gotoXY(x,y++);
cout<<"#       #     # #        #  #     #    #       #     # #     # #       ";gotoXY(x,y++);
cout<<" #####  #     # #        #  #     #    #       #     # #     # #####   ";gotoXY(x,y++);
cout<<"      # #     # #        #  #     #    #       #     # #     # #       ";gotoXY(x,y++);
cout<<"#     # #     # #        #  #     #    #     # #     # #     # #       ";gotoXY(x,y++);
cout<<" #####  ####### ####### ### ######      #####  ####### ######  ####### ";gotoXY(x,y++);
cin.get();
system("cls");
}

void GraphicInterface::level1(){
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(h, FOREGROUND_GREEN| FOREGROUND_INTENSITY);
int x = 15; int y = 15;
gotoXY(x,y++);
cout<<"#       ####### #     # ####### #             #   ";gotoXY(x,y++);
cout<<"#       #       #     # #       #            ##   ";gotoXY(x,y++);
cout<<"#       #       #     # #       #           # #   ";gotoXY(x,y++);
cout<<"#       #####   #     # #####   #             #   ";gotoXY(x,y++);
cout<<"#       #        #   #  #       #             #   ";gotoXY(x,y++);
cout<<"#       #         # #   #       #             #   ";gotoXY(x,y++);
cout<<"####### #######    #    ####### #######     ##### ";gotoXY(x,y++);
cin.get();
system("cls");
}

void GraphicInterface::level2(){
system("cls");
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(h, FOREGROUND_GREEN| FOREGROUND_INTENSITY);
int x = 15; int y = 15;
gotoXY(x,y++);
cout<<"#       ####### #     # ####### #           #####  ";gotoXY(x,y++);
cout<<"#       #       #     # #       #          #     # ";gotoXY(x,y++);
cout<<"#       #       #     # #       #                # ";gotoXY(x,y++);
cout<<"#       #####   #     # #####   #           #####  ";gotoXY(x,y++);
cout<<"#       #        #   #  #       #          #       ";gotoXY(x,y++);
cout<<"#       #         # #   #       #          #       ";gotoXY(x,y++);
cout<<"####### #######    #    ####### #######    ####### ";gotoXY(x,y++);
cin.get();
system("cls");
}

void GraphicInterface::printPlatform(string plat){
	int r = 0;int c = 0;
	int aux = plat.length();

	for(int i = 0; i < plat.length(); i++)
		if (plat[i] == 'O') {
			al_draw_rectangle(r * 40,c * 40,r * 40 + 40,c * 40 + 40,al_map_rgb(255,255,255),1);
			al_draw_filled_rectangle(r * 40,c * 40,r * 40 + 40,c * 40 + 40,al_map_rgb(76,145,65));
			r++;
		}
		else if(plat[i] == '-'){
			al_draw_filled_rectangle(r * 40,c * 40,r * 40 + 40,c * 40 + 40,al_map_rgb(0,0,0));
			al_draw_rectangle(r * 40,c * 40,r * 40 + 40,c * 40 + 40,al_map_rgb(255,255,255),1);
			r++;
			
		}
		else if(plat[i] == '\n'){
				r = 0; 
				c++;
		}
	al_flip_display();
}

GraphicInterface::~GraphicInterface(void)
{
	al_destroy_display(display);
}
