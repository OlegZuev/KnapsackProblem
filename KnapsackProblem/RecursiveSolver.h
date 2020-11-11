#pragma once
#include "KnapsackProblemSolver.h"
#include "Item.h"
#include<iostream>
#include<vector>

class RecursiveSolver : public KnapsackProblemSolver
{
public:
	std::vector <Item> result;
	double maxW;
	double maxPrice;
	RecursiveSolver(int m);
	virtual ~RecursiveSolver() = default;
	void Solver(std::vector<Item>);
	void CheckSet(std::vector<Item>);
	double CalcPrice(std::vector<Item>);
	double CalcWeigth(std::vector<Item>);
	void PrintResult();
	Variant solve(std::vector<Item> items, double M) override;
};
