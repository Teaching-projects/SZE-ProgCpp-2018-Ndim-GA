#pragma once
#include "stdafx.h"
#include <vector>
#include <algorithm>
#include "Chromosome.h"
#include "TestFunctions.h"

class EvoAlgs
{
public:
	EvoAlgs(int gen, int popSize, int dim, int testF, double min, double max);
	EvoAlgs();
	virtual ~EvoAlgs();
protected:
	int generation;
	int populationSize;
	int dimension;
	int testFunction;
	double minimum;
	double maximum;

	void populationInit(vector < Chromosome> &population);
	vector<double> createNDimPoint(double min, double max);
	double getFitness(vector<double> points);
	double randomFloatNM(double xmin, double xmax);
};

