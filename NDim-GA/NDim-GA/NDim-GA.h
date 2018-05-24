#pragma once
#include <vector>
#include "Chromosome.h"
#include "TestFunctions.h"

class NDim_GA 
{
public:
	NDim_GA(int dimension, int populationSize, int generationSize);
private:
	int dim;
	int popsize;
	int generation;

	void simulate();
	void populationInit(vector < Chromosome> &population);
	vector<double> createNDimPoint();
	double getFitness(vector<double> points);

	double randomFloatNM(double xmin, double xmax);
};