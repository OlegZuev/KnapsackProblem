#include <iostream>
#include <iomanip>
#include "Item.h"
#include "KnapsackProblemGenerator.h"
#include "RecursiveSolver.h"

const int MAX_WEIGHT = 15;

int main()
{

	// first test of KnapsackProblemGenerator and RecursiveSolver
	/*KnapsackProblemGenerator kpg(MAX_WEIGHT);

	for (int i = 0; i < 10000; i++)
	{
		std::vector<Item> items = kpg.get_random_items();
		kpg.print_knapsack_problem(items, MAX_WEIGHT, std::cout);
		RecursiveSolver rs(MAX_WEIGHT);
		rs.Solver(items);
		rs.PrintResult();
		system("pause");
	}*/

	std::cout << "Hello World!\n";
}
