#include "MonteCarlo.h"
#include <vector>

struct Partition {

	float xMin;
	float xMax;
	float yMin;
	float yMax;
	float zMin;
	float zMax;

};

float lhs_start(float(*fun)(float, float), float xmin, float xmax, float ymin, float ymax, float zmax, uint partitions, uint packages);
Partition*** get_partitioned_matrix(float xmax, float xmin, float ymax, float ymin, float zmax, float partitions);
