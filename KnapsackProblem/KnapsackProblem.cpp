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

double t_rec_min(int n)
{
	return 14.0 * n - 9.0;
}
double t_rec_max(int n)
{
	return 17 * pow(2, n) - 12;
}
double t_rec_avg(int n)
{
	return (17 * pow(2, n) - 7 + (n - 1) * 14.0) / 2.0;
}

double t_iter_min(int n)
{
	return 2.0 + 23.0 * n / 2 + 9.0 * n * n / 2;
}
double t_iter_max(int n)
{
	return 12.0 * pow(2, n) + 4.0 * n - 10;
}
double t_iter_avg(int n)
{
	return -22.0 + 24.0 * pow(1.5, n) + 4.0 * n;
}

double t_gre_min(int n)
{
	return 4.0 * n + n * log(n) + 5;
}
double t_gre_max(int n)
{
	return 9.0 * n + n * log(n);
}
double t_gre_avg(int n)
{
	return 6.5 * n + n * log(n) + 5;
}



const double MAX_WEIGHT = 200;
const int COUNT_OF_ELEMENTS = 23; // count of items
const int COUNT_OF_AVERAGE_LOADS = 3;
const int COUNT_OF_TESTING_GREEDY = 1000;

const bool PRINT_TO_FILE = true;
const bool USE_RANDOM_FOR_INPUT = true; // input from file if false

//const std::string INPUT_FILE_NAME = "input1.txt";
const std::string INPUT_FILE_NAME = "input1.txt";
const std::string OUTPUT_FILE_NAME = "output3.txt";

void input_method(double& M, std::vector<Item>& items, std::istream& fin);
void run_method(double M, int count_of_elements, std::ostream& ostr);
void run_test(double M, std::vector<Item> items, KnapsackProblemSolver* recursive_solver, KnapsackProblemSolver* iterative_solver, KnapsackProblemSolver* greedy_solver, std::ostream& ostr);
unsigned int run_method(double M, std::vector<Item> items, KnapsackProblemSolver* problem_solver, std::ostream& ostr);
void show_t_n(double (*fun)(int), double C, std::ostream& ostr);
void test_func_of_coplexity(std::ostream& ostr);
void test_greedy(std::ostream& ostr);

int main()
{
	std::ofstream fout("../" + OUTPUT_FILE_NAME);
	std::ostream& ostr = PRINT_TO_FILE ? fout : std::cout;

	std::ifstream fin("../" + INPUT_FILE_NAME);

	//// Usual load of KnapsackProblem for every method
	//KnapsackProblemGenerator kpg(COUNT_OF_ELEMENTS, MAX_WEIGHT);
	//KnapsackProblemSolver* recursive_solver = new RecursiveSolver();
	//KnapsackProblemSolver* iterative_solver = new IterativeSolver();
	//KnapsackProblemSolver* greedy_solver = new GreedySolver();

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
	//		
	//		
	//		ostr << std::endl;

	//	system("pause");
	//}


	//// Testing programm time
	//run_method(MAX_WEIGHT, COUNT_OF_ELEMENTS, ostr);


	//// Testing a function of complexity
	//test_func_of_coplexity(ostr);


	// Testing greedy method
	test_greedy(ostr);
	

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

void show_t_n(double (*fun)(int), double C, std::ostream& ostr)
{
	for (int N = 1; N <= COUNT_OF_ELEMENTS; N += 2)
	{
		ostr << std::fixed << std::setw(9) << std::setprecision(2) << fun(N) * C << " ";
	}
	ostr << std::endl;
}

void test_func_of_coplexity(std::ostream& ostr)
{
	for (int N = 1; N <= COUNT_OF_ELEMENTS; N += 2)
	{
		ostr << std::fixed << std::setw(9) << std::setprecision(2) << N << " ";
	}

	ostr << std::endl;
	ostr << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
	ostr << "t_rec_min" << std::endl;
	show_t_n(t_rec_min, 2.00 / t_rec_min(19), ostr);
	ostr << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
	ostr << "t_rec_max" << std::endl;
	show_t_n(t_rec_max, 5448.33 / t_rec_max(19), ostr);
	ostr << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
	ostr << "t_rec_avg" << std::endl;
	show_t_n(t_rec_avg, 3681.67 / t_rec_avg(19), ostr);
	ostr << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
	ostr << "t_iter_min" << std::endl;
	show_t_n(t_iter_min, 1.33 / t_iter_min(19), ostr);
	ostr << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
	ostr << "t_iter_max" << std::endl;
	show_t_n(t_iter_max, 6469.67 / t_iter_max(19), ostr);
	ostr << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
	ostr << "t_iter_avg" << std::endl;
	show_t_n(t_iter_avg, 3409.67 / t_iter_avg(19), ostr);
	ostr << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
	ostr << "t_gre_min" << std::endl;
	show_t_n(t_gre_min, 1.0 / 3.0 / t_gre_min(19), ostr);
	ostr << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
	ostr << "t_gre_max" << std::endl;
	show_t_n(t_gre_max, 2.0 / 3.0 / t_gre_max(19), ostr);
	ostr << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
	ostr << "t_gre_avg" << std::endl;
	show_t_n(t_gre_avg, 1.0 / 3.0 / t_gre_avg(19), ostr);
}

void test_greedy(std::ostream& ostr)
{
	KnapsackProblemSolver* recursive_solver = new RecursiveSolver();
	KnapsackProblemSolver* greedy_solver = new GreedySolver();

	for (int N = 1; N <= COUNT_OF_ELEMENTS; N += 2)
	{
		int count = 0;
		KnapsackProblemGenerator kpg(N, MAX_WEIGHT);
		for (int i = 0; i < COUNT_OF_TESTING_GREEDY; i++)
		{
			std::vector<Item> items = kpg.get_random_items();
			Variant res1 = greedy_solver->solve(items, MAX_WEIGHT);
			Variant res2 = recursive_solver->solve(items, MAX_WEIGHT);
			if (res1.sum_value == res2.sum_value) count++;
		}
		ostr << "N: " << N << " Percent " << (double(count) * 100 / COUNT_OF_TESTING_GREEDY) << std::endl;
	}
}
