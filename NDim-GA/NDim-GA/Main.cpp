// Main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h";
#include "NDimBeA.h";
#include "NDim-GA.h";

int main() {
	srand(time(NULL));
	NDimBeA(2, 50, 100, 0, 50, 50, -4.0, 4.0);
	//NDim_GA(4, 100, 200, 2, 70, 1, 0.05,-500.0, 500.0);
	getchar();
	return 0;
}