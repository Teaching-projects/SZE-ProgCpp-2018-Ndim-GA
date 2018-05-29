#pragma once
#include "EvoAlgs.h"
#include "Wheel.h"

class NDim_GA : public EvoAlgs
{
public:
	NDim_GA(int dimension, int populationSize, int generationSize, int crossoverMax, int testFunctionId, double min, double max);
private:
	int crossover;

	void simulate();
	void wheelInit(vector<Chromosome> population, vector<Wheel> &w);
	vector<Chromosome> selection(double rouletteminval, double roulettemaxval, vector<Chromosome> population, vector<Wheel> w);
	void selectingSurvivors(double rouletteminval, double roulettemaxval, vector<Chromosome> population, vector<Wheel> w, vector<Chromosome> &popbuff);
	Chromosome single_point(Chromosome parent1, Chromosome parent2);
};