#pragma once
#include "KnapsackProblemSolver.h"
#include "Item.h"
#include <vector>

class IterativeSolver : public KnapsackProblemSolver
{
public:
	Variant solve(std::vector<Item> items, double M) override;
	std::string get_name() override;
};
