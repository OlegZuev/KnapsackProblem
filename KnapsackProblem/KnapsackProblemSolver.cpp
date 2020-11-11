#include "KnapsackProblemSolver.h"
#include <iomanip>
#include <iostream>

/*
 * Print some variant of knapsack problem' solution
 * @param variant - knapsack problem' solution
 */
void KnapsackProblemSolver::print_variant(const Variant& variant) {
	const int output_width = 3;
	const int precision = 0;
	std::cout << "Sum value: " << variant.sum_value << std::endl;
	std::cout << this->get_name() << std::endl << "Weights: ";
	for (const Item& item : variant.items) {
		std::cout << std::fixed << std::setprecision(precision) << std::setw(output_width) << item.weight << " ";
	}

	std::cout << std::endl << "Values:  ";
	for (const Item& item : variant.items) {
		std::cout << std::fixed << std::setprecision(precision) << std::setw(output_width) << item.value << " ";
	}

	std::cout << std::endl;
}
