#pragma once
#include "KnapsackProblemSolver.h"
#include "Item.h"
#include <vector>

class IterativeSolver : public KnapsackProblemSolver
{
public:
	double best_weight;
	double best_value;
	std::vector <Item> result;
	IterativeSolver() = default;
	virtual ~IterativeSolver() = default;
	void Solver(std::vector <Item>, int);
	Variant solve(std::vector<Item> items, double M) override;
};
