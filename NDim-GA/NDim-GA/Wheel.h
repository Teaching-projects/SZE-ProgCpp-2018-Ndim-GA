#pragma once
#include "Chromosome.h"

class Wheel
{
public:
	Wheel();
	Wheel(Chromosome c);
	Wheel(Chromosome c, double val);

	Chromosome getChromosome();
	void setChromosome(Chromosome nc);

	double getOrderValue();
	void setOrderValue(double nv);

	double compareTo(Wheel w);
	bool operator <(const Wheel & wheel) const
	{
		return ordervalue < wheel.ordervalue;
	}

	~Wheel();
private:
	Chromosome chrom;
	double ordervalue;
};