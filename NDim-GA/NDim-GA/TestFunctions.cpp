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

/**
*	Source
*	The Schwefel function is complex, with many local minima.
*	The function is usually evaluated on the hypercube xi ? [-500, 500], for all i = 1, …, d.
*	Global minimum f = 0 at x = (420.9687,...,420.9687)
*	source: https://www.sfu.ca/~ssurjano/schwef.html
*	@param points is an N dimension point
*/
double TestFunctions::SchwefelFunction(vector<double> points) {
	double fitness = 0;
	for (vector<double>::iterator it = points.begin(); it != points.end(); it++)
	{
		fitness = fitness + (*it * sin(sqrt(abs(*it))));
	}
	return (points.size() * 418.9829) - fitness;
}

/**
*	Source
*	The Rastrigin function has several local minima.It is highly multimodal,
*	but locations of the minima are regularly distributed.
*	The function is usually evaluated on the hypercube xi ? [-5.12, 5.12], for all i = 1, …, d.
*	Global minimum f(x) = 0 x = (0,...,0)
*	source:	https://www.sfu.ca/~ssurjano/rastr.html
*	@param points is an N dimension point
*/
double TestFunctions::RastriginsFunction(vector<double> points)
{
	double fitness = 0;
	for (vector<double>::iterator it = points.begin(); it != points.end(); it++)
	{
		fitness = fitness + (pow(*it, 2.0) - (RASTRIGIN_A * cos(2.0 * MPI * *it)));
	}
	return (RASTRIGIN_A*points.size()) + fitness;
}

/**
*	Dimension: d
*	The function has a (minimum) solution of f = -0.42888194248 at x = -0.707107 (negative square root of 2, divided by 2), and y = 0.0.
*	xi ? [-2.0, 2.0], for all i = 1, …, d.
*	source: https://jamesmccaffrey.wordpress.com/2013/12/16/graphing-the-3d-double-dip-function/
*	@param points is an N dimension point
*/
double TestFunctions::DoubleDipFunction(vector<double> points) {
	double tmp = 0;
	for (vector<double>::iterator it = points.begin(); it != points.end(); it++)
	{
		tmp = tmp + pow(*it, 2.0);
	}
	return tmp * exp(-1 * tmp);
}
