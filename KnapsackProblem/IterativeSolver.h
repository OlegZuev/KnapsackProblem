#pragma once
#include "Item.h"
#include <vector>

class IterativeSolver
{
public:
	double best_weight;
	double best_value;
	std::vector <Item> result;
	IterativeSolver() = default;
	virtual ~IterativeSolver() = default;
	void Solver(std::vector <Item>, int);
};
