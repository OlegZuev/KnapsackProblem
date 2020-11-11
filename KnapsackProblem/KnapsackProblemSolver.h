#pragma once
#include "Variant.h"

class KnapsackProblemSolver {
public:
	KnapsackProblemSolver(KnapsackProblemSolver&) = delete;
	KnapsackProblemSolver& operator=(const KnapsackProblemSolver&) = delete;
	KnapsackProblemSolver(KnapsackProblemSolver&&) = delete;
	KnapsackProblemSolver& operator=(const KnapsackProblemSolver&&) = delete;
	virtual ~KnapsackProblemSolver() = default;
	
	virtual Variant solver(std::vector<Item> items, double M) = 0;
	static void print_variant(const Variant& variant);

protected:
	KnapsackProblemSolver() = default;
};
