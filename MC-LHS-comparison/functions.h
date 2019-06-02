#pragma once
#include <math.h>

/*Matyas Function
zmax = 80 minxy = -10 maxxy= 10*/
float matyas(float x, float y) {
	return 0.26f * (x * x + y * y) - 0.48f * x * y;
}

/*McCormick Function 
zmax = 40 minxy= -2 maxxy = 4*/
float mccormick(float x, float y) {
	return sin(x + y) + (x - y) * (x - y) - 1.5f * x + 2.5f * y + 1.f;
}

/*Simple cube*/
float simpleCube(float x, float y) {
	return 4;
}

