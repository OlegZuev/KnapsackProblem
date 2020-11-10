﻿#pragma once
#include "Item.h"
#include <vector>

class IterativeSolver 
{
public:
	std::vector <Item> result;
	IterativeSolver()=default;
	virtual ~IterativeSolver() = default;
	void Solver(std::vector <Item>, int);
	
};
