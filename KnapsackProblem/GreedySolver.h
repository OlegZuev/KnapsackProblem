#pragma once
#include <vector>
#include "Item.h"
#include "KnapsackProblemSolver.h"

class GreedySolver : public KnapsackProblemSolver {
public:
	Variant solve(std::vector<Item> items, double M) override;
	std::string get_name() override;
};
