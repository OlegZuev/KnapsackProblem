#pragma once
#include "KnapsackProblemSolver.h"
#include "Item.h"
#include<iostream>
#include<vector>

class RecursiveSolver : public KnapsackProblemSolver
{
public:
	Variant result;
	RecursiveSolver()=default;
	virtual ~RecursiveSolver() = default;
	void Solver(std::vector<Item> items, double M, int i, Variant curItems);
	Variant solve(std::vector<Item> items, double M) override;
	std::string get_name() override;
};
