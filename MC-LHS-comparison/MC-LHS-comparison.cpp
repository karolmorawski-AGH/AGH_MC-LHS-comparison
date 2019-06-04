#include <iostream>
#include <string>
#include <math.h>
#include <random>
#include <chrono> 

#include "functions.h"
#include "MonteCarlo.h"
#include "LatinHypercubeSampling.h"

typedef unsigned int uint;

/*McCormick - 3950*/
/*Matyas - 7840*/
/*Simplecube - 40000*/

//TODO replace macros with enums
/*Defines area and its volume*/
#define XMIN -5.f
#define XMAX 5.f
#define YMIN -5.f
#define YMAX 5.f
#define ZMAX 5.f

/*Sets number of randomly generated points*/
#define PRECISION 5000
#define partitions 5
#define packages 10

int main()
{ 
	using namespace std::chrono;

	/*Monte Carlo*/
	std::cout << "MC: \t";
	auto start = high_resolution_clock::now();
	std::cout << monte_carlo_start(mccormick, XMIN, XMAX, YMIN, YMAX, ZMAX, PRECISION);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
	std::cout << " \t\t" << duration.count() << "ms using " << PRECISION << " randomly generated points" << std::endl;

	/*LHS*/
	std::cout << "LHS: \t";
	auto startlhs = high_resolution_clock::now();
	std::cout << lhs_start(mccormick, XMIN, XMAX, YMIN, YMAX, ZMAX, partitions, packages);
	auto stoplhs = high_resolution_clock::now();
	auto durationlhs = duration_cast<milliseconds>(stoplhs - startlhs);
	std::cout << " \t" << durationlhs.count() << "ms using " << partitions * partitions * partitions * packages << " randomly generated points" << std::endl;
	}