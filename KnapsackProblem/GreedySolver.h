#pragma once
#include <vector>
#include "Item.h"
#include "KnapsackProblemSolver.h"

class GreedySolver : KnapsackProblemSolver {
public:

	Variant solver(std::vector<Item> items, double M) override;
};
