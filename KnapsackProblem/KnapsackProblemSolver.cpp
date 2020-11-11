#include "KnapsackProblemSolver.h"
#include <iomanip>
#include <iostream>

/*
 * Print some variant of knapsack problem' solution
 * @param variant - knapsack problem' solution
 */
void KnapsackProblemSolver::print_variant(const Variant& variant) {
	const int output_width = 3;
	for (const Item& item : variant.items) {
		std::cout << std::fixed << std::setw(output_width) << item.weight << " ";
	}

	std::cout << std::endl;
	for (const Item& item : variant.items) {
		std::cout << std::fixed << std::setw(output_width) << item.value << " ";
	}

	std::cout << std::endl;
}
