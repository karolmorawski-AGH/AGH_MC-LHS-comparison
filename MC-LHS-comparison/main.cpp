#include <iostream>
#include <string>
#include <math.h>
#include <random>
#include <chrono> 

#include "functions.h"
#include "MonteCarlo.h"
#include "LatinHypercubeSampling.h"

typedef unsigned int uint;

/*Defines area and its volume*/
const float XMIN = -5.f;
const float XMAX = 5.f;
const float YMIN = -5.f;
const float YMAX = 5.f;
const float ZMAX = 10.f;

/*Sets number of randomly generated points*/
const uint PRECISION = 10000;
const uint partitions = 10;
const uint packages = 2;

int main()
{ 
	using namespace std::chrono;

	/*Monte Carlo*/
	std::cout << "MC: \t";
	auto start = high_resolution_clock::now();
	std::cout << monte_carlo_start(simplePlane, XMIN, XMAX, YMIN, YMAX, ZMAX, PRECISION);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
	std::cout << " \t\t" << duration.count() << "ms using " << PRECISION << " randomly generated points" << std::endl;

	/*LHS*/
	std::cout << "LHS: \t";
	auto startlhs = high_resolution_clock::now();
	std::cout << lhs_start(simplePlane, XMIN, XMAX, YMIN, YMAX, ZMAX, partitions, packages);
	auto stoplhs = high_resolution_clock::now();
	auto durationlhs = duration_cast<milliseconds>(stoplhs - startlhs);
	std::cout << " \t" << durationlhs.count() << "ms using " << partitions * partitions * partitions * packages << " randomly generated points" << std::endl;
	}