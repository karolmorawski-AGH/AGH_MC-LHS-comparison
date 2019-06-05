#include "MonteCarlo.h"

float monte_carlo_start(float(*fun)(float, float), float xmin, float xmax, float ymin, float ymax, float zmax, uint precision)
{
	uint hit = 0;
	float volume = abs(xmax - xmin) * abs(ymax - ymin) * abs(zmax);

	for (uint i = 0; i < precision; i++) {
		/*Generating point coordinates*/
		float x = generate_random_float(xmin, xmax);
		float y = generate_random_float(ymin, ymax);
		float z = generate_random_float(0, zmax);

		/*Checking whether randomly generated point "hits" desired area under or on the plane*/
		if (does_belong_to(fun, x, y, z) == true) {
			hit++;
		}
	}
	
	//return volume;
	return (volume * hit) / precision;
}

float generate_random_float(float min, float max)
{
	/*Will be used to obtain a seed for the random number engine*/
	std::random_device rd;  
	/*Standard mersenne_twister_engine seeded with rd()*/
	std::mt19937 gen(rd()); 
	std::uniform_real_distribution<float> dis(min, max);

	return dis(gen);
}

bool does_belong_to(float(*fun)(float, float), float x, float y, float z)
{
	if (fun(x, y) >= z && fun(x, y) >= 0) {
		return true;
	}
	else {
		return false;
	}
}
