#include "KnapsackProblemGenerator.h"

KnapsackProblemGenerator::KnapsackProblemGenerator() : _max_weight(0), dist(nullptr), _multiplier(1.5) {}

KnapsackProblemGenerator::KnapsackProblemGenerator(int max_weight) : dist(nullptr), _multiplier(1.5) {
	set_max_weight(max_weight);
}

KnapsackProblemGenerator::~KnapsackProblemGenerator() {
	if (dist != nullptr) {
		delete dist;
	}
}

/*
* Gets random 1 <= int <= max_weight
*/
int KnapsackProblemGenerator::get_random_int() {
	return (*dist)(_random_device);
}

/*
* Gets vector<Item> of randrom items. Total weight >= max_weight
*/
std::vector<Item> KnapsackProblemGenerator::get_random_items() {
	std::vector<Item> items;

	int weight = 0;
	while (weight < _max_weight * _multiplier) {
		Item item;
		item.value = get_random_int();
		item.weight = get_random_int();
		items.push_back(item);
		weight += item.weight;
	}

	return items;
}

/*
* Sets max_weight of knapsack
*/
void KnapsackProblemGenerator::set_max_weight(int max_weight) {
	this->_max_weight = max_weight;

	if (dist != nullptr) {
		delete dist;
	}

	dist = new std::uniform_int_distribution<int>(1, _max_weight);
}

/*
* Sets the multiplier. The multiplier is used to stop generating items. 
* The sum of weight items must be smaller than
* the capacity of the backpack is multiplied by the multiplier
*/
void KnapsackProblemGenerator::set_weight_multiplier(double multiplier) {
	if (multiplier <= 0) return;

	this->_multiplier = multiplier;
}

/*
* Print knapsack problem
*/
void KnapsackProblemGenerator::print_knapsack_problem(std::vector<Item> items, int m, std::ostream& ostr) {
	ostr << m << std::endl;

	for (int i = 0; i < items.size(); i++) {
		ostr << items[i].weight << " ";
	}

	ostr << std::endl;

	for (int i = 0; i < items.size(); i++) {
		ostr << items[i].value << " ";
	}

	ostr << std::endl;
}
