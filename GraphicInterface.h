#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;

class GraphicInterface
{
public:
	GraphicInterface(void);	
	static void gotoXY(int, int);
	static void printPlatform(string);
	static void header();
	static void level1();
	static void level2();
	~GraphicInterface(void);
};

