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
const int COUNT_OF_ELEMENTS = 28; // count of items

const bool PRINT_TO_FILE = false;
const bool USE_RANDOM_FOR_INPUT = true; // input from file if false

const std::string INPUT_FILE_NAME = "input1.txt";
const std::string OUTPUT_FILE_NAME = "output1.txt";

void input_method(double& M, std::vector<Item>& items, std::istream& fin);
void run_method(double M, std::vector<Item> items, KnapsackProblemSolver* problem_solver, std::ostream& ostr);

int main() {
	KnapsackProblemGenerator kpg(COUNT_OF_ELEMENTS, MAX_WEIGHT);
	KnapsackProblemSolver* recursive_solver = new RecursiveSolver();
	KnapsackProblemSolver* iterative_solver = new IterativeSolver();
	KnapsackProblemSolver* greedy_solver = new GreedySolver();

	std::ofstream fout("../" + OUTPUT_FILE_NAME);
	std::ostream& ostr = PRINT_TO_FILE ? fout : std::cout;

	std::ifstream fin("../" + INPUT_FILE_NAME);

	int count_of_iteration = 1;
	if (USE_RANDOM_FOR_INPUT) count_of_iteration = 1000;
	for (int i = 0; i < count_of_iteration; i++) {
		ostr << std::endl;
		ostr << std::endl;

		std::vector<Item> items;
		double M = MAX_WEIGHT;
		if (USE_RANDOM_FOR_INPUT) {
			// generate random items
			//items = kpg.get_random_items();

			/*items.reserve(COUNT_OF_ELEMENTS);
			for (int i = 0; i < COUNT_OF_ELEMENTS; i++) {
			items.push_back(Item{1, double(i), i + 1});
			}*/

			items.reserve(COUNT_OF_ELEMENTS);
			for (int i = 0; i < COUNT_OF_ELEMENTS; i++) {
			items.push_back(Item{2* MAX_WEIGHT / items.size(), double(i), i + 1});
			}

			/*items.reserve(COUNT_OF_ELEMENTS);
			for (int i = 0; i < COUNT_OF_ELEMENTS; i++)
			{
				items.push_back(Item{ MAX_WEIGHT, double(i), i + 1 });
			}*/
		}
		else
		{
			input_method(M, items, fin);
		}

		KnapsackProblemGenerator::print_knapsack_problem(items, M, ostr);
		ostr << std::endl;

		// greedy solution
		run_method(M, items, greedy_solver, ostr);

		// recursive solution
		//run_method(M, items, recursive_solver, ostr);

		// iterative solution
		run_method(M, items, iterative_solver, ostr);

		ostr << std::endl;

		system("pause");
	}

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

void run_method(double M, std::vector<Item> items, KnapsackProblemSolver* problem_solver, std::ostream& ostr) {
	unsigned int start_time = clock();
	Variant result = problem_solver->solve(items, M);
	problem_solver->print_variant(result, ostr);
	unsigned int end_time = clock();
	ostr << "Time: " << end_time - start_time << "ms" << std::endl;
	ostr << std::endl;
}
