#include <iostream>
#include <iomanip>
#include "Item.h"
#include "KnapsackProblemGenerator.h"
#include "RecursiveSolver.h"
#include "IterativeSolver.h"

const int MAX_WEIGHT = 10;
const double MULTIPLIER = 2; //how mane items

// kovil77`s print. IDK need to make interface and use 1 print for all methods.
// And (or) need to put it somewhere else.
void PrintResult(int max_value, std::vector<Item> items);

int main()
{

	// first test of KnapsackProblemGenerator and RecursiveSolver
	KnapsackProblemGenerator kpg(MAX_WEIGHT);
	kpg.set_weight_multiplier(MULTIPLIER);

	for (int i = 0; i < 10000; i++)
	{
		std::cout << std::endl;
		std::cout << std::endl;

		// generate random items
		std::vector<Item> items = kpg.get_random_items();
		kpg.print_knapsack_problem(items, MAX_WEIGHT, std::cout);

		// recursive solution
		RecursiveSolver rs(MAX_WEIGHT);
		rs.Solver(items);
		rs.PrintResult();

		std::cout << std::endl;

		// iterative solution
		IterativeSolver is;
		is.Solver(items, MAX_WEIGHT);
		PrintResult(is.best_value, is.result);

		system("pause");
	}

	std::cout << "Hello World!\n";
}


void PrintResult(int max_value, std::vector<Item> items)
{
	std::cout << "Result value: " << max_value << std::endl;
	for (int i = 0; i < items.size(); i++)
		std::cout << items[i].value << " " << items[i].weight << std::endl;
}
