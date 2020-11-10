#include "IterativeSolver.h"


void IterativeSolver::Solver(std::vector <Item> items, int M)
{
	int n = items.size();
	for (int m = 1; m <= M; m++)
	{
		result[m].weight = result[m - 1].weight;
		result[m].value = result[m - 1].value;
		for (int i = 0; i < n; i++)
		{
			if (items[i].weight <= m)
			{
				result[i].weight=std:
			}
		}
	}
}
