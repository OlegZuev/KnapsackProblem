#pragma once
#include "Item.h"
#include<vector>
class RecursiveSolver
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
};
