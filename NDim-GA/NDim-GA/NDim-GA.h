#pragma once
#include "EvoAlgs.h"
#include "Wheel.h"

class NDim_GA : public EvoAlgs
{
public:
	NDim_GA(int dimension, int populationSize, int generationSize, int crossoverId, int crossoverMax, int testFunctionId, double mutationMax, double min, double max);
private:
	int crossover;
	int crossoverType;
	double mutation;

	void simulate();
	void wheelInit(vector<Chromosome> population, vector<Wheel> &w);
	vector<Chromosome> selection(double rouletteminval, double roulettemaxval, vector<Chromosome> population, vector<Wheel> w);
	void selectingSurvivors(double rouletteminval, double roulettemaxval, vector<Chromosome> population, vector<Wheel> w, vector<Chromosome> &popbuff);
	void doMutation(vector<Chromosome> &popbuff);

	Chromosome doCrossover(Chromosome parent1, Chromosome parent2);
	Chromosome single_point(Chromosome parent1, Chromosome parent2);
	Chromosome two_point(Chromosome parent1, Chromosome parent2);
	Chromosome uniform(Chromosome parent1, Chromosome parent2);
};