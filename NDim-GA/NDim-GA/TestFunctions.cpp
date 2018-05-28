#include "stdafx.h"
#include "TestFunctions.h"


/**
*	Source
*	The Ackley function is widely used for testing optimization algorithms.
*	In its two-dimensional form, as shown in the plot above, it is characterized by a nearly flat outer region,
*	and a large hole at the centre. The function poses a risk for optimization algorithms, particularly hillclimbing algorithms,
*	to be trapped in one of its many local minima.
*	The function is usually evaluated on the hypercube xi ? [-32.768, 32.768], for all i = 1, …, d, although it may also be restricted to a smaller domain.
*	Global minimum: f(0,...,0) = 0
*	Recommended variable values are: a = 20, b = 0.2 and c = 2?.
*	source: https://www.sfu.ca/~ssurjano/ackley.html
*	@param points is an N dimension point
*/
double TestFunctions::AckleyFunction(vector<double> points) {
	double fitness;
	double sqrtSum = 0;
	double expCosSum = 0;

	for (vector<double>::iterator it = points.begin(); it != points.end(); it++)
	{
		sqrtSum = sqrtSum + (pow(*it, 2.0));
		expCosSum = expCosSum + (cos(ACKLEY_C* *it));
	}
	fitness = (-1.0 * (double)ACKLEY_A) * exp((double)-ACKLEY_B * sqrt((1 / (double)points.size())*sqrtSum)) - exp((1 / (double)points.size())*expCosSum) + (double)ACKLEY_A + exp(1.0);
	return fitness;
}
