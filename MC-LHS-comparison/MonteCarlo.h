#pragma once
typedef unsigned int uint;

#include <iostream>
#include <random>
#include <iostream>

float monte_carlo_start(float(*fun)(float, float), float xmin, float xmax, float ymin, float ymax, float zmax, uint precision);
float generate_random_float(float min, float max);
bool does_belong_to(float(*fun)(float, float), float x, float y, float z);