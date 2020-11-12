#pragma once
#include <string>
#include "Variant.h"

class KnapsackProblemSolver {
public:
	KnapsackProblemSolver(KnapsackProblemSolver&) = delete;
	KnapsackProblemSolver& operator=(const KnapsackProblemSolver&) = delete;
	KnapsackProblemSolver(KnapsackProblemSolver&&) = delete;
	KnapsackProblemSolver& operator=(const KnapsackProblemSolver&&) = delete;
	virtual ~KnapsackProblemSolver() = default;

	/*
	 * Calculate solution of knapsack problem
	 * @param items - set of items with some value and weight
	 * @param M - max capacity of backpack
	 * @return some solution of knapsack problem 
	 */
	virtual Variant solve(std::vector<Item> items, double M) = 0;

	/*
	 * Returns method name of solution of knapsack problem
	 * @return name
	 */
	virtual std::string get_name() = 0;
	void print_variant(const Variant& variant, std::ostream& ostr);

protected:
	KnapsackProblemSolver() = default;
};
