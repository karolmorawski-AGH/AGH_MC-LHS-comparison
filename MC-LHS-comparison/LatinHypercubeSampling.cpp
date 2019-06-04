#include "LatinHypercubeSampling.h"


float lhs_start(float(*fun)(float, float), float xmin, float xmax, float ymin, float ymax, float zmax, uint partitions, uint packages)
{
	uint hit = 0;
	float volume = abs(xmax - xmin) * abs(ymax - ymin) * abs(zmax);

	Partition*** tab = get_partitioned_matrix(xmax, xmin, ymax, ymin, zmax, partitions);

	for (uint i = 0; i < packages; i++) {
		for (int i = 0; i < partitions; i++) {
			for (int j = 0; j < partitions; j++) {
				for (int k = 0; k < partitions; k++) {
					/*Random sampling*/
					//std::cout << tab[i][j][k].xMin << "\n";
					float x = generate_random_float(tab[i][j][k].xMin, tab[i][j][k].xMax);
					float y = generate_random_float(tab[i][j][k].yMin, tab[i][j][k].yMax);
					float z = generate_random_float(tab[i][j][k].zMin, tab[i][j][k].zMax);

					//float x = 0, y = 0, z = 0;
					//std::cout  << " FOR: " << "xmin: " << tab[i][j][k].xMin << " xmax: " << tab[i][j][k].xMax << "ymin: " << tab[i][j][k].yMin << " ymax: " << tab[i][j][k].yMax << "zmin: " << tab[i][j][k].zMin << " zmax: " << tab[i][j][k].zMax << "VALUES: " << " x: " << x << " y: " << y << " z: " << z << std::endl;

					/*Checking whether randomly generated point "hits" desired area under or on the plane*/
					if (does_belong_to(fun, x, y, z) == true) {
						hit++;
					}
				}
			}
		}
	}

	//return hit;
	return (hit * volume) / (packages * partitions * partitions * partitions);
}


Partition*** get_partitioned_matrix(float xmax, float xmin, float ymax, float ymin, float zmax, float partitions) {
	


	float xLength = xmax - xmin;
	float yLength = ymax - ymin;
	float zLength = zmax - 0;
	

	float avgX = xLength / partitions;
	float avgY = yLength / partitions;
	float avgZ = zLength / partitions;

	/*3D Array*/
	Partition*** tab = new Partition * *[partitions];
	for (int i = 0; i < partitions; i++) {
		tab[i] = new Partition * [partitions];
		for (int j = 0; j < partitions; j++) {
			tab[i][j] = new Partition[partitions];
		}
	}

	float xStart = xmin;
	float xEnd = xmin;
	float yStart = ymin;
	float yEnd = ymin;
	float zStart = 0.f; 
	float zEnd = 0.f;
	for (int i = 0; i < partitions; i++) {
		//slicing x axis

		if (i != partitions - 1) {
			xEnd += avgX;
		} else {
			xEnd = xmax;
		}

		yStart = ymin;
		yEnd = ymin;

		for (int j = 0; j < partitions; j++) {
			//slicing y axis

			if (j != partitions - 1) {
				yEnd += avgY;
			}
			else {
				yEnd = ymax;
			}

			zStart = 0.f;
			zEnd = 0.f;

			for (int k = 0; k < partitions; k++) {
				//slicing z axis

				if (k != partitions - 1) {
					zEnd += avgZ;
				}
				else {
					zEnd = zmax;
				}

				tab[i][j][k].xMin = xStart;
				tab[i][j][k].yMin = yStart;
				tab[i][j][k].zMin = zStart;

				tab[i][j][k].xMax = xEnd;
				tab[i][j][k].yMax = yEnd;
				tab[i][j][k].zMax = zEnd;

				zStart += avgZ;
			}

			yStart += avgY;


		}

		xStart += avgX;

	}

	return tab;
}