#include "LatinHypercubeSampling.h"

float lhs_start(float(*fun)(float, float), float xmin, float xmax, float ymin, float ymax, float zmax, int precision)
{
	uint hit = 0;
	float volume = abs(xmax - xmin) * abs(ymax - ymin) * abs(10);

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

	return (volume * hit) / precision;
}
