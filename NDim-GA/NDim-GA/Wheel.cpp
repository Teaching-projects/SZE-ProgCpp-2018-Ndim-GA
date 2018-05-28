#include "stdafx.h"
#include "Wheel.h"

Wheel::Wheel()
{
}

Wheel::Wheel(Chromosome c)
{
	chrom = c;
	ordervalue = c.getFitness();
}

Wheel::Wheel(Chromosome c, double val)
{
	chrom = c;
	ordervalue = val;
}

Chromosome Wheel::getChromosome()
{
	return chrom;
}

void Wheel::setChromosome(Chromosome nc)
{
	chrom = nc;
}

double Wheel::getOrderValue()
{
	return ordervalue;
}

void Wheel::setOrderValue(double nv)
{
	ordervalue = nv;
}

double Wheel::compareTo(Wheel w)
{
	if (ordervalue < w.getOrderValue()) return -1;
	if (ordervalue == w.getOrderValue()) return 0;
	return 1;
}

Wheel::~Wheel()
{
}