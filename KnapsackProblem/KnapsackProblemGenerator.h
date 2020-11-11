#pragma once
#include "Item.h"
#include <iostream>
#include <vector>
#include <random>

class KnapsackProblemGenerator
{
public:
	KnapsackProblemGenerator();
	KnapsackProblemGenerator(int max_weight);
	~KnapsackProblemGenerator();
	std::vector<Item> get_random_items();
	int get_random_int();
	void set_max_weight(int max_weight);
	void set_weight_multiplier(double multiplier);
	void print_knapsack_problem(std::vector<Item> items, int m, std::ostream& ostr);
private:
	int _max_weight;
	double _multiplier;
	std::random_device _random_device;
	std::uniform_int_distribution<int>* dist;
};
