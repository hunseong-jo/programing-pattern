#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <chrono>


using namespace std;
bool gameOver;
//const int width = 20;
//const int height = 20;
int width;
int height;
int nani;
//≥≠¿Ãµµ
int x, y, fruitX, fruitY, score, defruitX, defruitY;
int tailX[100], tailY[100];
int nTail;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirecton dir; 

int fruitX2, fruitY2;
int trapX, trapY;
