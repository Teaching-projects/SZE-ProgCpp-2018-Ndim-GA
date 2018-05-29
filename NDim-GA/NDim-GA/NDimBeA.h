#pragma once
#include "EvoAlgs.h"
class NDimBeA : public EvoAlgs
{
public:
	NDimBeA(int dimension, int gen, int populationSize, int testF, int clones, int inf, double min, double max);
	~NDimBeA();
private:
	int nclone;
	int infection;

	void simulate();
	Chromosome bacterialMutation(Chromosome p, vector<int> shuffle);
	void bacterialInfection(vector<Chromosome> &p);
};

