#include <iostream>
#include <iomanip>
#include "Item.h"
#include "KnapsackProblemGenerator.h"
#include "RecursiveSolver.h"
#include "IterativeSolver.h"
#include <ctime>
#include <utility>
#include "GreedySolver.h"

const double MAX_WEIGHT = 200;
const int COUNT_OF_ELEMENTS = 15; //how many items

void run_method(double M, std::vector<Item> items, KnapsackProblemSolver* problem_solver);

int main() {
	// first test of KnapsackProblemGenerator and RecursiveSolver
	KnapsackProblemGenerator kpg(COUNT_OF_ELEMENTS, MAX_WEIGHT);
	KnapsackProblemSolver* recursive_solver = new RecursiveSolver();
	KnapsackProblemSolver* iterative_solver = new IterativeSolver();
	KnapsackProblemSolver* greedy_solver = new GreedySolver();

	for (int i = 0; i < 10000; i++) {
		std::cout << std::endl;
		std::cout << std::endl;

		// generate random items
		//std::vector<Item> items = kpg.get_random_items();
		std::vector<Item> items;
		items.reserve(COUNT_OF_ELEMENTS);
		for (int i = 0; i < COUNT_OF_ELEMENTS; i++) {
		items.push_back(Item{1, double(i), i + 1});
		}

		/*std::vector<Item> items;
		items.reserve(COUNT_OF_ELEMENTS);
		for (int i = 0; i < COUNT_OF_ELEMENTS; i++)
		{
			items.push_back(Item{ MAX_WEIGHT, double(i), i + 1 });
		}*/

		KnapsackProblemGenerator::print_knapsack_problem(items, MAX_WEIGHT, std::cout);
		std::cout << std::endl;

		// greedy solution
		run_method(MAX_WEIGHT, items, greedy_solver);

		// recursive solution
		//run_method(MAX_WEIGHT, items, recursive_solver);

		// iterative solution
		run_method(MAX_WEIGHT, items, iterative_solver);

		std::cout << std::endl;

		system("pause");
	}

	std::cout << "Hello World!\n";
}


void run_method(double M, std::vector<Item> items, KnapsackProblemSolver* problem_solver) {
	unsigned int start_time = clock();
	Variant result = problem_solver->solve(items, M);
	problem_solver->print_variant(result);
	unsigned int end_time = clock();
	std::cout << "Time: " << end_time - start_time << "ms" << std::endl;
	std::cout << std::endl;
}
