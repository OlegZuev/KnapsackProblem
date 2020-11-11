#pragma once
#include "Item.h"
#include <iostream>
#include <vector>
#include <random>

class KnapsackProblemGenerator {
public:
	int count_of_elements;
	KnapsackProblemGenerator();
	KnapsackProblemGenerator(int count_of_elements, double max_weight);
	std::vector<Item> get_random_items();
	int get_random_int();
	static void print_knapsack_problem(const std::vector<Item>& items, double m, std::ostream& ostr);
private:
	std::random_device _random_device;
	std::uniform_int_distribution<int> dist;
};
