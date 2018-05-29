#include "stdafx.h"
#include "EvoAlgs.h"


EvoAlgs::EvoAlgs(int gen, int popSize, int dim, int testF, double min, double max)
{
	generation = gen;
	populationSize = popSize;
	dimension = dim;
	testFunction = testF;
	minimum = min;
	maximum = max;
}

EvoAlgs::EvoAlgs() {}
EvoAlgs::~EvoAlgs()
{
}

void EvoAlgs::populationInit(vector<Chromosome> &population) {
	vector<double> point;
	double fitness;
	for (int i = 0; i < populationSize; i++)
	{
		point = createNDimPoint(minimum, maximum);
		fitness = getFitness(point);
		population.push_back(Chromosome(point, fitness));
	}
}
/**
*	Creates an N dimension point
*/
vector<double> EvoAlgs::createNDimPoint(double min, double max) {
	vector<double> point = vector<double>();
	for (int i = 0; i < dimension; i++)
	{
		point.push_back(randomFloatNM(min, max));
	}
	return point;
}

double EvoAlgs::getFitness(vector<double> points) {
	switch (testFunction) {
	case 0:
		return TestFunctions::AckleyFunction(points);
	case 1:
		return TestFunctions::SchwefelFunction(points);
	case 2:
		return TestFunctions::RastriginsFunction(points);
	default:
		return 0.0;
	}
}
/**
*	Generates a random float number
*
*/
double EvoAlgs::randomFloatNM(double xmin, double xmax) {
	return (xmin + (xmax - xmin)*((double)rand() / RAND_MAX));
}