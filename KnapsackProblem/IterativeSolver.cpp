#include "IterativeSolver.h"

std::string IterativeSolver::get_name() {
	return "Iterative method";
}

Variant IterativeSolver::solve(std::vector<Item> items, double M) {
	std::vector<Variant> knapsack_variants;
	// empty knapsack
	Variant empty;
	knapsack_variants.push_back(std::move(empty));

	// take the best variant. First of all it is empty
	Variant* best_variant = &knapsack_variants.back();

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
				if (temp.sum_value > best_variant->sum_value) {
					*best_variant = temp;
				}

				// add to list new variant with current item
				knapsack_variants.push_back(std::move(temp));
			}
		}
	}

	return *best_variant;
}
