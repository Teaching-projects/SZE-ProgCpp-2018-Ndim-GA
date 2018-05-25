// NDim-GA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "NDim-GA.h"


int main()
{
	NDim_GA(2, 100, 50, 70);
	getchar();
	return 0;
}

NDim_GA::NDim_GA(int dimension, int populationSize, int generationSize, int crossoverMax)
{
	dim = dimension;
	popsize = populationSize;
	generation = generationSize;
	crossover = crossoverMax;
	NDim_GA::simulate();
}

void NDim_GA::simulate()
{
	// POPULATION INIT
	vector<Chromosome> population = vector<Chromosome>();
	populationInit(population);

	for (int i = 0; i < generation; i++)
	{
		//INIT vars
		vector<Wheel> w = vector<Wheel>();
		vector<Chromosome> popbuff = vector<Chromosome>();

		wheelInit(population, w);
		/*for (int j = 0; j < popsize; j++)
		{
		printf("orderv: %f fitness: %f\n", w[j].getOrderValue(), w[j].getChromosome().getFitness());
		}*/
		double roulettemaxval = w[0].getOrderValue();
		double rouletteminval = w[popsize - 2].getOrderValue();
		//TODO
		//Valammiért túl megy a tömbön 
		popbuff = selection(rouletteminval, roulettemaxval, population, w);
		for (int j = 0; j < popsize; j++)
		{
			printf("fitness: %f\n", popbuff[j].getFitness());
		}
		// TODO
		// selectSurvivors
		population = popbuff;
	}
	for (int i = 0; i < popsize; i++)
	{
		printf("fitness: %f\n", population[i].getFitness());
	}
}


/**
*	Population initialization
*
*	//
*
*/
void NDim_GA::populationInit(vector<Chromosome> &population) {
	vector<double> point;
	double fitness;
	for (int i = 0; i < popsize; i++)
	{
		point = createNDimPoint();
		fitness = getFitness(point);
		population.push_back(Chromosome(point, fitness));
	}
}


/**
*	Creates an N dimension point
*/
vector<double> NDim_GA::createNDimPoint() {
	vector<double> point = vector<double>();
	for (int i = 0; i < dim; i++)
	{
		point.push_back(randomFloatNM(-4, 4));
	}
	return point;
}


/**
*	Returns fitness from test fucntions
*
*/
double NDim_GA::getFitness(vector<double> points) {
	return TestFunctions::AckleyFunction(points);
}


/**
*	Generates a random float number
*
*/
double NDim_GA::randomFloatNM(double xmin, double xmax) {
	return (xmin + (xmax - xmin)*((double)rand() / RAND_MAX));
}

/**
*	Roulette Wheel Init
*
*	Used for roulette wheel selection. Generate a wheel based on the current population.
*	@param population is the current population
*	@param w is the roulette wheel
*/
void NDim_GA::wheelInit(vector<Chromosome> population, vector<Wheel> &w) {
	double minval, maxval;

	for (Chromosome ch : population)
	{
		w.push_back(Wheel(ch));
	}

	sort(w.begin(), w.end());
	minval = w.begin()->getOrderValue();
	maxval = w.rbegin()->getOrderValue();
	for (vector<Wheel>::iterator it = w.begin(); it != w.end(); it++) {
		it->setOrderValue(abs(1000 * it->getOrderValue() - (abs(1000 * minval) + abs(1000 * maxval) + 1)));
	}
	for (int j = popsize - 2; j >= 0; j--)
	{
		w[j].setOrderValue(w[j].getOrderValue() + w[j + 1].getOrderValue());
	}
}

vector<Chromosome> NDim_GA::selection(double rouletteminval, double roulettemaxval, vector<Chromosome> population, vector<Wheel> w) {

	vector<Chromosome> popbuff = vector<Chromosome>();
	crossover = (int)randomFloatNM(1, popsize*((double)crossover / 100.0));
	for (int j = 0; j < population.size()*((double)crossover / 100.0); j++)
	{
		Chromosome parent1;
		Chromosome parent2;

		double randombuff = randomFloatNM(rouletteminval, roulettemaxval - 1);
		double randombuff2 = randomFloatNM(rouletteminval, roulettemaxval - 1);
		bool p1 = false;
		bool p2 = false;

		//	starts from the wheel's end, and runs until both parents are selected
		for (vector<Wheel>::reverse_iterator it = w.rbegin(); !p1 || !p2; it++)
		{
			if ((randombuff <= it->getOrderValue()) && !p1)
			{

				parent1 = it->getChromosome();
				p1 = true;;
			}
			if ((randombuff2 <= it->getOrderValue()) && !p2)
			{

				parent2 = it->getChromosome();
				p2 = true;;
			}

		}
		//	handling allels
		popbuff.push_back((parent1, parent2));
	}
	return popbuff;
}

/**
*	Single-point: A single crossover point on both parents' organism strings is selected. All data beyond that point in either organism string is swapped between the two parent organisms.
*
*	@params parent1 is the first parent
*	@params parent2 is the second parent
*/
Chromosome NDim_GA::single_point(Chromosome parent1, Chromosome parent2)
{
	Chromosome child = Chromosome();
	if ((int)randomFloatNM(1, 100) % 2 == 0)
	{
		child.setCoordinate(parent2.getCoordinate());
		for (int k = 0; k < (int)randomFloatNM(1, dim); k++)
		{
			child.setCoordinateById(k, parent1.getCoordinate()[k]);
		}
	}
	else
	{
		child.setCoordinate(parent1.getCoordinate());
		for (int k = 0; k < (int)randomFloatNM(1, dim); k++)
		{
			child.setCoordinateById(k, parent2.getCoordinate()[k]);
		}
	}
	child.setFitness(getFitness(child.getCoordinate()));
	return child;
}