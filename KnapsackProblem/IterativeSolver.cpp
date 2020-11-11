#include "IterativeSolver.h"
#include <stack>

// variant of backpack
struct Variant
{
	std::vector<Item> items;
	double weight = 0;
	double value = 0;
};

Variant get_copy_variant(Variant& variant)
{
	Variant new_var;
	new_var.value = variant.value;
	new_var.weight = variant.weight;
	for (int  i = 0; i < variant.items.size(); i++)
	{
		new_var.items.push_back(variant.items[i]);
	}
	return new_var;
}

void IterativeSolver::Solver(std::vector <Item> items, int m)
{
	std::vector<Variant> knapsack_variants;
	Variant empty;
	knapsack_variants.push_back(empty);

	// create all posible variants of the knapsack
	for (Item item : items)
	{
		int n = knapsack_variants.size();
		for (int i = 0; i < n; i++)
		{
			Variant temp = get_copy_variant(knapsack_variants[i]);			

			temp.items.push_back(item);
			temp.value += item.value;
			temp.weight += item.weight;

			knapsack_variants.push_back(temp);
		}
	}

	// take the best variant
	double best_value = 0;
	int best_variant_index = 0;
	double best_weight;
	for (int i = 0; i < knapsack_variants.size(); i++)
	{
		if (knapsack_variants[i].weight <= m && knapsack_variants[i].value > best_value)
		{
			best_weight = knapsack_variants[i].weight;
			best_value = knapsack_variants[i].value;
			best_variant_index = i;
		}
	}

	// fill result
	result.clear();
	this->best_weight = best_weight;
	this->best_value = best_value;
	for (int i = 0; i < knapsack_variants[best_variant_index].items.size(); i++)
	{
		this->result.push_back(knapsack_variants[best_variant_index].items[i]);
	}
}

