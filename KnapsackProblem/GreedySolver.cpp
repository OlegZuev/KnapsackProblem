#include "GreedySolver.h"
#include <algorithm>

Variant GreedySolver::solve(std::vector<Item> items, double M) {
	std::vector<Item> sorted_items = items;
	std::sort(sorted_items.begin(), sorted_items.end(), [](const Item x, const Item y) -> bool {
		return x.value / x.weight > y.value / y.weight;
	});

	Variant result{std::vector<Item>()};
	for (const Item& item : sorted_items) {
		if (result.sum_weight + item.weight <= M) {
			result.items.push_back(item);
			result.sum_weight += item.weight;
			result.sum_value += item.value;
		}
	}

	return result;
}

std::string GreedySolver::get_name() {
	return "Greedy method";
}
