#include "KnapsackProblemSolver.h"
#include <iomanip>
#include <iostream>

/*
 * Print some variant of knapsack problem' solution
 * @param variant - knapsack problem' solution
 */
void KnapsackProblemSolver::print_variant(const Variant& variant, std::ostream& ostr) {
	const int output_width = 3;
	const int precision = 0;
	ostr << "Sum value: " << variant.sum_value << std::endl;
	ostr << this->get_name();
	ostr << std::endl << "Indexes:  ";
	for (const Item& item : variant.items) {
		ostr << std::fixed << std::setprecision(precision) << std::setw(output_width) << item.index << " ";
	}
	
	ostr << std::endl << "Weights: ";
	for (const Item& item : variant.items) {
		ostr << std::fixed << std::setprecision(precision) << std::setw(output_width) << item.weight << " ";
	}

	ostr << std::endl << "Values:  ";
	for (const Item& item : variant.items) {
		ostr << std::fixed << std::setprecision(precision) << std::setw(output_width) << item.value << " ";
	}
	
	ostr << std::endl;
}
