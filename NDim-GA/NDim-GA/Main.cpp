// Main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h";
#include "NDimBeA.h";
#include "NDim-GA.h";

int main() {
	//NDimBeA(2, 10, 120, 0, 20, 20, -4.0, 4.0);
	NDim_GA(2, 200, 100, 0, 70, 0, 1, 0);
	getchar();
	return 0;
}