#include <iostream>
#include <iomanip>
#include "Item.h"
#include "KnapsackProblemGenerator.h"
#include "RecursiveSolver.h"
#include "IterativeSolver.h"
#include <ctime>
#include <utility>
#include "GreedySolver.h"
#include <fstream>
#include <string>

const double MAX_WEIGHT = 200;
const int COUNT_OF_ELEMENTS = 23; // count of items
const int COUNT_OF_AVERAGE_LOADS = 3;

const bool PRINT_TO_FILE = true;
const bool USE_RANDOM_FOR_INPUT = true; // input from file if false

const std::string INPUT_FILE_NAME = "input1.txt";
const std::string OUTPUT_FILE_NAME = "output1.txt";

void input_method(double& M, std::vector<Item>& items, std::istream& fin);
void run_method(double M, int count_of_elements, std::ostream& ostr);
void run_test(double M, std::vector<Item> items, KnapsackProblemSolver* recursive_solver, KnapsackProblemSolver* iterative_solver, KnapsackProblemSolver* greedy_solver, std::ostream& ostr);
unsigned int run_method(double M, std::vector<Item> items, KnapsackProblemSolver* problem_solver, std::ostream& ostr);

int main()
{
	/*KnapsackProblemGenerator kpg(COUNT_OF_ELEMENTS, MAX_WEIGHT);
	KnapsackProblemSolver* recursive_solver = new RecursiveSolver();
	KnapsackProblemSolver* iterative_solver = new IterativeSolver();
	KnapsackProblemSolver* greedy_solver = new GreedySolver();*/

	std::ofstream fout("../" + OUTPUT_FILE_NAME);
	std::ostream& ostr = PRINT_TO_FILE ? fout : std::cout;

	std::ifstream fin("../" + INPUT_FILE_NAME);

	//int count_of_iteration = 1;
	//if (USE_RANDOM_FOR_INPUT) count_of_iteration = 1000;
	//for (int i = 0; i < count_of_iteration; i++)
	//{
	//	ostr << std::endl;
	//	ostr << std::endl;

	//	std::vector<Item> items;
	//	double M = MAX_WEIGHT;
	//	if (USE_RANDOM_FOR_INPUT)
	//	{
	//		// generate random items
	//		//items = kpg.get_random_items();
	//		items = kpg.get_bad_items();
	//		//items = kpg.get_avg_items();
	//		//items = kpg.get_good_items();
	//	}
	//	else
	//	{
	//		input_method(M, items, fin);
	//	}

	//	KnapsackProblemGenerator::print_knapsack_problem(items, M, ostr);
	//	ostr << std::endl;

	//	// greedy solution
	//	run_method(M, items, greedy_solver, ostr);

	//	// recursive solution
	//	run_method(M, items, recursive_solver, ostr);

	//	// iterative solution
	//	run_method(M, items, iterative_solver, ostr);

	//	ostr << std::endl;

	//	system("pause");
	//}

	run_method(MAX_WEIGHT, COUNT_OF_ELEMENTS, ostr);

	fin.close();
	fout.close();
}

void input_method(double& M, std::vector<Item>& items, std::istream& fin)
{
	int n;
	fin >> n >> M;
	items.reserve(n);
	for (int i = 0; i < n; i++)
	{
		Item it;
		fin >> it.weight;
		it.index = i;
		items.push_back(it);
	}

	for (int i = 0; i < n; i++)
	{
		fin >> items[i].value;
	}
}

void run_method(double M, int count_of_elements, std::ostream& ostr)
{
	KnapsackProblemSolver* recursive_solver = new RecursiveSolver();
	KnapsackProblemSolver* iterative_solver = new IterativeSolver();
	KnapsackProblemSolver* greedy_solver = new GreedySolver();
	std::vector<Item> items;

	for (int N = 1; N <= count_of_elements; N += 2)
	{
		KnapsackProblemGenerator kpg(N, M);
		items = kpg.get_bad_items();
		run_test(M, items, recursive_solver, iterative_solver, greedy_solver, ostr);

	}

	for (int N = 1; N <= count_of_elements; N += 2)
	{
		KnapsackProblemGenerator kpg(N, M);
		items = kpg.get_avg_items();
		run_test(M, items, recursive_solver, iterative_solver, greedy_solver, ostr);
	}

	for (int N = 1; N <= count_of_elements; N += 2)
	{
		KnapsackProblemGenerator kpg(N, M);
		items = kpg.get_good_items();
		run_test(M, items, recursive_solver, iterative_solver, greedy_solver, ostr);
	}
}

void run_test(double M, std::vector<Item> items, KnapsackProblemSolver* recursive_solver, KnapsackProblemSolver* iterative_solver, KnapsackProblemSolver* greedy_solver, std::ostream& ostr)
{
	KnapsackProblemGenerator::print_knapsack_problem(items, M, ostr);
	ostr << std::endl;

	double r1;
	double r2;
	double r3;
	unsigned long long r11 = 0;
	unsigned long long r22 = 0;
	unsigned long long r33 = 0;
	for (int i = 0; i < COUNT_OF_AVERAGE_LOADS; i++)
	{
		// greedy solution
		r11 += run_method(M, items, greedy_solver, ostr);

		// recursive solution
		r22 += run_method(M, items, recursive_solver, ostr);

		// iterative solution
		r33 += run_method(M, items, iterative_solver, ostr);

		ostr << std::endl;
	}

	r1 = (double)r11 / COUNT_OF_AVERAGE_LOADS;
	r2 = (double)r22 / COUNT_OF_AVERAGE_LOADS;
	r3 = (double)r33 / COUNT_OF_AVERAGE_LOADS;
	ostr << "AvgTime Greedy:" << std::fixed << std::setprecision(2) << r1 << std::endl;
	ostr << "AvgTime Recursive:" << std::fixed << std::setprecision(2) << r2 << std::endl;
	ostr << "AvgTime Iterative:" << std::fixed << std::setprecision(2) << r3 << std::endl;
	ostr << "__________________________________________________________________________________________" << std::endl;
}

unsigned int run_method(double M, std::vector<Item> items, KnapsackProblemSolver* problem_solver, std::ostream& ostr)
{
	unsigned int start_time = clock();
	Variant result = problem_solver->solve(items, M);
	problem_solver->print_variant(result, ostr);
	unsigned int end_time = clock();
	unsigned int r = end_time - start_time;
	ostr << "Time: " << r << "ms" << std::endl;
	ostr << std::endl;
	return r;
}
