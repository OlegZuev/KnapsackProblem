#include "RecursiveSolver.h"

void RecursiveSolver::Solver(std::vector<Item> items, double M, int i, Variant curItems)
{
    if (curItems.sum_weight > M)
        return;
    if (curItems.sum_value >= result.sum_value)
        result = curItems;
    if (i == items.size()) 
        return;

    Solver(items, M, i + 1, curItems);
    curItems.items.push_back(items[i]);
    curItems.sum_weight += items[i].weight;
    curItems.sum_value += items[i].value;
    Solver(items, M, i + 1, curItems); 
}

Variant RecursiveSolver::solve(std::vector<Item> items, double M)
{
    Variant a;
    result = a;
    Solver(items, M, 0, Variant());
    return result;
}

std::string RecursiveSolver::get_name() 
{
    return "Recursive method";
}

