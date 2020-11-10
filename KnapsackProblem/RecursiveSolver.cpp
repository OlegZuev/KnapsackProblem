#include "RecursiveSolver.h"

RecursiveSolver::RecursiveSolver(int m)
{
    maxW = m;
}

void RecursiveSolver::Solver(std::vector<Item> items)
{
    if (items.size() > 0)
        CheckSet(items);
    for (int i = 0; i < items.size(); i++)
    {
        std::vector <Item> newSet(items);
        newSet.erase(newSet.begin() + i);
        Solver(newSet);
    }
}

void RecursiveSolver::CheckSet(std::vector<Item> items)
{
    if (result.empty())
    {
        if (CalcWeigth(items) <= maxW)
        {
            result = items;
            maxPrice = CalcPrice(items);
        }
    }
    else
    {
        if (CalcWeigth(items) <= maxW && CalcPrice(items) > maxPrice)
        {
            result = items;
            maxPrice = CalcPrice(items);
        }
    }
}

double RecursiveSolver::CalcPrice(std::vector<Item>items)
{
    double sumPr = 0;
    for (int i = 0; i < items.size(); i++)
        sumPr += items[i].value;
    return sumPr;
}

double RecursiveSolver::CalcWeigth(std::vector<Item> items)
{
    double sumW = 0;
    for(int i=0;i<items.size();i++)
        sumW += items[i].weight;
    return sumW;
    
}
