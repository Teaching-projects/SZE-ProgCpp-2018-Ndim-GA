#pragma once
#include <vector>
#include <algorithm>
#include "Chromosome.h"
#include "TestFunctions.h"
#include "Wheel.h"

class NDim_GA 
{
public:
	NDim_GA(int dimension, int populationSize, int generationSize, int crossoverMax, int testFunctionId);
private:
	int dim;
	int popsize;
	int generation;
	int crossover;
	int testFunction;

	void simulate();
	void populationInit(vector < Chromosome> &population);
	vector<double> createNDimPoint();
	double getFitness(vector<double> points);
	void wheelInit(vector<Chromosome> population, vector<Wheel> &w);
	double randomFloatNM(double xmin, double xmax);
	vector<Chromosome> selection(double rouletteminval, double roulettemaxval, vector<Chromosome> population, vector<Wheel> w);
	void selectingSurvivors(double rouletteminval, double roulettemaxval, vector<Chromosome> population, vector<Wheel> w, vector<Chromosome> &popbuff);
	Chromosome single_point(Chromosome parent1, Chromosome parent2);
};