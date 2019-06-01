#include <iostream>
#include <string>
#include <math.h>
#include <random>

#include "functions.h"
#include "MonteCarlo.h"

typedef unsigned int uint;

/*Defines area and its volume*/
#define XMIN -10.f
#define XMAX 10.f
#define YMIN -10.f
#define YMAX 10.f
#define ZMAX 100.f

/*Sets number of randomly generated points*/
#define PRECISION 100000

int main()
{ 
		std::cout << monte_carlo_start(matyas, XMIN, XMAX, YMIN, YMAX, ZMAX, PRECISION) << std::endl;
}