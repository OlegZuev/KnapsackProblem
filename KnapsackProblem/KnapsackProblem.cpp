#include <iostream>
#include <iomanip>
#include "Item.h"
#include "KnapsackProblemGenerator.h"
#include "RecursiveSolver.h"
#include "IterativeSolver.h"
#include <ctime>

#include "GreedySolver.h"

const double MAX_WEIGHT = 200;
const double MULTIPLIER = 20; //how many items

void run_method(double M, std::vector<Item> items, KnapsackProblemSolver* problem_solver);

int main()
{

	// first test of KnapsackProblemGenerator and RecursiveSolver
	KnapsackProblemGenerator kpg(MAX_WEIGHT);
	kpg.set_weight_multiplier(MULTIPLIER);



	KnapsackProblemSolver* recursive_solver = new RecursiveSolver();
	KnapsackProblemSolver* iterative_solver = new IterativeSolver();
	KnapsackProblemSolver* greedy_solver = new GreedySolver();

	for (int i = 0; i < 10000; i++)
	{
		std::cout << std::endl;
		std::cout << std::endl;

		// generate random items
		std::vector<Item> items = kpg.get_random_items();
		kpg.print_knapsack_problem(items, MAX_WEIGHT, std::cout);
		std::cout << std::endl;

		// unsigned int start_time = clock(); // начальное время
		// // recursive solution
		// RecursiveSolver rs(MAX_WEIGHT);
		// rs.Solver(items);
		// rs.PrintResult();
		// unsigned int end_time = clock(); // конечное время
		// std::cout << "time: " << end_time - start_time << std::endl; // искомое время
		
		// recursive solution
		run_method(MAX_WEIGHT, items, recursive_solver);

		// iterative solution
		run_method(MAX_WEIGHT, items, iterative_solver);

		// greedy solution
		run_method(MAX_WEIGHT, items, greedy_solver);

		std::cout << std::endl;

		system("pause");
	}

	std::cout << "Hello World!\n";
}


void run_method(double M, std::vector<Item> items, KnapsackProblemSolver* problem_solver)
{
	unsigned int start_time = clock(); 
	Variant result = problem_solver->solve(items, M);
	problem_solver->print_variant(result);
	unsigned int end_time = clock();
	std::cout << "Time: " << end_time - start_time << "ms" << std::endl;
	std::cout << std::endl;
}
