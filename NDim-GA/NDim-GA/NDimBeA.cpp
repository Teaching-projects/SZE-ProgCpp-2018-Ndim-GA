#include "stdafx.h"
#include "NDimBeA.h"


NDimBeA::NDimBeA(int dimension, int gen, int populationSize,int testF, int clones, int inf, double min, double max) : EvoAlgs(gen, populationSize, dimension, testF, min, max)
{
	nclone = clones;
	infection = inf;
	simulate();
}
NDimBeA::~NDimBeA() {}
void NDimBeA::simulate() {
	vector<Chromosome> population = vector<Chromosome>();
	populationInit(population);

	for (int i = 0; i < generation; i++)
	{
		for (int j = 0; j < populationSize; j++)
		{
			population[j] = bacterialMutation(population[j]);
		}
		bacterialInfection(population);
	}
	for (int i = 0; i < populationSize; i++)
	{
		printf("fitness: %f\n", population[i].getFitness());
	}
}
Chromosome NDimBeA::bacterialMutation(Chromosome p) {
	vector<int> shuffle(dimension);
	Chromosome original = p;
	for (int i = 0; i < dimension; i++)
	{
		shuffle[i] = i;
	}
	for (int i = 0; i < dimension; i++)
	{
		int rand = randomFloatNM(0, dimension - 1);
		int tmp = shuffle[i];
		shuffle[i] = shuffle[rand];
		shuffle[rand] = tmp;
	}
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < infection; j++)
		{
			p.getCoordinate()[shuffle[i]] = randomFloatNM(minimum, maximum);
			double tmpFitness = getFitness(p.getCoordinate());
			if (p.getFitness() > tmpFitness) {
				original = Chromosome(p.getCoordinate(), tmpFitness);
			}
		}
	}
	return original;
}
void NDimBeA::bacterialInfection(vector<Chromosome> &p) {
	for (int i = 0; i < infection; i++)
	{
		Chromosome good = p[round(randomFloatNM(0, populationSize / 2))];
		int selectedPart = round(randomFloatNM(0, dimension - 1));
		int bad = round(randomFloatNM(populationSize / 2, populationSize));
		p[bad].getCoordinate()[selectedPart] = good.getCoordinate()[selectedPart];
		p[bad].setFitness(getFitness(p[bad].getCoordinate()));
	}
}