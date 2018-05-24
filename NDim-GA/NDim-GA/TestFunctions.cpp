#include "stdafx.h"
#include "TestFunctions.h"

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
