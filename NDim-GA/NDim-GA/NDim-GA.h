#pragma once
#include <vector>
#include <algorithm>
#include "Chromosome.h"
#include "TestFunctions.h"
#include "Wheel.h"

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
	void NDim_GA::wheelInit(vector<Chromosome> population, vector<Wheel> &w);
	double randomFloatNM(double xmin, double xmax);
};