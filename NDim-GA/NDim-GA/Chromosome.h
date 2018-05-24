#pragma once
#include "stdafx.h"
#include <vector>

using namespace std;

class Chromosome 
{
public:
	Chromosome();
	Chromosome(vector<double> coordinate);
	Chromosome(vector<double> coordinate, double fitness);

	double getFitness();
	void setFitness(double nf);

	vector<double> getCoordinate();
	void setCoordinate(vector<double> np);
	void setCoordinateById(int id, double value);

	double compareTo(Chromosome c);
	bool operator <(const Chromosome & c) const
	{
		return f > c.f;
	}

	~Chromosome();

private:
	vector<double> p;
	double f;
};