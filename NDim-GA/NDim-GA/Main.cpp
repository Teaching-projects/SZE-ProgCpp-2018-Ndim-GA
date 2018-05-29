// Main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h";
#include "NDimBeA.h";
#include "NDim-GA.h";

int main() {
	srand(time(NULL));
	//NDimBeA(5, 50, 300, 0, 50, 50, -4.0, 4.0);
	NDim_GA(2, 100, 200, 0, 70, 0, -4.0, 4.0);
	getchar();
	return 0;
}