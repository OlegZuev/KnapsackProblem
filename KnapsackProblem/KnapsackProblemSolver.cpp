#include "KnapsackProblemSolver.h"
#include <iomanip>
#include <iostream>

void KnapsackProblemSolver::print_variant(const Variant& variant) {
	const int output_width = 3;
	for (Item item : variant.items) {
		std::cout << std::fixed << std::setw(output_width) << item.weight << " ";
	}

	std::cout << std::endl;
	for (Item item : variant.items) {
		std::cout << std::fixed << std::setw(output_width) << item.value << " ";
	}

	std::cout << std::endl;
}
