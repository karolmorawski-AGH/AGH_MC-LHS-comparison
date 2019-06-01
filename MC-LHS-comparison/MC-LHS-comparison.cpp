#include <iostream>
#include <string>
#include <math.h>
#include <random>

#include "functions.h"
#include "MonteCarlo.h"

typedef unsigned int uint;

/*Defines area and its volume*/
#define XMIN -5.
#define XMAX 5.
#define YMIN -5.
#define YMAX 5.
#define ZMAX 5.

/*Sets number of randomly generated points*/
#define PRECISION 1000

int main()
{
	std::cout << monte_carlo_start(simpleCube, XMIN, XMAX, YMIN, YMAX, ZMAX, PRECISION);
}

