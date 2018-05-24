#include "stdafx.h"
#include "Chromosome.h"

Chromosome::Chromosome() 
{

};

Chromosome::Chromosome(vector<double> coordinate)
{
	p = coordinate;
}

Chromosome::Chromosome(vector<double> coordinate, double fitness)
{
	p = coordinate;
	f = fitness;
}

double Chromosome::getFitness()
{
	return f;
}

void Chromosome::setFitness(double nf)
{
	f = nf;
}

vector<double> Chromosome::getCoordinate() {
	return p;
}

void Chromosome::setCoordinate(vector<double> point)
{
	p = point;
}

void Chromosome::setCoordinateById(int id, double value) {
	p[id] = value;
}

double Chromosome::compareTo(Chromosome c)
{
	if (f > c.getFitness()) return -1;
	if (f == c.getFitness()) return 0;
	return 1;
}

Chromosome::~Chromosome() {}