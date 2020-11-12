#include "KnapsackProblemGenerator.h"

#include <iomanip>

KnapsackProblemGenerator::KnapsackProblemGenerator() : count_of_elements(5) {
	this->max_weight = 10;
	dist = std::uniform_int_distribution<int>(1, static_cast<int>(10));
}

KnapsackProblemGenerator::KnapsackProblemGenerator(int count_of_elements, double max_weight)  {
	this->count_of_elements = count_of_elements;
	this->max_weight = max_weight;
	dist = std::uniform_int_distribution<int>(1, static_cast<int>(max_weight));
}

/*
* Gets random 1 <= int <= max_weight
*/
int KnapsackProblemGenerator::get_random_int() {
	return (dist)(_random_device);
}

/*
* Gets vector<Item> of random items. Total weight >= max_weight
*/
std::vector<Item> KnapsackProblemGenerator::get_random_items() {
	std::vector<Item> items;
	int count = 0;
	while (count < count_of_elements) {
		Item item{};
		item.value = get_random_int();
		item.weight = get_random_int();
		item.index = items.size() + 1;
		items.push_back(item);
		count++;
	}

	return items;
}

std::vector<Item> KnapsackProblemGenerator::get_bad_items() {
	std::vector<Item> items;
	items.reserve(count_of_elements);
	for (int i = 0; i < count_of_elements; i++)
	{
		items.push_back(Item{ 1, double(i + 1), i + 1 });
	}

	return items;
}

std::vector<Item> KnapsackProblemGenerator::get_avg_items(){
	std::vector<Item> items;
	items.reserve(count_of_elements);
	for (int i = 0; i < count_of_elements; i++)
	{
		items.push_back(Item{ 2 * max_weight / count_of_elements, double(i), i + 1 });
	}

	return items;
}

std::vector<Item> KnapsackProblemGenerator::get_good_items(){
	std::vector<Item> items;
	items.reserve(count_of_elements);
	for (int i = 0; i < count_of_elements; i++)
	{
		items.push_back(Item{ max_weight, double(i), i + 1 });
	}

	return items;
}


/*
* Print knapsack problem
*/
void KnapsackProblemGenerator::print_knapsack_problem(const std::vector<Item>& items, double m, std::ostream& ostr) {
	ostr << "N: " << items.size() << " M: " << m << std::endl;
	const int output_width = 3;
	const int precision = 0;
	ostr << std::endl << "Indexes: ";
	for (const Item& item : items) {
		ostr << std::fixed << std::setprecision(precision) << std::setw(output_width) << item.index << " ";
	}

	ostr << std::endl << "Weights: ";
	for (const Item& item : items) {
		ostr << std::fixed << std::setprecision(precision) << std::setw(output_width) << item.weight << " ";
	}

	ostr << std::endl << "Values:  ";
	for (const Item& item : items) {
		ostr << std::fixed << std::setprecision(precision) << std::setw(output_width) << item.value << " ";
	}

	ostr << std::endl;
}
