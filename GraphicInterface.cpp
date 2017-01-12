#include "GraphicInterface.h"


GraphicInterface::GraphicInterface(void)
{
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
	int x = 25;int y = 0;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_GREEN| FOREGROUND_INTENSITY);
	gotoXY(x,y+=3);
	int aux = plat.length();
	for(int i = 0; i < plat.length(); i++)
		if (plat[i] == 'O') {
			gotoXY(x+=3,y);
			SetConsoleTextAttribute(h, FOREGROUND_GREEN| FOREGROUND_INTENSITY);
			cout<<plat[i]<<" ";
		}
		else if(plat[i] == '-'){
			gotoXY(x+=3,y);
			SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
			cout<<plat[i]<<" ";
		}
		else if(plat[i] == '\n'){
				x = 25; 
				y+=2;
			}
}

GraphicInterface::~GraphicInterface(void)
{
}
