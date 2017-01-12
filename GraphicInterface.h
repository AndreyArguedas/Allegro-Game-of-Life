#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#include <allegro5\allegro_primitives.h>
using namespace std;

class GraphicInterface
{
public:
	ALLEGRO_DISPLAY * display;
	GraphicInterface(void);	
	void gotoXY(int, int);
	void printPlatform(string);
	void header();
	void level1();
	void level2();
	ALLEGRO_DISPLAY getDisplay();
	~GraphicInterface(void);
};

