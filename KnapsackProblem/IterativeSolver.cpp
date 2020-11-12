#include "IterativeSolver.h"
#include <stack>

std::string IterativeSolver::get_name() {
	return "Iterative method";
}

Variant IterativeSolver::solve(std::vector<Item> items, double M) {
	std::vector<Variant> knapsack_variants;
	// empty knapsack
	Variant empty;
	knapsack_variants.push_back(std::move(empty));

	// index of the best variant
	unsigned index = 0;

	// create all possible variants of the knapsack
	// Look every item
	for (const Item& item : items) {
		int n = knapsack_variants.size();
		// Look every possible variant
		for (int i = 0; i < n; i++) {
			Variant temp = knapsack_variants[i];

			temp.items.push_back(item);
			temp.sum_value += item.value;
			temp.sum_weight += item.weight;

			// if variants fits in knapsack
			if (temp.sum_weight <= M) {
				// if it the best variant. need remember it
				if (temp.sum_value > knapsack_variants[index].sum_value)
				{
					index = knapsack_variants.size();
				}

				// add to list new variant with current item
				knapsack_variants.push_back(std::move(temp));
			}
		}
	}

	return knapsack_variants[index];
}
