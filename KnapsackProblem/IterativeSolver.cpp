#include "IterativeSolver.h"
#include <stack>

// variant of backpack
struct Variant
{
	std::vector<Item> items;
	double weight = 0;
	double value = 0;
};

/*
* function, that get copy of struct variant
*/
Variant get_copy_variant(Variant& variant)
{
	Variant new_var;
	new_var.value = variant.value;
	new_var.weight = variant.weight;
	for (int i = 0; i < variant.items.size(); i++)
	{
		new_var.items.push_back(variant.items[i]);
	}
	return new_var;
}

/*
* Iterative solver
*/
void IterativeSolver::Solver(std::vector <Item> items, int m)
{
	std::vector<Variant> knapsack_variants;
	// empty knapsack
	Variant empty;
	knapsack_variants.push_back(empty);

	// take the best variant. First of all it is empty
	Variant* best_variant = &empty;

	// create all possible variants of the knapsack
	// Look every item
	for(Item item : items)
	{
		int n = knapsack_variants.size();
		// Look every possible variant
		for (int i = 0; i < n; i++)
		{
			Variant temp = get_copy_variant(knapsack_variants[i]);

			temp.items.push_back(item);
			temp.value += item.value;
			temp.weight += item.weight;

			// if variants fits in knapsack
			if (temp.weight <= m)
			{
				// if it the best variant. need remember it
				if (temp.value > best_variant->value)
				{
					*best_variant = temp;
				}

				// add to list new variant with current item
				knapsack_variants.push_back(temp);
			}
		}
	}

	// fill result
	result.clear();
	this->best_weight = best_variant->weight;
	this->best_value = best_variant->value;
	for (auto item : best_variant->items) {
		this->result.push_back(item);
	}
}

